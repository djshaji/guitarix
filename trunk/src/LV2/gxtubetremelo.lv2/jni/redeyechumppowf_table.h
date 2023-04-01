
// redeyechumppowf_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  3.000000
 // --table_div  4.771952
 // --table_op  0.100000

struct tableredeyechumppowf { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tableredeyechumppowf_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tableredeyechumppowf&() const { return *(tableredeyechumppowf*)this; }
};

 static tableredeyechumppowf_imp<200> redeyechumppowf_table __rt_data = {
	0,0.833333,6.63333,200, {
	0.000000000000,0.018331792286,0.036471929206,0.054418192007,0.072168378064,
	0.089720303052,0.107071803332,0.124220738536,0.141164994385,0.157902485736,
	0.174431159879,0.190749000116,0.206854029649,0.222744315870,0.238417975160,
	0.253873178490,0.269108158425,0.284121219304,0.298910757917,0.313475449475,
	0.327814174656,0.341925611498,0.355808296380,0.369460851115,0.382881988190,
	0.396070516051,0.409025344421,0.421745489610,0.434230079807,0.446478360310,
	0.458489698668,0.470263589699,0.481799660358,0.493097674402,0.504157536832,
	0.514979298065,0.525563157807,0.535909468573,0.546018738837,0.555891635768,
	0.565528987510,0.574931784988,0.584101183202,0.593038501977,0.601745226161,
	0.610223005237,0.618473652340,0.626499142663,0.634301611259,0.641883350215,
	0.649246805230,0.656394571582,0.663329389515,0.670054139056,0.676571834304,
	0.682885617190,0.688998750786,0.694914612159,0.700636684849,0.706168550989,
	0.711513883139,0.716676435871,0.721660037160,0.726468579638,0.731106011766,
	0.735576328969,0.739883564796,0.744031782150,0.748025064639,0.751867508090,
	0.755563212280,0.759116272905,0.762530773840,0.765810779719,0.768960328851,
	0.771983426510,0.774884038617,0.777666085813,0.780333437965,0.782889909080,
	0.785339252656,0.787685157456,0.789931243707,0.792081059722,0.794138078931,
	0.796105697310,0.797987231198,0.799785915495,0.801504902202,0.803147259315,
	0.804715970027,0.806213932245,0.807643958379,0.809008775400,0.810311025138,
	0.811553264808,0.812737967733,0.813867524263,0.814944242849,0.815970351278,
	0.816947998030,0.817879253761,0.818766112878,0.819610495209,0.820414247736,
	0.821179146393,0.821906897916,0.822599141723,0.823257451820,0.823883338732,
	0.824478251437,0.825043579304,0.825580654021,0.826090751515,0.826575093857,
	0.827034851134,0.827471143308,0.827885042033,0.828277572443,0.828649714905,
	0.829002406725,0.829336543826,0.829652982371,0.829952540349,0.830235999112,
	0.830504104874,0.830757570156,0.830997075186,0.831223269264,0.831436772064,
	0.831638174904,0.831828041968,0.832006911479,0.832175296837,0.832333687705,
	0.832482551062,0.832622332209,0.832753455737,0.832876326460,0.832991330304,
	0.833098835164,0.833199191723,0.833292734238,0.833379781296,0.833460636527,
	0.833535589302,0.833604915386,0.833668877573,0.833727726286,0.833781700154,
	0.833831026565,0.833875922190,0.833916593484,0.833953237169,0.833985997133,
	0.834015047121,0.834040584563,0.834062780718,0.834081795410,0.834097779424,
	0.834110875583,0.834121219437,0.834128939768,0.834134159017,0.834136993649,
	0.834137554482,0.834135946991,0.834132271583,0.834126623860,0.834119094857,
	0.834109771278,0.834098735705,0.834086066805,0.834071839524,0.834056125263,
	0.834038992060,0.834020504746,0.834000725105,0.833979712019,0.833957521612,
	0.833934207378,0.833909820312,0.833884409028,0.833858019873,0.833830697037,
	0.833802482656,0.833773416908,0.833743538110,0.833712882804,0.833681485841,
	0.833649380466,0.833616598387,0.833583169855,0.833549123728,0.833514487538,
	0.833479287557,0.833443548851,0.833407295340,0.833370549853,0.833333334177
	}
};

double always_inline redeyechumppowfclip(double x) {
    double f = fabs(x);
    f = f * redeyechumppowf_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = redeyechumppowf_table.data[0];
    } else if (i >= redeyechumppowf_table.size-1) {
        f = redeyechumppowf_table.data[redeyechumppowf_table.size-1];
    } else {
    f -= i;
    f = redeyechumppowf_table.data[i]*(1-f) + redeyechumppowf_table.data[i+1]*f;
    }
    return copysign(f, x);
}

