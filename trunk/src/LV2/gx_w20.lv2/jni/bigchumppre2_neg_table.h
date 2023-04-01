#ifndef _BIGCHUMPPRE2_NEG_H_
#define _BIGCHUMPPRE2_NEG_H_

// bigchumppre2_neg_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  -5.000000
 // --table_div  103.329115
 // --table_op  0.100000

struct tablebigchumppre2_neg { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablebigchumppre2_neg_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablebigchumppre2_neg&() const { return *(tablebigchumppre2_neg*)this; }
};

 static tablebigchumppre2_neg_imp<2048> bigchumppre2_neg_table __rt_data = {
	0,0.357489,40.94,2048, {
	0.000000000000,0.001388545238,0.002775222683,0.004160032833,0.005542976182,
	0.006924053227,0.008303264465,0.009680610392,0.011056091506,0.012429708302,
	0.013801461277,0.015171350929,0.016539377755,0.017905542251,0.019269844914,
	0.020632286242,0.021992866732,0.023351586881,0.024708447186,0.026063448144,
	0.027416590252,0.028767874008,0.030117299908,0.031464868449,0.032810580128,
	0.034154435442,0.035496434888,0.036836578963,0.038174868163,0.039511302984,
	0.040845883923,0.042178611477,0.043509486140,0.044838508410,0.046165678781,
	0.047490997751,0.048814465813,0.050136083464,0.051455851198,0.052773769511,
	0.054089838896,0.055404059849,0.056716432864,0.058026958434,0.059335637054,
	0.060642469216,0.061947455415,0.063250596143,0.064551891893,0.065851343157,
	0.067148950427,0.068444714195,0.069738634953,0.071030713192,0.072320949402,
	0.073609344075,0.074895897699,0.076180610765,0.077463483763,0.078744517181,
	0.080023711509,0.081301067233,0.082576584843,0.083850264826,0.085122107668,
	0.086392113857,0.087660283878,0.088926618217,0.090191117361,0.091453781793,
	0.092714611998,0.093973608460,0.095230771662,0.096486102088,0.097739600219,
	0.098991266539,0.100241101528,0.101489105668,0.102735279438,0.103979623319,
	0.105222137790,0.106462823331,0.107701680419,0.108938709532,0.110173911147,
	0.111407285742,0.112638833791,0.113868555771,0.115096452157,0.116322523422,
	0.117546770040,0.118769192485,0.119989791229,0.121208566744,0.122425519500,
	0.123640649969,0.124853958620,0.126065445923,0.127275112346,0.128482958358,
	0.129688984424,0.130893191013,0.132095578590,0.133296147620,0.134494898568,
	0.135691831898,0.136886948072,0.138080247554,0.139271730804,0.140461398285,
	0.141649250455,0.142835287775,0.144019510704,0.145201919699,0.146382515218,
	0.147561297717,0.148738267652,0.149913425478,0.151086771650,0.152258306620,
	0.153428030841,0.154595944766,0.155762048846,0.156926343529,0.158088829267,
	0.159249506508,0.160408375700,0.161565437289,0.162720691722,0.163874139444,
	0.165025780900,0.166175616533,0.167323646787,0.168469872103,0.169614292923,
	0.170756909687,0.171897722834,0.173036732803,0.174173940031,0.175309344956,
	0.176442948014,0.177574749639,0.178704750266,0.179832950328,0.180959350257,
	0.182083950485,0.183206751443,0.184327753560,0.185446957265,0.186564362986,
	0.187679971150,0.188793782183,0.189905796510,0.191016014556,0.192124436743,
	0.193231063494,0.194335895230,0.195438932372,0.196540175339,0.197639624550,
	0.198737280423,0.199833143373,0.200927213818,0.202019492170,0.203109978846,
	0.204198674256,0.205285578814,0.206370692929,0.207454017012,0.208535551472,
	0.209615296717,0.210693253153,0.211769421187,0.212843801224,0.213916393668,
	0.214987198921,0.216056217386,0.217123449464,0.218188895555,0.219252556058,
	0.220314431371,0.221374521891,0.222432828014,0.223489350136,0.224544088650,
	0.225597043949,0.226648216426,0.227697606471,0.228745214475,0.229791040826,
	0.230835085913,0.231877350122,0.232917833839,0.233956537450,0.234993461338,
	0.236028605887,0.237061971477,0.238093558491,0.239123367307,0.240151398305,
	0.241177651863,0.242202128357,0.243224828163,0.244245751656,0.245264899209,
	0.246282271196,0.247297867988,0.248311689955,0.249323737467,0.250334010894,
	0.251342510601,0.252349236957,0.253354190326,0.254357371074,0.255358779562,
	0.256358416155,0.257356281214,0.258352375098,0.259346698168,0.260339250782,
	0.261330033296,0.262319046069,0.263306289454,0.264291763806,0.265275469479,
	0.266257406826,0.267237576196,0.268215977941,0.269192612409,0.270167479950,
	0.271140580910,0.272111915636,0.273081484473,0.274049287765,0.275015325856,
	0.275979599088,0.276942107802,0.277902852339,0.278861833037,0.279819050236,
	0.280774504272,0.281728195482,0.282680124202,0.283630290766,0.284578695507,
	0.285525338758,0.286470220850,0.287413342114,0.288354702880,0.289294303476,
	0.290232144230,0.291168225468,0.292102547517,0.293035110702,0.293965915346,
	0.294894961772,0.295822250303,0.296747781259,0.297671554961,0.298593571728,
	0.299513831879,0.300432335731,0.301349083600,0.302264075802,0.303177312653,
	0.304088794465,0.304998521552,0.305906494227,0.306812712799,0.307717177581,
	0.308619888880,0.309520847006,0.310420052267,0.311317504969,0.312213205419,
	0.313107153922,0.313999350782,0.314889796303,0.315778490788,0.316665434538,
	0.317550627855,0.318434071039,0.319315764390,0.320195708206,0.321073902786,
	0.321950348426,0.322825045423,0.323697994073,0.324569194670,0.325438647509,
	0.326306352884,0.327172311086,0.328036522407,0.328898987140,0.329759705574,
	0.330618677999,0.331475904705,0.332331385979,0.333185122110,0.334037113384,
	0.334887360089,0.335735862509,0.336582620930,0.337427635636,0.338270906911,
	0.339112435038,0.339952220300,0.340790262979,0.341626563356,0.342461121711,
	0.343293938326,0.344125013480,0.344954347451,0.345781940519,0.346607792961,
	0.347431905055,0.348254277078,0.349074909306,0.349893802015,0.350710955480,
	0.351526369977,0.352340045780,0.353151983163,0.353962182399,0.354770643763,
	0.355577367526,0.356382353960,0.357185603339,0.357987115932,0.358786892012,
	0.359584931849,0.360381235714,0.361175803877,0.361968636607,0.362759734173,
	0.363549096846,0.364336724893,0.365122618584,0.365906778186,0.366689203968,
	0.367469896197,0.368248855141,0.369026081068,0.369801574243,0.370575334935,
	0.371347363410,0.372117659935,0.372886224775,0.373653058198,0.374418160469,
	0.375181531855,0.375943172621,0.376703083034,0.377461263359,0.378217713862,
	0.378972434808,0.379725426465,0.380476689096,0.381226222968,0.381974028347,
	0.382720105498,0.383464454688,0.384207076182,0.384947970246,0.385687137147,
	0.386424577150,0.387160290522,0.387894277530,0.388626538440,0.389357073520,
	0.390085883035,0.390812967254,0.391538326444,0.392261960874,0.392983870810,
	0.393704056522,0.394422518277,0.395139256346,0.395854270998,0.396567562502,
	0.397279131128,0.397988977147,0.398697100830,0.399403502448,0.400108182273,
	0.400811140578,0.401512377634,0.402211893716,0.402909689098,0.403605764053,
	0.404300118857,0.404992753785,0.405683669114,0.406372865120,0.407060342081,
	0.407746100275,0.408430139981,0.409112461478,0.409793065047,0.410471950969,
	0.411149119526,0.411824571000,0.412498305674,0.413170323835,0.413840625765,
	0.414509211752,0.415176082082,0.415841237044,0.416504676927,0.417166402019,
	0.417826412613,0.418484709000,0.419141291473,0.419796160326,0.420449315854,
	0.421100758354,0.421750488123,0.422398505459,0.423044810663,0.423689404035,
	0.424332285877,0.424973456494,0.425612916189,0.426250665269,0.426886704042,
	0.427521032816,0.428153651901,0.428784561610,0.429413762254,0.430041254150,
	0.430667037612,0.431291112958,0.431913480508,0.432534140582,0.433153093502,
	0.433770339593,0.434385879180,0.434999712590,0.435611840153,0.436222262198,
	0.436830979058,0.437437991069,0.438043298565,0.438646901885,0.439248801368,
	0.439848997357,0.440447490195,0.441044280228,0.441639367802,0.442232753269,
	0.442824436979,0.443414419287,0.444002700548,0.444589281121,0.445174161364,
	0.445757341642,0.446338822319,0.446918603761,0.447496686338,0.448073070421,
	0.448647756384,0.449220744604,0.449792035458,0.450361629329,0.450929526599,
	0.451495727655,0.452060232886,0.452623042682,0.453184157438,0.453743577550,
	0.454301303417,0.454857335441,0.455411674027,0.455964319581,0.456515272514,
	0.457064533239,0.457612102172,0.458157979731,0.458702166339,0.459244662419,
	0.459785468400,0.460324584712,0.460862011789,0.461397750067,0.461931799988,
	0.462464161993,0.462994836529,0.463523824046,0.464051124996,0.464576739837,
	0.465100669027,0.465622913029,0.466143472310,0.466662347339,0.467179538590,
	0.467695046540,0.468208871668,0.468721014459,0.469231475401,0.469740254985,
	0.470247353705,0.470752772060,0.471256510554,0.471758569691,0.472258949983,
	0.472757651944,0.473254676090,0.473750022946,0.474243693035,0.474735686889,
	0.475226005041,0.475714648029,0.476201616397,0.476686910690,0.477170531458,
	0.477652479259,0.478132754649,0.478611358194,0.479088290461,0.479563552022,
	0.480037143456,0.480509065342,0.480979318267,0.481447902822,0.481914819602,
	0.482380069206,0.482843652240,0.483305569311,0.483765821036,0.484224408031,
	0.484681330921,0.485136590335,0.485590186906,0.486042121272,0.486492394077,
	0.486941005970,0.487387957604,0.487833249638,0.488276882736,0.488718857567,
	0.489159174805,0.489597835131,0.490034839229,0.490470187789,0.490903881508,
	0.491335921087,0.491766307232,0.492195040656,0.492622122077,0.493047552219,
	0.493471331809,0.493893461584,0.494313942284,0.494732774655,0.495149959450,
	0.495565497426,0.495979389348,0.496391635985,0.496802238114,0.497211196516,
	0.497618511979,0.498024185298,0.498428217273,0.498830608710,0.499231360421,
	0.499630473227,0.500027947951,0.500423785427,0.500817986491,0.501210551988,
	0.501601482769,0.501990779692,0.502378443621,0.502764475426,0.503148875984,
	0.503531646180,0.503912786904,0.504292299054,0.504670183533,0.505046441253,
	0.505421073132,0.505794080095,0.506165463073,0.506535223006,0.506903360839,
	0.507269877526,0.507634774026,0.507998051306,0.508359710342,0.508719752115,
	0.509078177614,0.509434987836,0.509790183784,0.510143766469,0.510495736909,
	0.510846096132,0.511194845171,0.511541985066,0.511887516867,0.512231441630,
	0.512573760419,0.512914474305,0.513253584369,0.513591091698,0.513926997387,
	0.514261302539,0.514594008265,0.514925115684,0.515254625923,0.515582540117,
	0.515908859409,0.516233584950,0.516556717899,0.516878259424,0.517198210700,
	0.517516572912,0.517833347251,0.518148534918,0.518462137121,0.518774155079,
	0.519084590016,0.519393443167,0.519700715775,0.520006409090,0.520310524372,
	0.520613062890,0.520914025920,0.521213414749,0.521511230670,0.521807474987,
	0.522102149011,0.522395254063,0.522686791472,0.522976762578,0.523265168726,
	0.523552011274,0.523837291587,0.524121011037,0.524403171010,0.524683772896,
	0.524962818098,0.525240308026,0.525516244098,0.525790627745,0.526063460404,
	0.526334743522,0.526604478555,0.526872666970,0.527139310242,0.527404409854,
	0.527667967301,0.527929984086,0.528190461721,0.528449401730,0.528706805642,
	0.528962675000,0.529217011354,0.529469816264,0.529721091300,0.529970838041,
	0.530219058077,0.530465753005,0.530710924435,0.530954573984,0.531196703280,
	0.531437313961,0.531676407674,0.531913986076,0.532150050834,0.532384603624,
	0.532617646133,0.532849180057,0.533079207104,0.533307728988,0.533534747437,
	0.533760264185,0.533984280980,0.534206799577,0.534427821742,0.534647349252,
	0.534865383891,0.535081927457,0.535296981755,0.535510548601,0.535722629822,
	0.535933227254,0.536142342743,0.536349978146,0.536556135330,0.536760816171,
	0.536964022557,0.537165756384,0.537366019560,0.537564814002,0.537762141637,
	0.537958004405,0.538152404251,0.538345343136,0.538536823027,0.538726845902,
	0.538915413752,0.539102528574,0.539288192378,0.539472407184,0.539655175022,
	0.539836497931,0.540016377961,0.540194817174,0.540371817640,0.540547381439,
	0.540721510664,0.540894207416,0.541065473806,0.541235311956,0.541403723998,
	0.541570712076,0.541736278341,0.541900424956,0.542063154094,0.542224467939,
	0.542384368685,0.542542858534,0.542699939700,0.542855614409,0.543009884893,
	0.543162753397,0.543314222176,0.543464293494,0.543612969627,0.543760252858,
	0.543906145484,0.544050649809,0.544193768148,0.544335502827,0.544475856180,
	0.544614830554,0.544752428303,0.544888651793,0.545023503398,0.545156985506,
	0.545289100510,0.545419850815,0.545549238837,0.545677267001,0.545803937741,
	0.545929253502,0.546053216739,0.546175829915,0.546297095505,0.546417015992,
	0.546535593870,0.546652831642,0.546768731820,0.546883296928,0.546996529497,
	0.547108432068,0.547219007194,0.547328257434,0.547436185359,0.547542793548,
	0.547648084591,0.547752061085,0.547854725640,0.547956080872,0.548056129406,
	0.548154873880,0.548252316938,0.548348461234,0.548443309431,0.548536864202,
	0.548629128228,0.548720104199,0.548809794816,0.548898202785,0.548985330826,
	0.549071181663,0.549155758032,0.549239062677,0.549321098350,0.549401867813,
	0.549481373835,0.549559619194,0.549636606679,0.549712339084,0.549786819213,
	0.549860049880,0.549932033904,0.550002774115,0.550072273351,0.550140534456,
	0.550207560285,0.550273353700,0.550337917571,0.550401254776,0.550463368200,
	0.550524260738,0.550583935291,0.550642394769,0.550699642090,0.550755680178,
	0.550810511965,0.550864140393,0.550916568408,0.550967798966,0.551017835030,
	0.551066679569,0.551114335560,0.551160805989,0.551206093846,0.551250202130,
	0.551293133847,0.551334892010,0.551375479638,0.551414899757,0.551453155402,
	0.551490249611,0.551526185431,0.551560965916,0.551594594126,0.551627073125,
	0.551658405988,0.551688595793,0.551717645624,0.551745558574,0.551772337739,
	0.551797986224,0.551822507138,0.551845903595,0.551868178718,0.551889335633,
	0.551909377472,0.551928307376,0.551946128486,0.551962843952,0.551978456930,
	0.551992970579,0.552006388064,0.552018712557,0.552029947232,0.552040095270,
	0.552049159858,0.552057144185,0.552064051447,0.552069884844,0.552074647581,
	0.552078342867,0.552080973915,0.552082543945,0.552083056178,0.552082513842,
	0.552080920167,0.552078278390,0.552074591748,0.552069863485,0.552064096849,
	0.552057295090,0.552049461463,0.552040599226,0.552030711640,0.552019801972,
	0.552007873489,0.551994929464,0.551980973171,0.551966007890,0.551950036902,
	0.551933063491,0.551915090945,0.551896122553,0.551876161609,0.551855211409,
	0.551833275250,0.551810356433,0.551786458261,0.551761584041,0.551735737079,
	0.551708920685,0.551681138171,0.551652392852,0.551622688043,0.551592027063,
	0.551560413229,0.551527849865,0.551494340291,0.551459887834,0.551424495817,
	0.551388167570,0.551350906418,0.551312715693,0.551273598725,0.551233558845,
	0.551192599385,0.551150723680,0.551107935062,0.551064236868,0.551019632432,
	0.550974125089,0.550927718177,0.550880415032,0.550832218990,0.550783133390,
	0.550733161567,0.550682306859,0.550630572603,0.550577962136,0.550524478795,
	0.550470125916,0.550414906834,0.550358824886,0.550301883407,0.550244085730,
	0.550185435188,0.550125935116,0.550065588844,0.550004399703,0.549942371024,
	0.549879506134,0.549815808361,0.549751281032,0.549685927470,0.549619751000,
	0.549552754943,0.549484942619,0.549416317346,0.549346882442,0.549276641221,
	0.549205596996,0.549133753078,0.549061112776,0.548987679395,0.548913456242,
	0.548838446617,0.548762653821,0.548686081150,0.548608731899,0.548530609361,
	0.548451716824,0.548372057575,0.548291634898,0.548210452074,0.548128512381,
	0.548045819092,0.547962375480,0.547878184813,0.547793250356,0.547707575371,
	0.547621163116,0.547534016846,0.547446139811,0.547357535260,0.547268206437,
	0.547178156580,0.547087388927,0.546995906710,0.546903713157,0.546810811491,
	0.546717204934,0.546622896701,0.546527890003,0.546432188047,0.546335794037,
	0.546238711171,0.546140942642,0.546042491641,0.545943361350,0.545843554951,
	0.545743075618,0.545641926521,0.545540110826,0.545437631693,0.545334492277,
	0.545230695728,0.545126245191,0.545021143807,0.544915394709,0.544809001026,
	0.544701965882,0.544594292396,0.544485983680,0.544377042842,0.544267472982,
	0.544157277197,0.544046458577,0.543935020206,0.543822965162,0.543710296518,
	0.543597017341,0.543483130691,0.543368639622,0.543253547183,0.543137856416,
	0.543021570356,0.542904692034,0.542787224473,0.542669170690,0.542550533695,
	0.542431316493,0.542311522080,0.542191153447,0.542070213580,0.541948705455,
	0.541826632044,0.541703996311,0.541580801213,0.541457049701,0.541332744717,
	0.541207889200,0.541082486079,0.540956538275,0.540830048706,0.540703020280,
	0.540575455897,0.540447358452,0.540318730833,0.540189575918,0.540059896580,
	0.539929695685,0.539798976090,0.539667740645,0.539535992193,0.539403733569,
	0.539270967601,0.539137697110,0.539003924909,0.538869653801,0.538734886585,
	0.538599626050,0.538463874978,0.538327636143,0.538190912313,0.538053706245,
	0.537916020690,0.537777858391,0.537639222083,0.537500114493,0.537360538341,
	0.537220496337,0.537079991184,0.536939025578,0.536797602205,0.536655723744,
	0.536513392866,0.536370612234,0.536227384502,0.536083712317,0.535939598316,
	0.535795045129,0.535650055378,0.535504631676,0.535358776628,0.535212492831,
	0.535065782873,0.534918649335,0.534771094787,0.534623121793,0.534474732907,
	0.534325930677,0.534176717640,0.534027096325,0.533877069254,0.533726638939,
	0.533575807884,0.533424578585,0.533272953528,0.533120935192,0.532968526047,
	0.532815728554,0.532662545165,0.532508978326,0.532355030470,0.532200704026,
	0.532046001411,0.531890925036,0.531735477300,0.531579660596,0.531423477309,
	0.531266929812,0.531110020472,0.530952751648,0.530795125687,0.530637144930,
	0.530478811708,0.530320128345,0.530161097154,0.530001720441,0.529842000503,
	0.529681939627,0.529521540092,0.529360804170,0.529199734122,0.529038332200,
	0.528876600650,0.528714541706,0.528552157596,0.528389450537,0.528226422740,
	0.528063076404,0.527899413722,0.527735436876,0.527571148041,0.527406549382,
	0.527241643058,0.527076431215,0.526910915993,0.526745099523,0.526578983928,
	0.526412571320,0.526245863804,0.526078863476,0.525911572423,0.525743992725,
	0.525576126450,0.525407975660,0.525239542407,0.525070828736,0.524901836681,
	0.524732568269,0.524563025518,0.524393210437,0.524223125028,0.524052771281,
	0.523882151180,0.523711266700,0.523540119808,0.523368712461,0.523197046608,
	0.523025124189,0.522852947137,0.522680517375,0.522507836818,0.522334907373,
	0.522161730936,0.521988309398,0.521814644640,0.521640738535,0.521466592945,
	0.521292209727,0.521117590728,0.520942737786,0.520767652733,0.520592337389,
	0.520416793569,0.520241023079,0.520065027714,0.519888809263,0.519712369507,
	0.519535710218,0.519358833160,0.519181740087,0.519004432748,0.518826912881,
	0.518649182217,0.518471242478,0.518293095380,0.518114742628,0.517936185921,
	0.517757426948,0.517578467392,0.517399308926,0.517219953216,0.517040401920,
	0.516860656687,0.516680719160,0.516500590972,0.516320273748,0.516139769106,
	0.515959078657,0.515778204002,0.515597146735,0.515415908442,0.515234490702,
	0.515052895084,0.514871123153,0.514689176462,0.514507056559,0.514324764983,
	0.514142303265,0.513959672930,0.513776875494,0.513593912465,0.513410785344,
	0.513227495625,0.513044044792,0.512860434326,0.512676665695,0.512492740362,
	0.512308659785,0.512124425409,0.511940038677,0.511755501021,0.511570813866,
	0.511385978632,0.511200996729,0.511015869560,0.510830598522,0.510645185004,
	0.510459630388,0.510273936047,0.510088103349,0.509902133655,0.509716028316,
	0.509529788678,0.509343416080,0.509156911854,0.508970277323,0.508783513804,
	0.508596622609,0.508409605039,0.508222462391,0.508035195955,0.507847807012,
	0.507660296838,0.507472666700,0.507284917862,0.507097051577,0.506909069093,
	0.506720971651,0.506532760486,0.506344436825,0.506156001889,0.505967456891,
	0.505778803040,0.505590041537,0.505401173574,0.505212200341,0.505023123017,
	0.504833942777,0.504644660790,0.504455278216,0.504265796211,0.504076215923,
	0.503886538494,0.503696765059,0.503506896749,0.503316934685,0.503126879985,
	0.502936733759,0.502746497110,0.502556171137,0.502365756931,0.502175255578,
	0.501984668156,0.501793995739,0.501603239394,0.501412400181,0.501221479156,
	0.501030477366,0.500839395855,0.500648235659,0.500456997809,0.500265683330,
	0.500074293240,0.499882828553,0.499691290276,0.499499679409,0.499307996949,
	0.499116243885,0.498924421200,0.498732529873,0.498540570876,0.498348545176,
	0.498156453734,0.497964297506,0.497772077440,0.497579794481,0.497387449569,
	0.497195043635,0.497002577607,0.496810052407,0.496617468953,0.496424828155,
	0.496232130918,0.496039378143,0.495846570725,0.495653709554,0.495460795513,
	0.495267829482,0.495074812334,0.494881744939,0.494688628158,0.494495462850,
	0.494302249867,0.494108990059,0.493915684266,0.493722333327,0.493528938073,
	0.493335499333,0.493142017928,0.492948494676,0.492754930389,0.492561325873,
	0.492367681933,0.492173999365,0.491980278961,0.491786521510,0.491592727794,
	0.491398898592,0.491205034676,0.491011136816,0.490817205774,0.490623242310,
	0.490429247179,0.490235221129,0.490041164907,0.489847079252,0.489652964899,
	0.489458822581,0.489264653024,0.489070456950,0.488876235076,0.488681988116,
	0.488487716778,0.488293421767,0.488099103781,0.487904763516,0.487710401664,
	0.487516018911,0.487321615939,0.487127193426,0.486932752045,0.486738292467,
	0.486543815355,0.486349321372,0.486154811173,0.485960285412,0.485765744736,
	0.485571189790,0.485376621214,0.485182039644,0.484987445711,0.484792840044,
	0.484598223267,0.484403595999,0.484208958856,0.484014312450,0.483819657390,
	0.483624994278,0.483430323715,0.483235646297,0.483040962618,0.482846273264,
	0.482651578821,0.482456879870,0.482262176987,0.482067470747,0.481872761718,
	0.481678050467,0.481483337556,0.481288623543,0.481093908984,0.480899194428,
	0.480704480425,0.480509767517,0.480315056246,0.480120347147,0.479925640756,
	0.479730937600,0.479536238207,0.479341543099,0.479146852795,0.478952167812,
	0.478757488662,0.478562815854,0.478368149893,0.478173491282,0.477978840520,
	0.477784198103,0.477589564522,0.477394940267,0.477200325823,0.477005721673,
	0.476811128296,0.476616546169,0.476421975763,0.476227417549,0.476032871993,
	0.475838339558,0.475643820704,0.475449315889,0.475254825566,0.475060350187,
	0.474865890199,0.474671446047,0.474477018172,0.474282607014,0.474088213008,
	0.473893836587,0.473699478181,0.473505138217,0.473310817118,0.473116515306,
	0.472922233199,0.472727971212,0.472533729757,0.472339509245,0.472145310081,
	0.471951132671,0.471756977414,0.471562844711,0.471368734955,0.471174648540,
	0.470980585857,0.470786547292,0.470592533231,0.470398544056,0.470204580145,
	0.470010641877,0.469816729624,0.469622843759,0.469428984651,0.469235152665,
	0.469041348166,0.468847571515,0.468653823070,0.468460103189,0.468266412223,
	0.468072750526,0.467879118444,0.467685516326,0.467491944513,0.467298403348,
	0.467104893170,0.466911414315,0.466717967117,0.466524551909,0.466331169018,
	0.466137818773,0.465944501498,0.465751217516,0.465557967147,0.465364750707,
	0.465171568514,0.464978420880,0.464785308116,0.464592230531,0.464399188431,
	0.464206182121,0.464013211903,0.463820278077,0.463627380941,0.463434520789,
	0.463241697917,0.463048912614,0.462856165170,0.462663455873,0.462470785008,
	0.462278152856,0.462085559700,0.461893005818,0.461700491486,0.461508016981,
	0.461315582573,0.461123188534,0.460930835134,0.460738522637,0.460546251310,
	0.460354021416,0.460161833214,0.459969686964,0.459777582924,0.459585521347,
	0.459393502488,0.459201526598,0.459009593926,0.458817704720,0.458625859226,
	0.458434057688,0.458242300347,0.458050587444,0.457858919218,0.457667295906,
	0.457475717741,0.457284184958,0.457092697788,0.456901256460,0.456709861203,
	0.456518512242,0.456327209803,0.456135954107,0.455944745376,0.455753583830,
	0.455562469685,0.455371403159,0.455180384465,0.454989413817,0.454798491425,
	0.454607617499,0.454416792248,0.454226015876,0.454035288590,0.453844610591,
	0.453653982083,0.453463403264,0.453272874334,0.453082395488,0.452891966924,
	0.452701588834,0.452511261411,0.452320984845,0.452130759327,0.451940585044,
	0.451750462182,0.451560390927,0.451370371462,0.451180403969,0.450990488628,
	0.450800625620,0.450610815121,0.450421057309,0.450231352358,0.450041700441,
	0.449852101732,0.449662556400,0.449473064616,0.449283626547,0.449094242361,
	0.448904912222,0.448715636295,0.448526414743,0.448337247727,0.448148135407,
	0.447959077943,0.447770075492,0.447581128210,0.447392236252,0.447203399773,
	0.447014618924,0.446825893857,0.446637224723,0.446448611670,0.446260054845,
	0.446071554395,0.445883110466,0.445694723201,0.445506392743,0.445318119234,
	0.445129902814,0.444941743623,0.444753641798,0.444565597478,0.444377610797,
	0.444189681890,0.444001810892,0.443813997934,0.443626243148,0.443438546664,
	0.443250908611,0.443063329117,0.442875808310,0.442688346316,0.442500943258,
	0.442313599261,0.442126314448,0.441939088940,0.441751922858,0.441564816322,
	0.441377769449,0.441190782359,0.441003855166,0.440816987987,0.440630180937,
	0.440443434128,0.440256747674,0.440070121685,0.439883556273,0.439697051547,
	0.439510607616,0.439324224587,0.439137902567,0.438951641662,0.438765441978,
	0.438579303617,0.438393226682,0.438207211277,0.438021257502,0.437835365457,
	0.437649535242,0.437463766955,0.437278060694,0.437092416555,0.436906834635,
	0.436721315028,0.436535857828,0.436350463129,0.436165131024,0.435979861602,
	0.435794654957,0.435609511176,0.435424430349,0.435239412565,0.435054457911,
	0.434869566473,0.434684738337,0.434499973588,0.434315272310,0.434130634587,
	0.433946060501,0.433761550135,0.433577103568,0.433392720881,0.433208402154,
	0.433024147466,0.432839956894,0.432655830516,0.432471768408,0.432287770646,
	0.432103837305,0.431919968459,0.431736164181,0.431552424545,0.431368749623,
	0.431185139486,0.431001594204,0.430818113849,0.430634698488,0.430451348190,
	0.430268063025,0.430084843058,0.429901688356,0.429718598985,0.429535575011,
	0.429352616498,0.429169723509,0.428986896108,0.428804134358,0.428621438321,
	0.428438808057,0.428256243628,0.428073745093,0.427891312512,0.427708945944,
	0.427526645446,0.427344411077,0.427162242893,0.426980140951,0.426798105306,
	0.426616136013,0.426434233127,0.426252396702,0.426070626790,0.425888923446,
	0.425707286721,0.425525716666,0.425344213333,0.425162776772,0.424981407033,
	0.424800104165,0.424618868218,0.424437699238,0.424256597275,0.424075562375,
	0.423894594584,0.423713693949,0.423532860516,0.423352094329,0.423171395432,
	0.422990763871,0.422810199687,0.422629702924,0.422449273625,0.422268911831,
	0.422088617584,0.421908390924,0.421728231892,0.421548140528,0.421368116871,
	0.421188160961,0.421008272835,0.420828452531,0.420648700088,0.420469015541,
	0.420289398929,0.420109850285,0.419930369647,0.419750957049,0.419571612527,
	0.419392336113,0.419213127843,0.419033987748,0.418854915863,0.418675912220,
	0.418496976850,0.418318109786,0.418139311057,0.417960580696,0.417781918732,
	0.417603325196,0.417424800115,0.417246343521,0.417067955440,0.416889635902,
	0.416711384934,0.416533202564,0.416355088818,0.416177043723,0.415999067305,
	0.415821159590,0.415643320604,0.415465550370,0.415287848915,0.415110216262,
	0.414932652435,0.414755157457,0.414577731352,0.414400374142,0.414223085849,
	0.414045866497,0.413868716105,0.413691634695,0.413514622289,0.413337678907,
	0.413160804568,0.412983999293,0.412807263102,0.412630596013,0.412453998044,
	0.412277469216,0.412101009545,0.411924619049,0.411748297746,0.411572045653,
	0.411395862786,0.411219749163,0.411043704798,0.410867729709,0.410691823909,
	0.410515987415,0.410340220242,0.410164522403,0.409988893913,0.409813334785,
	0.409637845034,0.409462424673,0.409287073714,0.409111792171,0.408936580054,
	0.408761437378,0.408586364153,0.408411360391,0.408236426102,0.408061561299,
	0.407886765991,0.407712040189,0.407537383903,0.407362797142,0.407188279916,
	0.407013832235,0.406839454106,0.406665145540,0.406490906543,0.406316737125,
	0.406142637293,0.405968607055,0.405794646418,0.405620755388,0.405446933974,
	0.405273182181,0.405099500015,0.404925887483,0.404752344591,0.404578871343,
	0.404405467746,0.404232133804,0.404058869522,0.403885674905,0.403712549956,
	0.403539494680,0.403366509081,0.403193593162,0.403020746927,0.402847970379,
	0.402675263520,0.402502626354,0.402330058882,0.402157561107,0.401985133031,
	0.401812774655,0.401640485982,0.401468267012,0.401296117747,0.401124038187,
	0.400952028334,0.400780088187,0.400608217746,0.400436417013,0.400264685986,
	0.400093024665,0.399921433050,0.399749911139,0.399578458933,0.399407076429,
	0.399235763626,0.399064520523,0.398893347118,0.398722243409,0.398551209393,
	0.398380245069,0.398209350433,0.398038525483,0.397867770216,0.397697084629,
	0.397526468718,0.397355922481,0.397185445912,0.397015039010,0.396844701768,
	0.396674434184,0.396504236253,0.396334107969,0.396164049329,0.395994060328,
	0.395824140960,0.395654291220,0.395484511103,0.395314800603,0.395145159714,
	0.394975588431,0.394806086746,0.394636654655,0.394467292150,0.394297999225,
	0.394128775874,0.393959622088,0.393790537862,0.393621523188,0.393452578058,
	0.393283702465,0.393114896402,0.392946159860,0.392777492832,0.392608895309,
	0.392440367283,0.392271908745,0.392103519688,0.391935200102,0.391766949978,
	0.391598769308,0.391430658082,0.391262616291,0.391094643926,0.390926740977,
	0.390758907433,0.390591143287,0.390423448526,0.390255823142,0.390088267124,
	0.389920780462,0.389753363144,0.389586015162,0.389418736502,0.389251527156,
	0.389084387111,0.388917316357,0.388750314883,0.388583382676,0.388416519726,
	0.388249726020,0.388083001547,0.387916346295,0.387749760253,0.387583243407,
	0.387416795746,0.387250417257,0.387084107928,0.386917867746,0.386751696698,
	0.386585594772,0.386419561955,0.386253598233,0.386087703594,0.385921878024,
	0.385756121509,0.385590434037,0.385424815594,0.385259266166,0.385093785738,
	0.384928374298,0.384763031831,0.384597758324,0.384432553761,0.384267418128,
	0.384102351412,0.383937353597,0.383772424669,0.383607564613,0.383442773415,
	0.383278051059,0.383113397530,0.382948812814,0.382784296894,0.382619849757,
	0.382455471385,0.382291161765,0.382126920880,0.381962748714,0.381798645252,
	0.381634610478,0.381470644376,0.381306746931,0.381142918124,0.380979157942,
	0.380815466367,0.380651843382,0.380488288973,0.380324803121,0.380161385810,
	0.379998037024,0.379834756746,0.379671544958,0.379508401645,0.379345326788,
	0.379182320371,0.379019382377,0.378856512788,0.378693711587,0.378530978756,
	0.378368314278,0.378205718135,0.378043190311,0.377880730786,0.377718339543,
	0.377556016565,0.377393761832,0.377231575328,0.377069457035,0.376907406933,
	0.376745425005,0.376583511232,0.376421665596,0.376259888079,0.376098178662,
	0.375936537327,0.375774964054,0.375613458825,0.375452021622,0.375290652425,
	0.375129351215,0.374968117975,0.374806952683,0.374645855322,0.374484825872,
	0.374323864314,0.374162970629,0.374002144797,0.373841386799,0.373680696616,
	0.373520074227,0.373359519614,0.373199032756,0.373038613634,0.372878262228,
	0.372717978518,0.372557762485,0.372397614108,0.372237533368,0.372077520244,
	0.371917574716,0.371757696765,0.371597886369,0.371438143509,0.371278468164,
	0.371118860314,0.370959319939,0.370799847018,0.370640441530,0.370481103455,
	0.370321832772,0.370162629461,0.370003493501,0.369844424870,0.369685423549,
	0.369526489516,0.369367622751,0.369208823232,0.369050090938,0.368891425849,
	0.368732827943,0.368574297199,0.368415833596,0.368257437113,0.368099107727,
	0.367940845419,0.367782650167,0.367624521948,0.367466460742,0.367308466528,
	0.367150539282,0.366992678985,0.366834885615,0.366677159149,0.366519499566,
	0.366361906844,0.366204380962,0.366046921897,0.365889529628,0.365732204132,
	0.365574945389,0.365417753375,0.365260628069,0.365103569449,0.364946577493,
	0.364789652178,0.364632793482,0.364476001383,0.364319275859,0.364162616888,
	0.364006024446,0.363849498513,0.363693039065,0.363536646080,0.363380319536,
	0.363224059410,0.363067865679,0.362911738321,0.362755677314,0.362599682634,
	0.362443754259,0.362287892167,0.362132096335,0.361976366739,0.361820703358,
	0.361665106168,0.361509575147,0.361354110271,0.361198711517,0.361043378864,
	0.360888112287,0.360732911765,0.360577777273,0.360422708789,0.360267706289,
	0.360112769751,0.359957899152,0.359803094468,0.359648355676,0.359493682753,
	0.359339075676,0.359184534421,0.359030058965,0.358875649285,0.358721305358,
	0.358567027159,0.358412814666,0.358258667856,0.358104586705,0.357950571189,
	0.357796621285,0.357642736969,0.357488918218
	}
};

double always_inline bigchumppre2_negclip(double x) {
    double f = fabs(x);
    f = f * bigchumppre2_neg_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = bigchumppre2_neg_table.data[0];
    } else if (i >= bigchumppre2_neg_table.size-1) {
        f = bigchumppre2_neg_table.data[bigchumppre2_neg_table.size-1];
    } else {
    f -= i;
    f = bigchumppre2_neg_table.data[i]*(1-f) + bigchumppre2_neg_table.data[i+1]*f;
    }
    return copysign(f, x);
}

#endif //_BIGCHUMPPRE2_NEG_H_
