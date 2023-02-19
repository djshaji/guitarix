// generated from file '../src/faust/tonestack_groove.dsp' by dsp2cc:
// Code generated with Faust (https://faust.grame.fr)


namespace tonestack_groove {

class Dsp: public PluginDef {
private:
	int fSampleRate;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec0[4];
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fConst3;

	void clear_state_f();
	void init(unsigned int sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static void init_static(unsigned int sample_rate, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "Trio Preamp";
	name = N_("Trio Preamp Style");
	groups = 0;
	description = ""; // description (tooltip)
	category = "";       // category
	shortname = "";     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = 0;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; l0 < 4; l0 = l0 + 1) fRec0[l0] = 0.0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = 2.0 * std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
	fConst1 = mydsp_faustpower2_f(fConst0);
	fConst2 = mydsp_faustpower3_f(fConst0);
	fConst3 = 3.0 * fConst2;
	clear_state_f();
}

void Dsp::init_static(unsigned int sample_rate, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(sample_rate);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
	double fSlow0 = std::exp(3.4 * (double(fVslider0) + -1.0));
	double fSlow1 = double(fVslider1);
	double fSlow2 = 2.3926056000000006e-07 * fSlow1;
	double fSlow3 = fConst1 * (fSlow1 * (1.0875480000000001e-05 * fSlow0 + -4.347578400000001e-07 - fSlow2) + 3.659304000000001e-05 * fSlow0 + 1.1144196800000003e-06);
	double fSlow4 = 3.403100800000001e-09 * fSlow0;
	double fSlow5 = 1.4413132800000006e-09 * fSlow0 - 3.1708892160000014e-11 * fSlow1;
	double fSlow6 = fConst2 * (fSlow1 * (fSlow5 + -4.315932544000001e-11) + fSlow4 + 7.486821760000003e-11);
	double fSlow7 = 0.022470000000000004 * fSlow0;
	double fSlow8 = 0.00048400000000000006 * fSlow1;
	double fSlow9 = fConst0 * (fSlow8 + fSlow7 + 0.00358974);
	double fSlow10 = fSlow9 + fSlow6 + (-1.0 - fSlow3);
	double fSlow11 = fSlow9 + fSlow3;
	double fSlow12 = fSlow11 - 3.0 * (fSlow6 + 1.0);
	double fSlow13 = fSlow3 - (fSlow9 + 3.0 * (1.0 - fSlow6));
	double fSlow14 = 1.0 / (-1.0 - (fSlow11 + fSlow6));
	double fSlow15 = double(fVslider2);
	double fSlow16 = fConst1 * (3.0937280000000007e-07 * fSlow15 + fSlow1 * (2.893061600000001e-07 - fSlow2) + fSlow0 * (1.0875480000000001e-05 * fSlow1 + 3.6810400000000007e-06) + 8.098288000000002e-08);
	double fSlow17 = fSlow1 * (fSlow5 + 3.1708892160000014e-11) + fSlow15 * (fSlow4 + 7.486821760000003e-11 * (1.0 - fSlow1));
	double fSlow18 = fConst2 * fSlow17;
	double fSlow19 = fConst0 * (fSlow7 + fSlow8 + 0.0001034 * fSlow15 + 0.00049434);
	double fSlow20 = fSlow19 + fSlow18 - fSlow16;
	double fSlow21 = fConst3 * fSlow17;
	double fSlow22 = fSlow19 + fSlow16;
	double fSlow23 = fSlow22 - fSlow21;
	double fSlow24 = fSlow16 + fSlow21 - fSlow19;
	double fSlow25 = 0.0 - (fSlow22 + fSlow18);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec0[0] = double(input0[i0]) - fSlow14 * (fSlow13 * fRec0[1] + fSlow12 * fRec0[2] + fSlow10 * fRec0[3]);
		output0[i0] = FAUSTFLOAT(fSlow14 * (fSlow25 * fRec0[0] + fSlow24 * fRec0[1] + fSlow23 * fRec0[2] + fSlow20 * fRec0[3]));
		for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
			fRec0[j0] = fRec0[j0 - 1];
		}
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	fVslider0_ = reg.registerFloatVar("amp.tonestack.Bass","","SA","",&fVslider0, 0.5, 0.0, 1.0, 0.01, 0);
	fVslider1_ = reg.registerFloatVar("amp.tonestack.Middle","","SA","",&fVslider1, 0.5, 0.0, 1.0, 0.01, 0);
	fVslider2_ = reg.registerFloatVar("amp.tonestack.Treble","","SA","",&fVslider2, 0.5, 0.0, 1.0, 0.01, 0);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace tonestack_groove
