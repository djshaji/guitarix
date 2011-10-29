/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * ---------------------------------------------------------------------------
 *
 *    This is the gx_head system interface
 *
 * ----------------------------------------------------------------------------
 */

#include <dirent.h>
#include <iostream>
#include <iomanip>                  // NOLINT

#include "engine.h"

namespace gx_system {

/****************************************************************
 ** Measuring times (only when debugging)
 */

#ifndef NDEBUG

/* return time difference in ns, fail if > sec (doesn't fit int 32 bit int) */
int Measure::ts_diff(struct timespec ts1, struct timespec ts2) {
    time_t df = ts1.tv_sec - ts2.tv_sec;
    if (abs(df) > 2) {
        return -1; // failed
    }
    return df * 1000000000 + (ts1.tv_nsec - ts2.tv_nsec);
}

void Measure::print_accum(const Accum& accum, const char* prefix, bool verbose, int total) const {
    cout << prefix << "mean: " << fixed << setprecision(4) << ns2ms(accum.mean());
    if (total > 0) {
        cout << " (" << setprecision(2) << 100.0*accum.mean()/static_cast<float>(total) << "%)";
    }
    cout << ", min: " << setprecision(4) << ns2ms(accum.minimum())
         << ", max: " << ns2ms(accum.maximum());
    if (total > 0) {
        cout << " (" << setprecision(2) << 100.0*accum.maximum()/static_cast<float>(total) << "%)";
    }
    if (verbose) {
        cout << ", stddev: " << setprecision(4) << ns2ms(accum.stddev())
             << ", n: " << accum.count();
    }
    cout << endl;
}

void Measure::print(bool verbose) const {
    if (verbose) {
        print_accum(period,    "period     ", verbose);
	print_accum(duration1, "duration1  ", verbose, period.mean());
	print_accum(duration2, "duration2  ", verbose, period.mean());
	print_accum(duration,  "duration   ", verbose, period.mean());
    } else {
        print_accum(duration, "duration  ", false, period.mean());
    }
}

void MeasureThreadsafe::print(bool verbose) {
    Measure *p = pmeasure;
    Measure *pn;
    if (p == m) {
        pn = m+1;
    } else {
        pn = m;
    }
    g_atomic_pointer_set(&pmeasure, pn);
    p->print(verbose);
    p->reset();
}

MeasureThreadsafe measure;

static int print_measures(gpointer data) {
    bool verbose = GPOINTER_TO_INT(data);
    measure.print(verbose);
    return TRUE;
}

void add_time_measurement() {
    char *p = getenv("GUITARIX_MEASURE");
    if (!p) {
        return;
    }
    bool verbose = false;
    if (strcmp(p, "1") == 0) {
        verbose = true;
    }
    g_timeout_add(1000, print_measures, (gpointer)verbose);
}

#endif


/****************************************************************
 ** CmdlineOptions
 ** command line options
 */

void SkinHandling::set_styledir(const string& style_dir) {
    // fetch all skin names in directory
    DIR *d;
    d = opendir(style_dir.c_str());
    if (!d) {
        return;
    }
    // look for gx_head_*.rc and extract *-part
    struct dirent *de;
    skin_list.clear();
    while ((de = readdir(d)) != 0) {
        char *p = de->d_name;
        if (strncmp(p, "gx_head_", 8) != 0) {
            continue;
        }
        p += 8;
        int n = strlen(p) - 3;
        if (strcmp(p+n, ".rc") != 0) {
            continue;
        }
        skin_list.push_back(string(p, n));
    }
    closedir(d);
    sort(skin_list.begin(), skin_list.end());
}

bool SkinHandling::is_in_list(const string& name) {
    for (vector<string>::iterator i = skin_list.begin(); i != skin_list.end(); ++i) {
	if (*i == name) {
	    return true;
	}
    }
    return false;
}

bool PathList::contains(const string& d) const {
    Glib::RefPtr<Gio::File> f = Gio::File::create_for_path(d);
    for (pathlist::const_iterator i = dirs.begin();
	 i != dirs.end(); ++i) {
	if (f->equal(*i)) {
	    return true;
	}
    }
    return false;
}


bool PathList::find_dir(string* d, const string& filename) const {
    for (pathlist::const_iterator i = dirs.begin();
	 i != dirs.end(); ++i) {
	string p = (*i)->get_path();
	string fn = Glib::build_filename(p, filename);
	if (access(fn.c_str(), R_OK) == 0) {
	    *d = p;
	    return true;
	    }
	}
    return false;
}

CmdlineOptions *CmdlineOptions::instance = 0;

static inline const char *shellvar(const char *name) {
    const char *p = getenv(name);
    return p ? p : "";
}

#define TCLR(s)  "\033[1;32m" s "\033[0m" // light green
#define TCLR2(s) TCLR(s), s

CmdlineOptions::CmdlineOptions()
    : main_group("",""),
      optgroup_style("style", TCLR2("GTK style configuration options")),
      optgroup_jack("jack", TCLR2("JACK configuration options")),
      optgroup_file("file", TCLR2("File options")),
      optgroup_debug("debug", TCLR2("Debug options")),
      version(false), clear(false),
      jack_input(shellvar("GUITARIX2JACK_INPUTS")),
      jack_midi(shellvar("GUITARIX2JACK_MIDI")),
      jack_outputs(),
      jack_uuid(),
      jack_uuid2(),
      load_file(shellvar("GUITARIX_LOAD_FILE")),
      builder_dir(GX_BUILDER_DIR1),
      style_dir(GX_STYLE_DIR1),
      pixmap_dir(GX_PIXMAPS_DIR),
      user_dir(),
      plugin_dir(),
      sys_IR_dir(GX_SOUND_DIR1),
      IR_pathlist(),
      rcset(shellvar("GUITARIX_RC_STYLE")),
      lterminal(false),
      skin(style_dir) {
    const char* home = getenv("HOME");
    if (!home) {
	throw GxFatalError(_("no HOME environment variable"));
    }
    user_dir = string(home) + "/.gx_head/";
    plugin_dir = user_dir;
    const char *tmp = getenv("GUITARIX2JACK_OUTPUTS1");
    if (tmp && *tmp) {
	jack_outputs.push_back(tmp);
    }
    tmp = getenv("GUITARIX2JACK_OUTPUTS2");
    if (tmp && *tmp) {
	jack_outputs.push_back(tmp);
    }

    // ---- parse command line arguments
    set_summary(
        "All parameters are optional. Examples:\n"
        "\tguitarix\n"
        "\tguitarix -r gx4-black -i system:capture_3\n"
        "\tguitarix -c -o system:playback_1 -o system:playback_2");
    Glib::OptionEntry opt_version;
    opt_version.set_short_name('v');
    opt_version.set_long_name("version");
    opt_version.set_description("Print version string and exit");
    main_group.add_entry(opt_version, version);
    set_main_group(main_group);

    Glib::OptionEntry opt_clear;
    opt_clear.set_short_name('c');
    opt_clear.set_long_name("clear");
    opt_clear.set_description("Use 'default' GTK style");
    Glib::OptionEntry opt_rcset;
    opt_rcset.set_short_name('r');
    opt_rcset.set_long_name("rcset");
    opt_rcset.set_description(get_opskin());
    opt_rcset.set_arg_description("STYLE");
    optgroup_style.add_entry(opt_clear, clear);
    optgroup_style.add_entry(opt_rcset, rcset);

    // JACK options: input and output ports
    Glib::OptionEntry opt_jack_input;
    opt_jack_input.set_short_name('i');
    opt_jack_input.set_long_name("jack-input");
    opt_jack_input.set_description("Guitarix JACK input");
    opt_jack_input.set_arg_description("PORT");
    Glib::OptionEntry opt_jack_output;
    opt_jack_output.set_short_name('o');
    opt_jack_output.set_long_name("jack-output");
    opt_jack_output.set_description("Guitarix JACK outputs");
    opt_jack_output.set_arg_description("PORT");
    Glib::OptionEntry opt_jack_midi;
    opt_jack_midi.set_short_name('m');
    opt_jack_midi.set_long_name("jack-midi");
    opt_jack_midi.set_description("Guitarix JACK midi control");
    opt_jack_midi.set_arg_description("PORT");
    Glib::OptionEntry opt_jack_instance;
    opt_jack_instance.set_short_name('n');
    opt_jack_instance.set_long_name("name");
    opt_jack_instance.set_description("instance name (default gx_head)");
    opt_jack_instance.set_arg_description("NAME");
    Glib::OptionEntry opt_jack_uuid;
    opt_jack_uuid.set_short_name('U');
    opt_jack_uuid.set_long_name("jack-uuid");
    opt_jack_uuid.set_description("JackSession ID");
    Glib::OptionEntry opt_jack_uuid2;
    opt_jack_uuid2.set_short_name('A');
    opt_jack_uuid2.set_long_name("jack-uuid2");
    opt_jack_uuid2.set_description("JackSession ID");
    optgroup_jack.add_entry(opt_jack_input, jack_input);
    optgroup_jack.add_entry(opt_jack_output, jack_outputs);
    optgroup_jack.add_entry(opt_jack_midi, jack_midi);
    optgroup_jack.add_entry(opt_jack_instance, jack_instance);
    optgroup_jack.add_entry(opt_jack_uuid, jack_uuid);
    optgroup_jack.add_entry(opt_jack_uuid2, jack_uuid2);

    // FILE options

    Glib::OptionEntry opt_load_file;
    opt_load_file.set_short_name('f');
    opt_load_file.set_long_name("load-file");
    opt_load_file.set_description(_("load state file on startup"));
    opt_load_file.set_arg_description("FILE");
    optgroup_file.add_entry_filename(opt_load_file, load_file);
    Glib::OptionEntry opt_plugin_dir;
    opt_plugin_dir.set_short_name('P');
    opt_plugin_dir.set_long_name("plugin-dir");
    opt_plugin_dir.set_description(_("directory with guitarix plugins (.so files)"));
    opt_plugin_dir.set_arg_description("DIR");
    optgroup_file.add_entry_filename(opt_plugin_dir, plugin_dir);

    // DEBUG options
    Glib::OptionEntry opt_builder_dir;
    opt_builder_dir.set_short_name('B');
    opt_builder_dir.set_long_name("builder-dir");
    opt_builder_dir.set_description(_("directory from which .glade files are loaded"));
    opt_builder_dir.set_arg_description("DIR");
    optgroup_debug.add_entry_filename(opt_builder_dir, builder_dir);
    Glib::OptionEntry opt_style_dir;
    opt_style_dir.set_short_name('S');
    opt_style_dir.set_long_name("style-dir");
    opt_style_dir.set_description(_("directory with skin style definitions (.rc files)"));
    opt_style_dir.set_arg_description("DIR");
    optgroup_debug.add_entry_filename(opt_style_dir, style_dir);
    Glib::OptionEntry opt_log_terminal;
    opt_log_terminal.set_short_name('t');
    opt_log_terminal.set_long_name("log-terminal");
    opt_log_terminal.set_description(_("print log on terminal"));
    optgroup_debug.add_entry(opt_log_terminal, lterminal);

    // collecting all option groups
    add_group(optgroup_style);
    add_group(optgroup_jack);
    add_group(optgroup_file);
    add_group(optgroup_debug);

    instance = this;
}

CmdlineOptions::~CmdlineOptions() {
    instance = 0;
}

Glib::ustring CmdlineOptions::get_jack_output(unsigned int n) const {
    if (n >= jack_outputs.size()) {
	return "";
    }
    return jack_outputs.at(n);
}

string CmdlineOptions::get_opskin() {
    // initialize number of skins. We just count the number of rc files
    unsigned int n = skin.skin_list.size();
    if (n < 1) {
        gx_print_error(_("main"), string(_("number of skins is 0")));
	GxExit::get_instance().exit_program();
    }

    // GTK options: rc style (aka skin)
    string opskin("Style to use");

    vector<string>::iterator it;

    for (it = skin.skin_list.begin(); it != skin.skin_list.end(); ++it) {
        opskin += ", '" + *it + "'";
    }
    return opskin;
}

static void log_terminal(const string& msg, GxMsgType tp) {
    const char *t;
    switch (tp) {
    case kInfo:    t = "I"; break;
    case kWarning: t = "W"; break;
    case kError:   t = "E"; break;
    default:       t = "?"; break;
    }
    cerr << t << " " << msg << endl;
}

void CmdlineOptions::make_ending_slash(string& dirpath) {
    if (dirpath.empty()) {
	return;
    }
    if (dirpath[dirpath.size()-1] != '/') {
	dirpath += "/";
    }
}

void CmdlineOptions::process(int argc, char** argv) {
    path_to_program = Gio::File::create_for_path(argv[0])->get_path();
    if (version) {
        std::cout << "Guitarix version \033[1;32m"
             << GX_VERSION << endl
             << "\033[0m   Copyright " << static_cast<char>(0x40) << " 2010 "
             << "Hermman Meyer - James Warden - Andreas Degert"
             << endl;
        exit(0);
    }
    if (argc > 1) {
	throw gx_system::GxFatalError(
	    string("unknown argument on command line: ")+argv[1]);
    }
    if (clear && !rcset.empty()) {
	throw Glib::OptionError(
	    Glib::OptionError::BAD_VALUE,
	    _("-c and -r cannot be used together"));
    }
    if (lterminal) {
	Logger::get_logger().signal_message().connect(
	    sigc::ptr_fun(log_terminal));
    }

    make_ending_slash(builder_dir);
    make_ending_slash(style_dir);
    make_ending_slash(pixmap_dir);
    make_ending_slash(user_dir);
    make_ending_slash(plugin_dir);
    make_ending_slash(sys_IR_dir);

    IR_pathlist.add(get_user_dir());
    IR_pathlist.add(get_sys_IR_dir());

    skin.set_styledir(style_dir);
    if (!rcset.empty() && !skin.is_in_list(rcset)) {
	throw Glib::OptionError(
	    Glib::OptionError::BAD_VALUE,
	    (boost::format(_("invalid style '%1%' on command line"))
	     % rcset).str());
    }
    if (jack_outputs.size() >= 2) {
	gx_print_warning(
	    _("main"),
	    _("Warning --> provided more than 2 output ports, ignoring extra ports"));
    }
}


/****************************************************************
 ** Logging
 */

Logger::Logger()
    : trackable(),
      msglist(),
      msgmutex(),
      got_new_msg(),
      ui_thread(),
      handlers() {
}

Logger& Logger::get_logger() {
    static Logger instance;
    return instance;
}

Logger::~Logger() {
    delete got_new_msg;
}

void Logger::set_ui_thread() {
    if (ui_thread) {
	assert(pthread_equal(pthread_self(), ui_thread));
    } else {
	got_new_msg = new Glib::Dispatcher;
	ui_thread = pthread_self();
	got_new_msg->connect(mem_fun(*this, &Logger::write_queued));
    }
}

Logger::msg_signal& Logger::signal_message() {
    set_ui_thread();
    return handlers;
}

void Logger::write_queued() {
    if (handlers.empty()) {
	return;
    }

    // quick copy list
    msgmutex.lock();
    list<logmsg> l = msglist;
    msglist.clear();
    msgmutex.unlock();

    // feed throught the handler(s)
    for (list<logmsg>::iterator i = l.begin(); i != l.end(); ++i) {
	handlers(i->msg, i->msgtype);
    }
}

string Logger::format(const char* func, const string& msg) {
    // timestamp
    time_t now;
    time(&now);
    struct tm *tm_now = localtime(&now);
    ostringstream msgbuf;
    msgbuf << "[" << setfill('0')
           << setw(2) << tm_now->tm_hour << ":"
           << setw(2) << tm_now->tm_min  << ":"
           << setw(2) << tm_now->tm_sec  << "]"
           << "  " << func << "  ***  " << msg;
    return msgbuf.str();
}

void Logger::print(const char* func, const string& msg, GxMsgType msgtype) {
    string m = format(func, msg);
    if (handlers.empty() || !(pthread_equal(pthread_self(), ui_thread))) {
	boost::mutex::scoped_lock lock(msgmutex);
	// defer output
        msglist.push_back(logmsg(m, msgtype));
	if (!handlers.empty() && msglist.size() == 1) {
	    (*got_new_msg)();
	}
    } else {
	write_queued();
	handlers(m, msgtype);
    }
}

/*
** utility logger functions
*/

// ---- log message handler
void gx_print_logmsg(const char* func, const string& msg, GxMsgType msgtype) {
    Logger::get_logger().print(func, msg, msgtype);
}

// warning
void gx_print_warning(const char* func, const string& msg) {
    gx_print_logmsg(func, msg, kWarning);
}

// error
void gx_print_error(const char* func, const string& msg) {
    gx_print_logmsg(func, msg, kError);
}

GxFatalError::~GxFatalError() throw() {
}

// fatal error
// - do not use before Gtk::Main() ctor
// - do not use when main loop is blocked (modal dialog or something)
//
void gx_print_fatal(const char* func, const string& msg) {
    string msgbuf = string(_("fatal system error: ")) + func + "  ***  " + msg + "\n";
    GxExit::get_instance().fatal_msg(msgbuf);
}

// info
void gx_print_info(const char* func, const string& msg) {
    gx_print_logmsg(func, msg, kInfo);
}


/****************************************************************
 ** class GxExit
 */

GxExit::GxExit(): exit_sig(), ui_thread() {}

GxExit::~GxExit() {}

void GxExit::exit_program(string msg, int errcode) {
    exit_sig(pthread_equal(pthread_self(), ui_thread));
    if (msg.empty()) {
	msg = "** guitarix exit **";
    }
    cerr << msg << endl;
    _exit(errcode);
}

GxExit& GxExit::get_instance() {
    static GxExit instance;
    return instance;
}


/****************************************************************
 ** misc functions
 */

// ----start jack if possible
bool gx_start_jack() {
    // first, let's try via qjackctl
    if (gx_system::gx_system_call("which", "qjackctl", true) == SYSTEM_OK) {
        if (gx_system::gx_system_call("qjackctl", "--start", true, true) == SYSTEM_OK) {
            sleep(5);

            // let's check it is really running
            if (gx_system::gx_system_call("pgrep", "jackd", true) == SYSTEM_OK) {
                return true;
            }
        }
    }

    // qjackctl not found or not started, let's try .jackdrc
    string jackdrc = "$HOME/.jackdrc";
    if (gx_system::gx_system_call("ls", jackdrc.c_str(), true, false) == SYSTEM_OK) {
        // open it
        jackdrc = string(getenv("HOME")) + string("/") + ".jackdrc";
        string cmdline = "";

        ifstream f(jackdrc.c_str());
        if (f.good()) {
            // should contain only one command line
            getline(f, cmdline);
            f.close();
        }

        // launch jackd
        if (!cmdline.empty())
            if (gx_system::gx_system_call(cmdline.c_str(), "", true, true) == SYSTEM_OK) {

                sleep(2);

                // let's check it is really running
                if (gx_system::gx_system_call("pgrep", "jackd", true) == SYSTEM_OK) {
                    return true;
                }
            }
    }

    return false;
}

// ---- gx_head system function
int gx_system_call(const char* name1,
                   const char* name2,
                   const bool  devnull,
                   const bool  escape) {
    string str(name1);
    str.append(" ");
    str.append(name2);

    if (devnull)
        str.append(" 1>/dev/null 2>&1");

    if (escape)
        str.append("&");

    //    cerr << " ********* \n system command = " << str.c_str() << endl;

    sigset_t waitset;
    sigemptyset(&waitset);
    sigaddset(&waitset, SIGCHLD);
    sigprocmask(SIG_UNBLOCK, &waitset, NULL);
    int rc = system(str.c_str());
    sigprocmask(SIG_BLOCK, &waitset, NULL);
    return rc;
}

// polymorph1
int gx_system_call(const char*   name1,
                   const string& name2,
                   const bool  devnull,
                   const bool  escape) {
    return gx_system_call(name1, name2.c_str(), devnull, escape);
}

// polymorph3
int gx_system_call(const string& name1,
                   const char*   name2,
                   const bool  devnull,
                   const bool  escape) {
    return gx_system_call(name1.c_str(), name2, devnull, escape);
}

} /* end of gx_system namespace */
