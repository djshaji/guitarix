
// alembic_brite_neg_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  -0.500000
 // --table_div  2.624830
 // --table_op  0.250000

struct tablealembic_brite_neg { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablealembic_brite_neg_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablealembic_brite_neg&() const { return *(tablealembic_brite_neg*)this; }
};

 static tablealembic_brite_neg_imp<200> alembic_brite_neg_table __rt_data = {
	0,0.709061,99.5,200, {
	0.000000000000,0.016239521366,0.028340428309,0.037476970437,0.044487771980,
	0.049972504317,0.054360603207,0.057960130568,0.060992531450,0.063617369378,
	0.065949939533,0.068073818930,0.070049816213,0.071922360100,0.073724064780,
	0.075478996993,0.077205017838,0.078915464605,0.080620361406,0.082327292963,
	0.084042037256,0.085769025270,0.087511676487,0.089272644903,0.091054000406,
	0.092857363332,0.094684004955,0.096534923089,0.098410899435,0.100312543429,
	0.102240326081,0.104194606314,0.106175651655,0.108183654637,0.110218745905,
	0.112281004793,0.114370467901,0.116487136120,0.118630980420,0.120801946634,
	0.122999959452,0.125224925751,0.127476737403,0.129755273627,0.132060402989,
	0.134391985089,0.136749871993,0.139133909458,0.141543937963,0.143979793598,
	0.146441308821,0.148928313101,0.151440633468,0.153978094989,0.156540521167,
	0.159127734288,0.161739555716,0.164375806147,0.167036305820,0.169720874707,
	0.172429332670,0.175161499594,0.177917195503,0.180696240661,0.183498455652,
	0.186323661453,0.189171679499,0.192042331728,0.194935440630,0.197850829280,
	0.200788321374,0.203747741254,0.206728913927,0.209731665088,0.212755821132,
	0.215801209170,0.218867657037,0.221954993300,0.225063047268,0.228191648994,
	0.231340629281,0.234509819684,0.237699052513,0.240908160833,0.244136978466,
	0.247385339991,0.250653080742,0.253940036809,0.257246045036,0.260570943020,
	0.263914569108,0.267276762396,0.270657362728,0.274056210690,0.277473147613,
	0.280908015564,0.284360657348,0.287830916506,0.291318637308,0.294823664751,
	0.298345844560,0.301885023182,0.305441047782,0.309013766242,0.312603027158,
	0.316208679836,0.319830574289,0.323468561235,0.327122492093,0.330792218979,
	0.334477594706,0.338178472779,0.341894707391,0.345626153420,0.349372666430,
	0.353134102663,0.356910319039,0.360701173151,0.364506523263,0.368326228307,
	0.372160147882,0.376008142248,0.379870072321,0.383745799679,0.387635186549,
	0.391538095810,0.395454390988,0.399383936255,0.403326596422,0.407282236942,
	0.411250723903,0.415231924026,0.419225704661,0.423231933788,0.427250480012,
	0.431281212558,0.435324001271,0.439378716614,0.443445229662,0.447523412102,
	0.451613136230,0.455714274946,0.459826701755,0.463950290761,0.468084916665,
	0.472230454766,0.476386780952,0.480553771703,0.484731304085,0.488919255749,
	0.493117504929,0.497325930437,0.501544411661,0.505772828567,0.510011061689,
	0.514258992131,0.518516501566,0.522783472229,0.527059786918,0.531345328989,
	0.535639982356,0.539943631487,0.544256161402,0.548577457670,0.552907406408,
	0.557245894278,0.561592808482,0.565948036765,0.570311467407,0.574682989225,
	0.579062491568,0.583449864316,0.587844997877,0.592247783184,0.596658111696,
	0.601075875391,0.605500966766,0.609933278837,0.614372705133,0.618819139694,
	0.623272477074,0.627732612330,0.632199441028,0.636672859237,0.641152763526,
	0.645639050964,0.650131619116,0.654630366043,0.659135190298,0.663645990924,
	0.668162667453,0.672685119904,0.677213248778,0.681746955059,0.686286140213,
	0.690830706180,0.695380555379,0.699935590702,0.704495715512,0.709060833642
	}
};

double always_inline alembic_brite_negclip(double x) {
    double f = fabs(x);
    f = f * alembic_brite_neg_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = alembic_brite_neg_table.data[0];
    } else if (i >= alembic_brite_neg_table.size-1) {
        f = alembic_brite_neg_table.data[alembic_brite_neg_table.size-1];
    } else {
    f -= i;
    f = alembic_brite_neg_table.data[i]*(1-f) + alembic_brite_neg_table.data[i+1]*f;
    }
    return copysign(f, x);
}

