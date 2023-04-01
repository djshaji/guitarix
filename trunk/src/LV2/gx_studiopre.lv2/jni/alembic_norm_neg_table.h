
// alembic_norm_neg_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  -0.500000
 // --table_div  2.578949
 // --table_op  0.250000

struct tablealembic_norm_neg { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablealembic_norm_neg_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablealembic_norm_neg&() const { return *(tablealembic_norm_neg*)this; }
};

 static tablealembic_norm_neg_imp<200> alembic_norm_neg_table __rt_data = {
	0,0.710293,99.5,200, {
	0.000000000000,0.009458983398,0.017690162983,0.024879727704,0.031186387875,
	0.036745427321,0.041672157650,0.046064862957,0.050007310167,0.053570889135,
	0.056816437133,0.059795794308,0.062553129787,0.065126072271,0.067546673952,
	0.069842232346,0.072035990974,0.074147736786,0.076194309518,0.078190036005,
	0.080147100472,0.082075860282,0.083985115146,0.085882336674,0.087773864111,
	0.089665071231,0.091560508652,0.093464025183,0.095378871300,0.097307787382,
	0.099253078951,0.101216680830,0.103200211853,0.105205021523,0.107232229795,
	0.109282761001,0.111357372783,0.113456680763,0.115581179586,0.117731260856,
	0.119907228441,0.122109311521,0.124337675712,0.126592432557,0.128873647618,
	0.131181347375,0.133515525115,0.135876145945,0.138263151075,0.140676461468,
	0.143115980948,0.145581598857,0.148073192318,0.150590628160,0.153133764568,
	0.155702452485,0.158296536802,0.160915857384,0.163560249936,0.166229546744,
	0.168923577305,0.171642168865,0.174385146878,0.177152335397,0.179943557403,
	0.182758635090,0.185597390108,0.188459643762,0.191345217192,0.194253931518,
	0.197185607965,0.200140067972,0.203117133281,0.206116626015,0.209138368740,
	0.212182184522,0.215247896973,0.218335330291,0.221444309288,0.224574659423,
	0.227726206822,0.230898778295,0.234092201357,0.237306304234,0.240540915879,
	0.243795865977,0.247070984955,0.250366103982,0.253681054977,0.257015670612,
	0.260369784309,0.263743230247,0.267135843359,0.270547459334,0.273977914614,
	0.277427046394,0.280894692621,0.284380691992,0.287884883954,0.291407108697,
	0.294947207157,0.298505021011,0.302080392675,0.305673165301,0.309283182775,
	0.312910289712,0.316554331457,0.320215154080,0.323892604371,0.327586529840,
	0.331296778713,0.335023199930,0.338765643140,0.342523958698,0.346297997665,
	0.350087611801,0.353892653564,0.357712976108,0.361548433278,0.365398879607,
	0.369264170314,0.373144161301,0.377038709149,0.380947671117,0.384870905134,
	0.388808269804,0.392759624396,0.396724828843,0.400703743743,0.404696230349,
	0.408702150572,0.412721366975,0.416753742772,0.420799141823,0.424857428632,
	0.428928468346,0.433012126750,0.437108270263,0.441216765939,0.445337481460,
	0.449470285139,0.453615045908,0.457771633325,0.461939917566,0.466119769422,
	0.470311060298,0.474513662211,0.478727447784,0.482952290247,0.487188063431,
	0.491434641769,0.495691900290,0.499959714619,0.504237960970,0.508526516150,
	0.512825257551,0.517134063150,0.521452811505,0.525781381754,0.530119653610,
	0.534467507362,0.538824823869,0.543191484559,0.547567371428,0.551952367035,
	0.556346354499,0.560749217501,0.565160840276,0.569581107614,0.574009904857,
	0.578447117897,0.582892633171,0.587346337661,0.591808118892,0.596277864928,
	0.600755464371,0.605240806357,0.609733780555,0.614234277164,0.618742186913,
	0.623257401054,0.627779811364,0.632309310141,0.636845790200,0.641389144876,
	0.645939268016,0.650496053979,0.655059397635,0.659629194362,0.664205340041,
	0.668787731059,0.673376264303,0.677970837159,0.682571347509,0.687177693731,
	0.691789774695,0.696407489761,0.701030738778,0.705659422079,0.710293440484
	}
};

double always_inline alembic_norm_negclip(double x) {
    double f = fabs(x);
    f = f * alembic_norm_neg_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = alembic_norm_neg_table.data[0];
    } else if (i >= alembic_norm_neg_table.size-1) {
        f = alembic_norm_neg_table.data[alembic_norm_neg_table.size-1];
    } else {
    f -= i;
    f = alembic_norm_neg_table.data[i]*(1-f) + alembic_norm_neg_table.data[i+1]*f;
    }
    return copysign(f, x);
}

