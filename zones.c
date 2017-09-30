#include "utz.h"

const urule_packed_t zone_rules[50] = {
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AN	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AN	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AS	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AS	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AT	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  1, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AT	2001	max	-	Oct	Sun>=1	2:00s	1:00	D
{ 16,  22, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2016	2022	-	Feb	Sun>=15	0:00	0	-
{ 23,  23, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2023	only	-	Feb	Sun>=22	0:00	0	-
{ 24,  25, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2024	2025	-	Feb	Sun>=15	0:00	0	-
{ 26,  26, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2026	only	-	Feb	Sun>=22	0:00	0	-
{ 27,  33, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2027	2033	-	Feb	Sun>=15	0:00	0	-
{ 34,  34, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2034	only	-	Feb	Sun>=22	0:00	0	-
{ 35,  36, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2035	2036	-	Feb	Sun>=15	0:00	0	-
{ 37,  37, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2037	only	-	Feb	Sun>=22	0:00	0	-
{ 38, 255, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2038	max	-	Feb	Sun>=15	0:00	0	-
{  8, 255, 7, 15,  1,  0, 0, 1, 10, 1}, // 	Brazil	2008	max	-	Oct	Sun>=15	0:00	1:00	S
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Canada	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Canada	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 16, 255, 7,  9,  0,  3, 0, 0,  5, 0}, // 	Chile	2016	max	-	May	Sun>=9	3:00u	0	-
{ 16, 255, 7,  9,  0,  4, 0, 1,  8, 1}, // 	Chile	2016	max	-	Aug	Sun>=9	4:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EU	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EU	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 17,  19, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2017	2019	-	Mar	22	0:00	1:00	D
{ 20,  20, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2020	only	-	Mar	21	0:00	1:00	D
{ 21,  23, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2021	2023	-	Mar	22	0:00	1:00	D
{ 24,  24, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2024	only	-	Mar	21	0:00	1:00	D
{ 25,  27, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2025	2027	-	Mar	22	0:00	1:00	D
{ 28,  29, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2028	2029	-	Mar	21	0:00	1:00	D
{ 30,  31, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2030	2031	-	Mar	22	0:00	1:00	D
{ 32,  33, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2032	2033	-	Mar	21	0:00	1:00	D
{ 34,  35, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2034	2035	-	Mar	22	0:00	1:00	D
{ 36, 255, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2036	max	-	Mar	21	0:00	1:00	D
{ 17,  19, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2017	2019	-	Sep	22	0:00	0	S
{ 20,  20, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2020	only	-	Sep	21	0:00	0	S
{ 21,  23, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2021	2023	-	Sep	22	0:00	0	S
{ 24,  24, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2024	only	-	Sep	21	0:00	0	S
{ 25,  27, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2025	2027	-	Sep	22	0:00	0	S
{ 28,  29, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2028	2029	-	Sep	21	0:00	0	S
{ 30,  31, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2030	2031	-	Sep	22	0:00	0	S
{ 32,  33, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2032	2033	-	Sep	21	0:00	0	S
{ 34,  35, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2034	2035	-	Sep	22	0:00	0	S
{ 36, 255, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2036	max	-	Sep	21	0:00	0	S
{  2, 255, 7,  1,  1,  2, 0, 2,  4, 1}, // 	Mexico	2002	max	-	Apr	Sun>=1	2:00	1:00	D
{  2, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Mexico	2002	max	-	Oct	lastSun	2:00	0	S
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	NZ	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  7, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	NZ	2007	max	-	Sep	lastSun	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	US	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	US	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 13, 255, 5, 23,  1,  2, 0, 2,  3, 1}, // 	Zion	2013	max	-	Mar	Fri>=23	2:00	1:00	D
{ 13, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Zion	2013	max	-	Oct	lastSun	2:00	0	S
};

const char zone_abrevs[] = {
'E','E','S','T','\0',
'W','A','T','\0',
'C','A','T','\0',
'E','A','T','\0',
'A','K','%','s','T','\0',
'A','R','S','T','\0',
'C','%','s','T','\0',
'M','%','s','T','\0',
'A','%','s','T','\0',
'P','%','s','T','\0',
'A','M','T','\0',
'E','%','s','T','\0',
'M','S','T','\0',
'C','S','T','\0',
'C','L','%','s','T','\0',
'B','R','%','s','T','\0',
'N','%','s','T','\0',
'I','C','T','\0',
'G','S','T','\0',
'H','K','S','T','\0',
'I','%','s','T','\0',
'P','K','S','T','\0',
'N','P','T','\0',
'I','S','T','\0',
'A','S','T','\0',
'K','S','T','\0',
'I','R','%','s','T','\0',
'J','S','T','\0',
'M','M','T','\0',
'A','C','%','s','T','\0',
'A','E','S','T','\0',
'A','C','S','T','\0',
'A','E','%','s','T','\0',
'A','W','S','T','\0',
'C','E','%','s','T','\0',
'E','E','%','s','T','\0',
'+','0','3','\0',
'G','M','T','/','B','S','T','\0',
'M','S','K','\0',
'N','Z','%','s','T','\0',
'C','h','S','T','\0',
'H','S','T','\0',
'S','S','T','\0',
};

const uzone_packed_t zone_defns[46] = {
// Africa/Cairo	2:00	Egypt	EE%sT
{  8,   0,   0,   0},
// Africa/Lagos	1:00	-	WAT
{  4,   0,   0,   3},
// Africa/Maputo	2:00	-	CAT
{  8,   0,   0,   6},
// Africa/Nairobi	3:00	-	EAT
{ 12,   0,   0,   9},
// America/Anchorage	-9:00	US	AK%sT
{-36,  46,   2,  12},
// America/Argentina/Buenos_Aires	-3:00	Arg	AR%sT
{-12,   0,   0,  15},
// America/Chicago	-6:00	US	C%sT
{-24,  46,   2,  18},
// America/Denver	-7:00	US	M%sT
{-28,  46,   2,  21},
// America/Halifax	-4:00	Canada	A%sT
{-16,  16,   2,  24},
// America/Los_Angeles	-8:00	US	P%sT
// America/Tijuana	-8:00	US	P%sT
{-32,  46,   2,  27},
// America/Manaus	-4:00	-	AMT
{-16,   0,   0,  30},
// America/Mexico_City	-6:00	Mexico	C%sT
{-24,  42,   2,  18},
// America/New_York	-5:00	US	E%sT
{-20,  46,   2,  33},
// America/Phoenix	-7:00	-	MST
{-28,   0,   0,  36},
// America/Regina	-6:00	-	CST
{-24,   0,   0,  39},
// America/Santiago	-4:00	Chile	CL%sT
{-16,  18,   2,  42},
// America/Sao_Paulo	-3:00	Brazil	BR%sT
{-12,   6,  10,  45},
// America/St_Johns	-3:30	Canada	N%sT
{-10,  16,   2,  48},
// Asia/Bangkok	7:00	-	ICT
{ 28,   0,   0,  51},
// Asia/Dubai	4:00	-	GST
{ 16,   0,   0,  54},
// Asia/Hong_Kong	8:00	HK	HK%sT
{ 32,   0,   0,  57},
// Asia/Jerusalem	2:00	Zion	I%sT
{  8,  48,   2,  60},
// Asia/Karachi	5:00	Pakistan	PK%sT
{ 20,   0,   0,  63},
// Asia/Kathmandu	5:45	-	NPT
{ 23,   0,   0,  66},
// Asia/Kolkata	5:30	-	IST
{ 22,   0,   0,  69},
// Asia/Riyadh	3:00	-	AST
{ 12,   0,   0,  72},
// Asia/Seoul	9:00	ROK	K%sT
{ 36,   0,   0,  75},
// Asia/Shanghai	8:00	PRC	C%sT
// Asia/Taipei	8:00	Taiwan	C%sT
{ 32,   0,   0,  39},
// Asia/Tehran	3:30	Iran	IR%sT
{ 14,  22,  20,  78},
// Asia/Tokyo	9:00	Japan	J%sT
{ 36,   0,   0,  81},
// Asia/Yangon	6:30	-	MMT
{ 26,   0,   0,  84},
// Australia/Adelaide	9:30	AS	AC%sT
{ 38,   2,   2,  87},
// Australia/Brisbane	10:00	AQ	AE%sT
{ 40,   0,   0,  90},
// Australia/Darwin	9:30	Aus	AC%sT
{ 38,   0,   0,  93},
// Australia/Hobart	10:00	AT	AE%sT
{ 40,   4,   2,  96},
// Australia/Perth	8:00	AW	AW%sT
{ 32,   0,   0,  99},
// Australia/Sydney	10:00	AN	AE%sT
{ 40,   0,   2,  96},
// Europe/Belgrade	1:00	EU	CE%sT
// Europe/Berlin	1:00	EU	CE%sT
// Europe/Madrid	1:00	EU	CE%sT
// Europe/Rome	1:00	EU	CE%sT
{  4,  20,   2, 102},
// Europe/Helsinki	2:00	EU	EE%sT
{  8,  20,   2, 105},
// Europe/Istanbul	3:00	-	+03
{ 12,   0,   0, 108},
// Europe/London	0:00	EU	GMT/BST
{  0,  20,   2, 111},
// Europe/Moscow	3:00	-	MSK
{ 12,   0,   0, 114},
// Pacific/Auckland	12:00	NZ	NZ%sT
{ 48,  44,   2, 117},
// Pacific/Guam	10:00	-	ChST
{ 40,   0,   0, 120},
// Pacific/Honolulu	-10:00	-	HST
{-40,   0,   0, 123},
// Pacific/Pago_Pago	-11:00	-	SST
{-44,   0,   0, 126},
};

const unsigned char zone_names[961] = {
                                            'A','d','e','l','a','i','d','e','\0',  31, // Adelaide
                                        'A','h','m','e','d','a','b','a','d','\0',  24, // Ahmedabad
                                        'A','n','c','h','o','r','a','g','e','\0',   4, // Anchorage
                                                    'A','n','k','a','r','a','\0',  39, // Ankara
                                                'A','t','l','a','n','t','a','\0',  12, // Atlanta
                                            'A','u','c','k','l','a','n','d','\0',  42, // Auckland
                                        'B','a','n','g','a','l','o','r','e','\0',  24, // Bangalore
                                                'B','a','n','g','k','o','k','\0',  18, // Bangkok
                                        'B','a','r','c','e','l','o','n','a','\0',  37, // Barcelona
                                                'B','e','i','j','i','n','g','\0',  27, // Beijing
                                            'B','e','l','g','r','a','d','e','\0',  37, // Belgrade
                    'B','e','l','o',' ','H','o','r','i','z','o','n','t','e','\0',  16, // Belo Horizonte
                                                    'B','e','r','l','i','n','\0',  37, // Berlin
                                                    'B','o','s','t','o','n','\0',  12, // Boston
                                'B','r','a','z','z','a','v','i','l','l','e','\0',   1, // Brazzaville
                                            'B','r','i','s','b','a','n','e','\0',  32, // Brisbane
                            'B','u','e','n','o','s',' ','A','i','r','e','s','\0',   5, // Buenos Aires
                                                        'C','a','i','r','o','\0',   0, // Cairo
                                            'C','a','l','c','u','t','t','a','\0',  24, // Calcutta
                                        'C','h','a','n','g','z','h','o','u','\0',  27, // Changzhou
                                                'C','h','e','n','g','d','u','\0',  27, // Chengdu
                                                'C','h','e','n','n','a','i','\0',  24, // Chennai
                                                'C','h','i','c','a','g','o','\0',   6, // Chicago
                                        'C','h','o','n','g','q','i','n','g','\0',  27, // Chongqing
            'D','a','l','l','a','s','F','o','r','t',' ','W','o','r','t','h','\0',   6, // DallasFort Worth
                                                    'D','a','r','w','i','n','\0',  33, // Darwin
                                                        'D','e','l','h','i','\0',  24, // Delhi
                                                    'D','e','n','v','e','r','\0',   7, // Denver
                                                        'D','u','b','a','i','\0',  19, // Dubai
                                'G','u','a','d','a','l','a','j','a','r','a','\0',  11, // Guadalajara
                                                            'G','u','a','m','\0',  43, // Guam
                                        'G','u','a','n','g','z','h','o','u','\0',  27, // Guangzhou
                                                'H','a','l','i','f','a','x','\0',   8, // Halifax
                                                'H','a','m','b','u','r','g','\0',  37, // Hamburg
                                            'H','a','n','g','z','h','o','u','\0',  27, // Hangzhou
                                                    'H','a','r','a','r','e','\0',   2, // Harare
                                            'H','e','l','s','i','n','k','i','\0',  38, // Helsinki
                                                    'H','o','b','a','r','t','\0',  34, // Hobart
                                        'H','o','n','g',' ','K','o','n','g','\0',  20, // Hong Kong
                                            'H','o','n','o','l','u','l','u','\0',  44, // Honolulu
                                                'H','o','u','s','t','o','n','\0',   6, // Houston
                                        'H','y','d','e','r','a','b','a','d','\0',  24, // Hyderabad
                        'I','n','l','a','n','d',' ','E','m','p','i','r','e','\0',   9, // Inland Empire
                                            'I','s','t','a','n','b','u','l','\0',  39, // Istanbul
                                        'J','e','r','u','s','a','l','e','m','\0',  21, // Jerusalem
                                                        'J','i','n','a','n','\0',  27, // Jinan
                                                'K','a','r','a','c','h','i','\0',  22, // Karachi
                                            'K','a','t','m','a','n','d','u','\0',  23, // Katmandu
                                                'K','o','l','k','a','t','a','\0',  24, // Kolkata
                                                    'K','u','w','a','i','t','\0',  25, // Kuwait
                                                    'L','a','h','o','r','e','\0',  22, // Lahore
                                                    'L','o','n','d','o','n','\0',  40, // London
                                'L','o','s',' ','A','n','g','e','l','e','s','\0',   9, // Los Angeles
                                                    'M','a','d','r','i','d','\0',  37, // Madrid
                                                    'M','a','n','a','u','s','\0',  10, // Manaus
                                'M','e','x','i','c','o',' ','C','i','t','y','\0',  11, // Mexico City
                                                        'M','i','a','m','i','\0',  12, // Miami
                                                    'M','i','d','w','a','y','\0',  45, // Midway
                                                        'M','i','l','a','n','\0',  37, // Milan
                                                    'M','o','s','c','o','w','\0',  41, // Moscow
                                                    'M','u','m','b','a','i','\0',  24, // Mumbai
                                                    'M','u','n','i','c','h','\0',  37, // Munich
                                                    'N','a','g','o','y','a','\0',  29, // Nagoya
                                                'N','a','i','r','o','b','i','\0',   3, // Nairobi
                                            'N','a','n','c','h','a','n','g','\0',  27, // Nanchang
                                                'N','a','n','j','i','n','g','\0',  27, // Nanjing
                                            'N','e','w',' ','Y','o','r','k','\0',  12, // New York
                                                        'O','s','a','k','a','\0',  29, // Osaka
                                                        'P','e','r','t','h','\0',  35, // Perth
                            'P','h','i','l','a','d','e','l','p','h','i','a','\0',  12, // Philadelphia
                                                'P','h','o','e','n','i','x','\0',  13, // Phoenix
                                                            'P','u','n','e','\0',  24, // Pune
                                                'Q','i','n','g','d','a','o','\0',  27, // Qingdao
                                                'R','a','n','g','o','o','n','\0',  30, // Rangoon
                                                    'R','e','g','i','n','a','\0',  14, // Regina
                                    'R','h','i','n','e','-','R','u','h','r','\0',  37, // Rhine-Ruhr
                    'R','i','o',' ','d','e',' ','J','a','n','e','i','r','o','\0',  16, // Rio de Janeiro
                                                            'R','o','m','e','\0',  37, // Rome
                        'S','a','n',' ','F','r','a','n','c','i','s','c','o','\0',   9, // San Francisco
                                            'S','a','n','t','i','a','g','o','\0',  15, // Santiago
                                        'S','a','o',' ','P','a','u','l','o','\0',  16, // Sao Paulo
                                            'S','a','r','a','j','e','v','o','\0',  37, // Sarajevo
                                                        'S','e','o','u','l','\0',  26, // Seoul
                                            'S','h','a','n','g','h','a','i','\0',  27, // Shanghai
                                            'S','h','e','n','y','a','n','g','\0',  27, // Shenyang
                                            'S','h','e','n','z','h','e','n','\0',  27, // Shenzhen
                                            'S','t',' ','J','o','h','n','s','\0',  17, // St Johns
                                        'S','t','u','t','t','g','a','r','t','\0',  37, // Stuttgart
                                                        'S','u','r','a','t','\0',  24, // Surat
                                                    'S','y','d','n','e','y','\0',  36, // Sydney
                                                    'T','a','i','p','e','i','\0',  27, // Taipei
                                                    'T','e','h','r','a','n','\0',  28, // Tehran
                                                'T','i','a','n','j','i','n','\0',  27, // Tianjin
                                                'T','i','j','u','a','n','a','\0',   9, // Tijuana
                                                        'T','o','k','y','o','\0',  29, // Tokyo
            'W','a','s','h','i','n','g','t','o','n',',',' ','D','.','C','.','\0',  12, // Washington, D.C.
                                                'W','e','n','z','h','o','u','\0',  27, // Wenzhou
                                                        'W','u','h','a','n','\0',  27, // Wuhan
                                                       'X','i','\'','a','n','\0',  27, // Xi'an
                                        'Z','h','e','n','g','z','h','o','u','\0',  27, // Zhengzhou
};
