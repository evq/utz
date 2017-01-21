#ifndef _UTZ_ZONES_H
#define _UTZ_ZONES_H

urule_t rules[96] = {
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AN	2008	max	-	Apr	Sun>=1	2:00s	0	S
{ 38, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AN	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AS	2008	max	-	Apr	Sun>=1	2:00s	0	S
{ 38, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AS	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{ 31, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AT	2001	max	-	Oct	Sun>=1	2:00s	1:00	D
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AT	2008	max	-	Apr	Sun>=1	2:00s	0	S
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AV	2008	max	-	Apr	Sun>=1	2:00s	0	S
{ 38, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AV	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{ 38, 255, 7, 15,  1,  0, 0, 1, 10, 1}, // 	Brazil	2008	max	-	Oct	Sun>=15	0:00	1:00	S
{ 46,  52, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2016	2022	-	Feb	Sun>=15	0:00	0	-
{ 53,  53, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2023	only	-	Feb	Sun>=22	0:00	0	-
{ 54,  55, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2024	2025	-	Feb	Sun>=15	0:00	0	-
{ 56,  56, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2026	only	-	Feb	Sun>=22	0:00	0	-
{ 57,  63, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2027	2033	-	Feb	Sun>=15	0:00	0	-
{ 64,  64, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2034	only	-	Feb	Sun>=22	0:00	0	-
{ 67,  67, 6, 21,  1, 23, 0, 0,  2, 0}, // 	Brazil	2037	only	-	Feb	Sun>=22	0:00	0	-
{ 68, 255, 6, 14,  1, 23, 0, 0,  2, 0}, // 	Brazil	2038	max	-	Feb	Sun>=15	0:00	0	-
{ 11, 255, 7,  0,  1,  2, 0, 1,  3, 1}, // 	C-Eur	1981	max	-	Mar	lastSun	 2:00s	1:00	S
{ 26, 255, 7,  0,  1,  2, 0, 0, 10, 0}, // 	C-Eur	1996	max	-	Oct	lastSun	 2:00s	0	-
{ 37, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Canada	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{ 37, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Canada	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 37, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	Chatham	2007	max	-	Sep	lastSun	2:45s	1:00	D
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	Chatham	2008	max	-	Apr	Sun>=1	2:45s	0	S
{ 46, 255, 7,  9,  0,  3, 0, 0,  5, 0}, // 	Chile	2016	max	-	May	Sun>=9	3:00u	0	-
{ 46, 255, 7,  9,  0,  4, 0, 1,  8, 1}, // 	Chile	2016	max	-	Aug	Sun>=9	4:00u	1:00	S
{ 42, 255, 7,  1,  1,  0, 0, 1, 11, 0}, // 	Cuba	2012	max	-	Nov	Sun>=1	0:00s	0	S
{ 43, 255, 7,  8,  1,  0, 0, 2,  3, 1}, // 	Cuba	2013	max	-	Mar	Sun>=8	0:00s	1:00	D
{ 11, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EU	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{ 26, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EU	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 11, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EUAsia	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{ 26, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EUAsia	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 44, 255, 7,  1,  1,  2, 0, 1, 11, 1}, // 	Fiji	2014	max	-	Nov	Sun>=1	2:00	1:00	S
{ 45, 255, 7, 15,  1,  2, 0, 0,  1, 0}, // 	Fiji	2015	max	-	Jan	Sun>=15	3:00	0	-
{ 47,  49, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2017	2019	-	Mar	22	0:00	1:00	D
{ 47,  49, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2017	2019	-	Sep	22	0:00	0	S
{ 50,  50, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2020	only	-	Mar	21	0:00	1:00	D
{ 50,  50, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2020	only	-	Sep	21	0:00	0	S
{ 51,  53, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2021	2023	-	Mar	22	0:00	1:00	D
{ 51,  53, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2021	2023	-	Sep	22	0:00	0	S
{ 54,  54, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2024	only	-	Mar	21	0:00	1:00	D
{ 54,  54, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2024	only	-	Sep	21	0:00	0	S
{ 55,  57, 0, 22,  1,  0, 0, 2,  3, 1}, // 	Iran	2025	2027	-	Mar	22	0:00	1:00	D
{ 55,  57, 0, 21,  1, 23, 0, 1,  9, 0}, // 	Iran	2025	2027	-	Sep	22	0:00	0	S
{ 66, 255, 0, 21,  1,  0, 0, 2,  3, 1}, // 	Iran	2036	max	-	Mar	21	0:00	1:00	D
{ 66, 255, 0, 20,  1, 23, 0, 1,  9, 0}, // 	Iran	2036	max	-	Sep	21	0:00	0	S
{ 44, 255, 4,  0,  1, 24, 0, 1,  3, 1}, // 	Jordan	2014	max	-	Mar	lastThu	24:00	1:00	S
{ 44, 255, 5,  0,  1,  0, 0, 0, 10, 0}, // 	Jordan	2014	max	-	Oct	lastFri	0:00s	0	-
{ 38, 255, 7,  1,  1,  1, 0, 1,  4, 0}, // 	LH	2008	max	-	Apr	Sun>=1	2:00	0	S
{ 38, 255, 7,  1,  1,  1, 0, 2, 10, 0}, // 	LH	2008	max	-	Oct	Sun>=1	2:00	0:30	D
{ 23, 255, 7,  0,  1,  0, 0, 1,  3, 1}, // 	Lebanon	1993	max	-	Mar	lastSun	0:00	1:00	S
{ 29, 255, 7,  0,  1,  0, 0, 0, 10, 0}, // 	Lebanon	1999	max	-	Oct	lastSun	0:00	0	-
{ 32, 255, 7,  1,  1,  2, 0, 2,  4, 1}, // 	Mexico	2002	max	-	Apr	Sun>=1	2:00	1:00	D
{ 32, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Mexico	2002	max	-	Oct	lastSun	2:00	0	S
{ 27, 255, 7,  0,  1,  2, 0, 1,  3, 1}, // 	Moldova	1997	max	-	Mar	lastSun	 2:00	1:00	S
{ 27, 255, 7,  0,  1,  2, 0, 0, 10, 0}, // 	Moldova	1997	max	-	Oct	lastSun	 3:00	0	-
{ 45, 255, 6,  0,  1,  2, 0, 1,  3, 1}, // 	Mongol	2015	max	-	Mar	lastSat	2:00	1:00	S
{ 45, 255, 6,  0,  1,  0, 0, 0,  9, 0}, // 	Mongol	2015	max	-	Sep	lastSat	0:00	0	-
{ 43, 255, 7,  0,  1,  2, 0, 0, 10, 0}, // 	Morocco	2013	max	-	Oct	lastSun	 3:00	0	-
{ 44,  51, 7,  0,  1,  2, 0, 1,  3, 1}, // 	Morocco	2014	2021	-	Mar	lastSun	 2:00	1:00	S
{ 47,  47, 0, 21,  1,  2, 0, 0,  5, 0}, // 	Morocco	2017	only	-	May	21	 3:00	0	-
{ 47,  47, 0,  2,  1,  2, 0, 1,  7, 1}, // 	Morocco	2017	only	-	Jul	 2	 2:00	1:00	S
{ 48,  48, 0, 13,  1,  2, 0, 0,  5, 0}, // 	Morocco	2018	only	-	May	13	 3:00	0	-
{ 48,  48, 0, 17,  1,  2, 0, 1,  6, 1}, // 	Morocco	2018	only	-	Jun	17	 2:00	1:00	S
{ 49,  49, 0,  5,  1,  2, 0, 0,  5, 0}, // 	Morocco	2019	only	-	May	 5	 3:00	0	-
{ 49,  49, 0,  9,  1,  2, 0, 1,  6, 1}, // 	Morocco	2019	only	-	Jun	 9	 2:00	1:00	S
{ 50,  50, 0, 19,  1,  2, 0, 0,  4, 0}, // 	Morocco	2020	only	-	Apr	19	 3:00	0	-
{ 50,  50, 0, 24,  1,  2, 0, 1,  5, 1}, // 	Morocco	2020	only	-	May	24	 2:00	1:00	S
{ 51,  51, 0, 11,  1,  2, 0, 0,  4, 0}, // 	Morocco	2021	only	-	Apr	11	 3:00	0	-
{ 51,  51, 0, 16,  1,  2, 0, 1,  5, 1}, // 	Morocco	2021	only	-	May	16	 2:00	1:00	S
{ 52,  52, 0,  8,  1,  2, 0, 1,  5, 1}, // 	Morocco	2022	only	-	May	 8	 2:00	1:00	S
{ 53,  53, 0, 23,  1,  2, 0, 1,  4, 1}, // 	Morocco	2023	only	-	Apr	23	 2:00	1:00	S
{ 54,  54, 0, 14,  1,  2, 0, 1,  4, 1}, // 	Morocco	2024	only	-	Apr	14	 2:00	1:00	S
{ 55,  55, 0,  6,  1,  2, 0, 1,  4, 1}, // 	Morocco	2025	only	-	Apr	 6	 2:00	1:00	S
{ 56, 255, 7,  0,  1,  2, 0, 1,  3, 1}, // 	Morocco	2026	max	-	Mar	lastSun	 2:00	1:00	S
{ 66,  66, 0, 19,  1,  2, 0, 0, 10, 0}, // 	Morocco	2036	only	-	Oct	19	 3:00	0	-
{ 67,  67, 0,  4,  1,  2, 0, 0, 10, 0}, // 	Morocco	2037	only	-	Oct	 4	 3:00	0	-
{ 37, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	NZ	2007	max	-	Sep	lastSun	2:00s	1:00	D
{ 38, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	NZ	2008	max	-	Apr	Sun>=1	2:00s	0	S
{ 24, 255, 7,  1,  1,  2, 0, 1,  9, 1}, // 	Namibia	1994	max	-	Sep	Sun>=1	2:00	1:00	S
{ 25, 255, 7,  1,  1,  1, 0, 0,  4, 0}, // 	Namibia	1995	max	-	Apr	Sun>=1	2:00	0	-
{ 46, 255, 6,  0,  1,  1, 0, 1,  3, 1}, //  Palestine	2016	max	-	Mar	lastSat	1:00	1:00	S
{ 46, 255, 6,  0,  1,  0, 0, 0, 10, 0}, //  Palestine	2016	max	-	Oct	lastSat	1:00	0	-
{ 40, 255, 7,  1,  1,  0, 0, 1, 10, 1}, // 	Para	2010	max	-	Oct	Sun>=1	0:00	1:00	S
{ 43, 255, 6, 21,  1, 23, 0, 0,  3, 0}, // 	Para	2013	max	-	Mar	Sun>=22	0:00	0	-
{ 42, 255, 5,  0,  1,  0, 0, 1,  3, 1}, // 	Syria	2012	max	-	Mar	lastFri	0:00	1:00	S
{ 39, 255, 5,  0,  1,  0, 0, 0, 10, 0}, // 	Syria	2009	max	-	Oct	lastFri	0:00	0	-
{ 37, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Thule	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{ 37, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Thule	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 46, 255, 7,  1,  1,  2, 0, 1, 11, 1}, // 	Tonga	2016	max	-	Nov	Sun>=1	2:00	1:00	S
{ 47, 255, 7, 15,  1,  2, 0, 0,  1, 0}, // 	Tonga	2017	max	-	Jan	Sun>=15	3:00	0	-
{ 37, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	US	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{ 37, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	US	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 42, 255, 7,  1,  1,  3, 0, 1,  4, 0}, // 	WS	2012	max	-	Apr	Sun>=1	4:00	0	S
{ 42, 255, 7,  0,  1,  3, 0, 2,  9, 1}, // 	WS	2012	max	-	Sep	lastSun	3:00	1	D
{ 43, 255, 5, 23,  1,  2, 0, 2,  3, 1}, // 	Zion	2013	max	-	Mar	Fri>=23	2:00	1:00	D
{ 43, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Zion	2013	max	-	Oct	lastSun	2:00	0	S
};

uzone_t zones[165] = {
// Africa/Abidjan	0:00	-	GMT
// Africa/Bissau	0:00	-	GMT
// Africa/Monrovia	0:00	-	GMT
// America/Danmarkshavn	0:00	-	GMT
// Atlantic/Reykjavik	0:00	-	GMT
{  0,   0,   0, { 'G', 'M', 'T','\0'}},
// Africa/Accra	0:00	Ghana	%s
{  0,   0,   0, { 'S','\0','\0','\0'}},
// Africa/Algiers	1:00	-	CET
{  4,   0,   0, { 'C', 'E', 'T','\0'}},
// Africa/Cairo	2:00	Egypt	EE%sT
{  8,   0,   0, { 'E', 'E', 'S', 'T'}},
// Africa/Casablanca	0:00	Morocco	WE%sT
// Africa/El_Aaiun	0:00	Morocco	WE%sT
{  0,  57,  19, { 'W', 'E', '%', 'T'}},
// Africa/Ceuta	1:00	EU	CE%sT
// Europe/Amsterdam	1:00	EU	CE%sT
// Europe/Andorra	1:00	EU	CE%sT
// Europe/Belgrade	1:00	EU	CE%sT
// Europe/Berlin	1:00	EU	CE%sT
// Europe/Brussels	1:00	EU	CE%sT
// Europe/Budapest	1:00	EU	CE%sT
// Europe/Copenhagen	1:00	EU	CE%sT
// Europe/Gibraltar	1:00	EU	CE%sT
// Europe/Luxembourg	1:00	EU	CE%sT
// Europe/Madrid	1:00	EU	CE%sT
// Europe/Malta	1:00	EU	CE%sT
// Europe/Monaco	1:00	EU	CE%sT
// Europe/Oslo	1:00	EU	CE%sT
// Europe/Paris	1:00	EU	CE%sT
// Europe/Prague	1:00	EU	CE%sT
// Europe/Rome	1:00	EU	CE%sT
// Europe/Stockholm	1:00	EU	CE%sT
// Europe/Tirane	1:00	EU	CE%sT
// Europe/Vienna	1:00	EU	CE%sT
// Europe/Warsaw	1:00	EU	CE%sT
// Europe/Zurich	1:00	EU	CE%sT
{  4,  27,   2, { 'C', 'E', '%', 'T'}},
// Africa/Johannesburg	2:00	SA	SAST
{  8,   0,   0, { 'S', 'A', 'S', 'T'}},
// Africa/Khartoum	3:00	-	EAT
// Africa/Nairobi	3:00	-	EAT
{ 12,   0,   0, { 'E', 'A', 'T','\0'}},
// Africa/Lagos	1:00	-	WAT
// Africa/Ndjamena	1:00	-	WAT
{  4,   0,   0, { 'W', 'A', 'T','\0'}},
// Africa/Maputo	2:00	-	CAT
{  8,   0,   0, { 'C', 'A', 'T','\0'}},
// Africa/Tripoli	2:00	-	EET
// Europe/Kaliningrad	2:00	-	EET
{  8,   0,   0, { 'E', 'E', 'T','\0'}},
// Africa/Tunis	1:00	Tunisia	CE%sT
{  4,   0,   0, { 'C', 'E', 'S', 'T'}},
// Africa/Windhoek	1:00	Namibia	WA%sT
{  4,  78,   2, { 'W', 'A', '%', 'T'}},
// America/Adak	-10:00	US	H%sT
{-40,  90,   2, { 'H', '%', 'T','\0'}},
// America/Anchorage	-9:00	US	AK%sT
// America/Juneau	-9:00	US	AK%sT
// America/Metlakatla	-9:00	US	AK%sT
// America/Nome	-9:00	US	AK%sT
// America/Sitka	-9:00	US	AK%sT
// America/Yakutat	-9:00	US	AK%sT
{-36,  90,   2, { 'A', 'K', '%', 'T'}},
// America/Araguaina	-3:00	-	BRT
// America/Bahia	-3:00	-	BRT
// America/Belem	-3:00	-	BRT
// America/Fortaleza	-3:00	-	BRT
// America/Maceio	-3:00	-	BRT
// America/Recife	-3:00	-	BRT
// America/Santarem	-3:00	-	BRT
{-12,   0,   0, { 'B', 'R', 'T','\0'}},
// America/Argentina/Buenos_Aires	-3:00	Arg	AR%sT
// America/Argentina/Cordoba	-3:00	Arg	AR%sT
// America/Argentina/Tucuman	-3:00	Arg	AR%sT
{-12,   0,   0, { 'A', 'R', 'S', 'T'}},
// America/Argentina/Catamarca	-3:00	-	ART
// America/Argentina/Jujuy	-3:00	-	ART
// America/Argentina/La_Rioja	-3:00	-	ART
// America/Argentina/Mendoza	-3:00	-	ART
// America/Argentina/Rio_Gallegos	-3:00	-	ART
// America/Argentina/Salta	-3:00	-	ART
// America/Argentina/San_Juan	-3:00	-	ART
// America/Argentina/San_Luis	-3:00	-	ART
// America/Argentina/Ushuaia	-3:00	-	ART
{-12,   0,   0, { 'A', 'R', 'T','\0'}},
// America/Asuncion	-4:00	Para	PY%sT
{-16,  82,   2, { 'P', 'Y', '%', 'T'}},
// America/Atikokan	-5:00	-	EST
// America/Cancun	-5:00	-	EST
// America/Jamaica	-5:00	-	EST
// America/Panama	-5:00	-	EST
// America/Port-au-Prince	-5:00	Haiti	E%sT
// 	EST		 -5:00	-	EST
{-20,   0,   0, { 'E', 'S', 'T','\0'}},
// America/Bahia_Banderas	-6:00	Mexico	C%sT
// America/Merida	-6:00	Mexico	C%sT
// America/Mexico_City	-6:00	Mexico	C%sT
// America/Monterrey	-6:00	Mexico	C%sT
{-24,  51,   2, { 'C', '%', 'T','\0'}},
// America/Barbados	-4:00	Barb	A%sT
// America/Blanc-Sablon	-4:00	-	AST
// America/Curacao	-4:00	-	AST
// America/Grand_Turk	-4:00	-	AST
// America/Martinique	-4:00	-	AST
// America/Port_of_Spain	-4:00	-	AST
// America/Puerto_Rico	-4:00	-	AST
// America/Santo_Domingo	-4:00	-	AST
{-16,   0,   0, { 'A', 'S', 'T','\0'}},
// America/Belize	-6:00	Belize	C%sT
// America/Costa_Rica	-6:00	CR	C%sT
// America/El_Salvador	-6:00	Salv	C%sT
// America/Guatemala	-6:00	Guat	C%sT
// America/Managua	-6:00	Nic	C%sT
// America/Regina	-6:00	-	CST
// America/Swift_Current	-6:00	-	CST
// America/Tegucigalpa	-6:00	Hond	C%sT
{-24,   0,   0, { 'C', 'S', 'T','\0'}},
// America/Boa_Vista	-4:00	-	AMT
// America/Manaus	-4:00	-	AMT
// America/Porto_Velho	-4:00	-	AMT
{-16,   0,   0, { 'A', 'M', 'T','\0'}},
// America/Bogota	-5:00	CO	CO%sT
{-20,   0,   0, { 'C', 'O', 'S', 'T'}},
// America/Boise	-7:00	US	M%sT
// America/Denver	-7:00	US	M%sT
// America/Ojinaga	-7:00	US	M%sT
// 	MST7MDT		 -7:00	US	M%sT
{-28,  90,   2, { 'M', '%', 'T','\0'}},
// America/Cambridge_Bay	-7:00	Canada	M%sT
// America/Edmonton	-7:00	Canada	M%sT
// America/Inuvik	-7:00	Canada	M%sT
// America/Yellowknife	-7:00	Canada	M%sT
{-28,  19,   2, { 'M', '%', 'T','\0'}},
// America/Campo_Grande	-4:00	Brazil	AM%sT
// America/Cuiaba	-4:00	Brazil	AM%sT
{-16,   8,   9, { 'A', 'M', '%', 'T'}},
// America/Caracas	-4:00	-	VET
{-16,   0,   0, { 'V', 'E', 'T','\0'}},
// America/Cayenne	-3:00	-	GFT
{-12,   0,   0, { 'G', 'F', 'T','\0'}},
// America/Chicago	-6:00	US	C%sT
// America/Indiana/Knox	-6:00	US	C%sT
// America/Indiana/Tell_City	-6:00	US	C%sT
// America/Matamoros	-6:00	US	C%sT
// America/Menominee	-6:00	US	C%sT
// America/North_Dakota/Beulah	-6:00	US	C%sT
// America/North_Dakota/Center	-6:00	US	C%sT
// America/North_Dakota/New_Salem	-6:00	US	C%sT
// 	CST6CDT		 -6:00	US	C%sT
{-24,  90,   2, { 'C', '%', 'T','\0'}},
// America/Chihuahua	-7:00	Mexico	M%sT
// America/Mazatlan	-7:00	Mexico	M%sT
{-28,  51,   2, { 'M', '%', 'T','\0'}},
// America/Creston	-7:00	-	MST
// America/Dawson_Creek	-7:00	-	MST
// America/Fort_Nelson	-7:00	-	MST
// America/Hermosillo	-7:00	-	MST
// America/Phoenix	-7:00	-	MST
// 	MST		 -7:00	-	MST
{-28,   0,   0, { 'M', 'S', 'T','\0'}},
// America/Dawson	-8:00	Canada	P%sT
// America/Vancouver	-8:00	Canada	P%sT
// America/Whitehorse	-8:00	Canada	P%sT
{-32,  19,   2, { 'P', '%', 'T','\0'}},
// America/Detroit	-5:00	US	E%sT
// America/Indiana/Indianapolis	-5:00	US	E%sT
// America/Indiana/Marengo	-5:00	US	E%sT
// America/Indiana/Petersburg	-5:00	US	E%sT
// America/Indiana/Vevay	-5:00	US	E%sT
// America/Indiana/Vincennes	-5:00	US	E%sT
// America/Indiana/Winamac	-5:00	US	E%sT
// America/Kentucky/Louisville	-5:00	US	E%sT
// America/Kentucky/Monticello	-5:00	US	E%sT
// America/Nassau	-5:00	US	E%sT
// America/New_York	-5:00	US	E%sT
// 	EST5EDT		 -5:00	US	E%sT
{-20,  90,   2, { 'E', '%', 'T','\0'}},
// America/Eirunepe	-5:00	-	ACT
// America/Rio_Branco	-5:00	-	ACT
{-20,   0,   0, { 'A', 'C', 'T','\0'}},
// America/Glace_Bay	-4:00	Canada	A%sT
// America/Goose_Bay	-4:00	Canada	A%sT
// America/Halifax	-4:00	Canada	A%sT
// America/Moncton	-4:00	Canada	A%sT
{-16,  19,   2, { 'A', '%', 'T','\0'}},
// America/Godthab	-3:00	EU	WG%sT
{-12,  27,   2, { 'W', 'G', '%', 'T'}},
// America/Guayaquil	-5:00	-	ECT
{-20,   0,   0, { 'E', 'C', 'T','\0'}},
// America/Guyana	-4:00	-	GYT
{-16,   0,   0, { 'G', 'Y', 'T','\0'}},
// America/Havana	-5:00	Cuba	C%sT
{-20,  25,   2, { 'C', '%', 'T','\0'}},
// America/Iqaluit	-5:00	Canada	E%sT
// America/Nipigon	-5:00	Canada	E%sT
// America/Pangnirtung	-5:00	Canada	E%sT
// America/Thunder_Bay	-5:00	Canada	E%sT
// America/Toronto	-5:00	Canada	E%sT
{-20,  19,   2, { 'E', '%', 'T','\0'}},
// America/La_Paz	-4:00	-	BOT
{-16,   0,   0, { 'B', 'O', 'T','\0'}},
// America/Lima	-5:00	Peru	PE%sT
{-20,   0,   0, { 'P', 'E', 'S', 'T'}},
// America/Los_Angeles	-8:00	US	P%sT
// America/Tijuana	-8:00	US	P%sT
// 	PST8PDT		 -8:00	US	P%sT
{-32,  90,   2, { 'P', '%', 'T','\0'}},
// America/Miquelon	-3:00	Canada	PM%sT
{-12,  19,   2, { 'P', 'M', '%', 'T'}},
// America/Montevideo	-3:00	Uruguay	UY%sT
{-12,   0,   0, { 'U', 'Y', 'S', 'T'}},
// America/Noronha	-2:00	-	FNT
{ -8,   0,   0, { 'F', 'N', 'T','\0'}},
// America/Paramaribo	-3:00	-	SRT
{-12,   0,   0, { 'S', 'R', 'T','\0'}},
// America/Rainy_River	-6:00	Canada	C%sT
// America/Rankin_Inlet	-6:00	Canada	C%sT
// America/Resolute	-6:00	Canada	C%sT
// America/Winnipeg	-6:00	Canada	C%sT
{-24,  19,   2, { 'C', '%', 'T','\0'}},
// America/Santiago	-4:00	Chile	CL%sT
// Antarctica/Palmer	-4:00	Chile	CL%sT
{-16,  23,   2, { 'C', 'L', '%', 'T'}},
// America/Sao_Paulo	-3:00	Brazil	BR%sT
{-12,   8,   9, { 'B', 'R', '%', 'T'}},
// America/Scoresbysund	-1:00	EU	EG%sT
{ -4,  27,   2, { 'E', 'G', '%', 'T'}},
// America/St_Johns	-3:30	Canada	N%sT
{-10,  19,   2, { 'N', '%', 'T','\0'}},
// America/Thule	-4:00	Thule	A%sT
{-16,  86,   2, { 'A', '%', 'T','\0'}},
// Antarctica/Macquarie	11:00	-	MIST
{ 44,   0,   0, { 'M', 'I', 'S', 'T'}},
// Asia/Almaty	6:00	-	+06
// Asia/Bishkek	6:00	-	+06
// Asia/Omsk	6:00	-	+06
// Asia/Qyzylorda	6:00	-	+06
{ 24,   0,   0, { '-','\0','\0','\0'}},
// Asia/Amman	2:00	Jordan	EE%sT
{  8,  45,   2, { 'E', 'E', '%', 'T'}},
// Asia/Anadyr	12:00	-	+12
// Asia/Kamchatka	12:00	-	+12
{ 48,   0,   0, { '-','\0','\0','\0'}},
// Asia/Aqtau	5:00	-	+05
// Asia/Aqtobe	5:00	-	+05
// Asia/Ashgabat	5:00	-	+05
// Asia/Atyrau	5:00	-	+05
// Asia/Dushanbe	5:00	-	+05
// Asia/Oral	5:00	-	+05
// Asia/Samarkand	5:00	-	+05
// Asia/Tashkent	5:00	-	+05
// Asia/Yekaterinburg	5:00	-	+05
{ 20,   0,   0, { '-','\0','\0','\0'}},
// Asia/Baghdad	3:00	Iraq	A%sT
// Asia/Qatar	3:00	-	AST
// Asia/Riyadh	3:00	-	AST
{ 12,   0,   0, { 'A', 'S', 'T','\0'}},
// Asia/Baku	4:00	Azer	+04/+05
// Asia/Tbilisi	4:00	-	+04
// Asia/Yerevan	4:00	RussiaAsia	+04/+05
// Europe/Astrakhan	4:00	-	+04
// Europe/Samara	4:00	-	+04
// Europe/Saratov	4:00	-	+04
// Europe/Ulyanovsk	4:00	-	+04
{ 16,   0,   0, { '-','\0','\0','\0'}},
// Asia/Bangkok	7:00	-	ICT
// Asia/Ho_Chi_Minh	7:00	-	ICT
{ 28,   0,   0, { 'I', 'C', 'T','\0'}},
// Asia/Barnaul	7:00	-	+07
// Asia/Krasnoyarsk	7:00	-	+07
// Asia/Novokuznetsk	7:00	-	+07
// Asia/Novosibirsk	7:00	-	+07
// Asia/Tomsk	7:00	-	+07
{ 28,   0,   0, { '-','\0','\0','\0'}},
// Asia/Beirut	2:00	Lebanon	EE%sT
{  8,  49,   2, { 'E', 'E', '%', 'T'}},
// Asia/Brunei	8:00	-	BNT
{ 32,   0,   0, { 'B', 'N', 'T','\0'}},
// Asia/Chita	9:00	-	+09
// Asia/Khandyga	9:00	-	+09
// Asia/Yakutsk	9:00	-	+09
{ 36,   0,   0, { '-','\0','\0','\0'}},
// Asia/Choibalsan	8:00	Mongol	CHO%sT
{ 32,  55,   2, { 'C', 'H', 'O', 'T'}},
// Asia/Colombo	5:30	-	+0530
{ 22,   0,   0, { '-','\0','\0','\0'}},
// Asia/Damascus	2:00	Syria	EE%sT
{  8,  84,   2, { 'E', 'E', '%', 'T'}},
// Asia/Dhaka	6:00	Dhaka	BD%sT
{ 24,   0,   0, { 'B', 'D', 'S', 'T'}},
// Asia/Dili	9:00	-	TLT
{ 36,   0,   0, { 'T', 'L', 'T','\0'}},
// Asia/Dubai	4:00	-	GST
{ 16,   0,   0, { 'G', 'S', 'T','\0'}},
// Asia/Famagusta	3:00	-	+03
// Europe/Istanbul	3:00	-	+03
// Europe/Kirov	3:00	-	+03
// Europe/Minsk	3:00	-	+03
// Europe/Volgograd	3:00	-	+03
{ 12,   0,   0, { '-','\0','\0','\0'}},
// Asia/Gaza	2:00	Palestine	EE%sT
// Asia/Hebron	2:00	Palestine	EE%sT
{  8,  80,   2, { 'E', 'E', '%', 'T'}},
// Asia/Hong_Kong	8:00	HK	HK%sT
{ 32,   0,   0, { 'H', 'K', 'S', 'T'}},
// Asia/Hovd	7:00	Mongol	HOV%sT
{ 28,  55,   2, { 'H', 'O', 'V', 'T'}},
// Asia/Irkutsk	8:00	-	+08
{ 32,   0,   0, { '-','\0','\0','\0'}},
// Asia/Jakarta	7:00	-	WIB
// Asia/Pontianak	7:00	-	WIB
{ 28,   0,   0, { 'W', 'I', 'B','\0'}},
// Asia/Jayapura	9:00	-	WIT
{ 36,   0,   0, { 'W', 'I', 'T','\0'}},
// Asia/Jerusalem	2:00	Zion	I%sT
{  8,  94,   2, { 'I', '%', 'T','\0'}},
// Asia/Kabul	4:30	-	AFT
{ 18,   0,   0, { 'A', 'F', 'T','\0'}},
// Asia/Karachi	5:00	Pakistan	PK%sT
{ 20,   0,   0, { 'P', 'K', 'S', 'T'}},
// Asia/Kathmandu	5:45	-	NPT
{ 23,   0,   0, { 'N', 'P', 'T','\0'}},
// Asia/Kolkata	5:30	-	IST
{ 22,   0,   0, { 'I', 'S', 'T','\0'}},
// Asia/Kuala_Lumpur	8:00	-	MYT
// Asia/Kuching	8:00	-	MYT
{ 32,   0,   0, { 'M', 'Y', 'T','\0'}},
// Asia/Macau	8:00	PRC	C%sT
// Asia/Shanghai	8:00	PRC	C%sT
// Asia/Taipei	8:00	Taiwan	C%sT
{ 32,   0,   0, { 'C', 'S', 'T','\0'}},
// Asia/Magadan	11:00	-	+11
// Asia/Sakhalin	11:00	-	+11
// Asia/Srednekolymsk	11:00	-	+11
{ 44,   0,   0, { '-','\0','\0','\0'}},
// Asia/Makassar	8:00	-	WITA
{ 32,   0,   0, { 'W', 'I', 'T', 'A'}},
// Asia/Manila	8:00	Phil	PH%sT
{ 32,   0,   0, { 'P', 'H', 'S', 'T'}},
// Asia/Nicosia	2:00	EUAsia	EE%sT
{  8,  29,   2, { 'E', 'E', '%', 'T'}},
// Asia/Pyongyang	8:30	-	KST
{ 34,   0,   0, { 'K', 'S', 'T','\0'}},
// Asia/Seoul	9:00	ROK	K%sT
{ 36,   0,   0, { 'K', 'S', 'T','\0'}},
// Asia/Singapore	8:00	-	SGT
{ 32,   0,   0, { 'S', 'G', 'T','\0'}},
// Asia/Tehran	3:30	Iran	IR%sT
{ 14,  33,  12, { 'I', 'R', '%', 'T'}},
// Asia/Thimphu	6:00	-	BTT
{ 24,   0,   0, { 'B', 'T', 'T','\0'}},
// Asia/Tokyo	9:00	Japan	J%sT
{ 36,   0,   0, { 'J', 'S', 'T','\0'}},
// Asia/Ulaanbaatar	8:00	Mongol	ULA%sT
{ 32,  55,   2, { 'U', 'L', 'A', 'T'}},
// Asia/Urumqi	6:00	-	XJT
{ 24,   0,   0, { 'X', 'J', 'T','\0'}},
// Asia/Ust-Nera	10:00	-	+10
// Asia/Vladivostok	10:00	-	+10
{ 40,   0,   0, { '-','\0','\0','\0'}},
// Asia/Yangon	6:30	-	MMT
{ 26,   0,   0, { 'M', 'M', 'T','\0'}},
// Atlantic/Azores	-1:00	EU	AZO%sT
{ -4,  27,   2, { 'A', 'Z', 'O', 'T'}},
// Atlantic/Bermuda	-4:00	US	A%sT
{-16,  90,   2, { 'A', '%', 'T','\0'}},
// Atlantic/Canary	0:00	EU	WE%sT
// Atlantic/Faroe	0:00	EU	WE%sT
// Atlantic/Madeira	0:00	EU	WE%sT
// Europe/Lisbon	0:00	EU	WE%sT
// 	WET		0:00	EU	WE%sT
{  0,  27,   2, { 'W', 'E', '%', 'T'}},
// Atlantic/Cape_Verde	-1:00	-	CVT
{ -4,   0,   0, { 'C', 'V', 'T','\0'}},
// Atlantic/South_Georgia	-2:00	-	GST
{ -8,   0,   0, { 'G', 'S', 'T','\0'}},
// Atlantic/Stanley	-3:00	-	FKST
{-12,   0,   0, { 'F', 'K', 'S', 'T'}},
// Australia/Adelaide	9:30	AS	AC%sT
// Australia/Broken_Hill	9:30	AS	AC%sT
{ 38,   2,   2, { 'A', 'C', '%', 'T'}},
// Australia/Brisbane	10:00	AQ	AE%sT
// Australia/Lindeman	10:00	Holiday	AE%sT
{ 40,   0,   0, { 'A', 'E', 'S', 'T'}},
// Australia/Currie	10:00	AT	AE%sT
// Australia/Hobart	10:00	AT	AE%sT
{ 40,   4,   2, { 'A', 'E', '%', 'T'}},
// Australia/Darwin	9:30	Aus	AC%sT
{ 38,   0,   0, { 'A', 'C', 'S', 'T'}},
// Australia/Eucla	8:45	AW	ACW%sT
{ 35,   0,   0, { '-','\0','\0','\0'}},
// Australia/Lord_Howe	10:30	LH	LH%sT
{ 42,  47,   2, { 'L', 'H', '%', 'T'}},
// Australia/Melbourne	10:00	AV	AE%sT
{ 40,   6,   2, { 'A', 'E', '%', 'T'}},
// Australia/Perth	8:00	AW	AW%sT
{ 32,   0,   0, { 'A', 'W', 'S', 'T'}},
// Australia/Sydney	10:00	AN	AE%sT
{ 40,   0,   2, { 'A', 'E', '%', 'T'}},
// 	CET		1:00	C-Eur	CE%sT
{  4,  17,   2, { 'C', 'E', '%', 'T'}},
// 	EET		2:00	EU	EE%sT
// Europe/Athens	2:00	EU	EE%sT
// Europe/Bucharest	2:00	EU	EE%sT
// Europe/Helsinki	2:00	EU	EE%sT
// Europe/Kiev	2:00	EU	EE%sT
// Europe/Riga	2:00	EU	EE%sT
// Europe/Sofia	2:00	EU	EE%sT
// Europe/Tallinn	2:00	EU	EE%sT
// Europe/Uzhgorod	2:00	EU	EE%sT
// Europe/Vilnius	2:00	EU	EE%sT
// Europe/Zaporozhye	2:00	EU	EE%sT
{  8,  27,   2, { 'E', 'E', '%', 'T'}},
// Europe/Chisinau	2:00	Moldova	EE%sT
{  8,  53,   2, { 'E', 'E', '%', 'T'}},
// Europe/Dublin	0:00	EU	GMT/IST
{  0,  27,   2, { '/', 'I', 'S', 'T'}},
// Europe/London	0:00	EU	GMT/BST
{  0,  27,   2, { '/', 'B', 'S', 'T'}},
// Europe/Moscow	3:00	-	MSK
// Europe/Simferopol	3:00	-	MSK
{ 12,   0,   0, { 'M', 'S', 'K','\0'}},
// 	HST		-10:00	-	HST
// Pacific/Honolulu	-10:00	-	HST
{-40,   0,   0, { 'H', 'S', 'T','\0'}},
// Indian/Chagos	6:00	-	IOT
{ 24,   0,   0, { 'I', 'O', 'T','\0'}},
// Indian/Christmas	7:00	-	CXT
{ 28,   0,   0, { 'C', 'X', 'T','\0'}},
// Indian/Cocos	6:30	-	CCT
{ 26,   0,   0, { 'C', 'C', 'T','\0'}},
// Indian/Mahe	4:00	-	SCT
{ 16,   0,   0, { 'S', 'C', 'T','\0'}},
// Indian/Maldives	5:00	-	MVT
{ 20,   0,   0, { 'M', 'V', 'T','\0'}},
// Indian/Mauritius	4:00	Mauritius	MU%sT
{ 16,   0,   0, { 'M', 'U', 'S', 'T'}},
// Indian/Reunion	4:00	-	RET
{ 16,   0,   0, { 'R', 'E', 'T','\0'}},
// 	MET		1:00	C-Eur	ME%sT
{  4,  17,   2, { 'M', 'E', '%', 'T'}},
// Pacific/Apia	13:00	WS	WS%sT
{ 52,  92,   2, { 'W', 'S', '%', 'T'}},
// Pacific/Auckland	12:00	NZ	NZ%sT
{ 48,  76,   2, { 'N', 'Z', '%', 'T'}},
// Pacific/Bougainville	11:00	-	BST
{ 44,   0,   0, { 'B', 'S', 'T','\0'}},
// Pacific/Chatham	12:45	Chatham	CHA%sT
{ 51,  21,   2, { 'C', 'H', 'A', 'T'}},
// Pacific/Chuuk	10:00	-	CHUT
{ 40,   0,   0, { 'C', 'H', 'U', 'T'}},
// Pacific/Easter	-6:00	Chile	EAS%sT
{-24,  23,   2, { 'E', 'A', 'S', 'T'}},
// Pacific/Efate	11:00	Vanuatu	VU%sT
{ 44,   0,   0, { 'V', 'U', 'S', 'T'}},
// Pacific/Enderbury	13:00	-	PHOT
{ 52,   0,   0, { 'P', 'H', 'O', 'T'}},
// Pacific/Fakaofo	13:00	-	TKT
{ 52,   0,   0, { 'T', 'K', 'T','\0'}},
// Pacific/Fiji	12:00	Fiji	FJ%sT
{ 48,  31,   2, { 'F', 'J', '%', 'T'}},
// Pacific/Funafuti	12:00	-	TVT
{ 48,   0,   0, { 'T', 'V', 'T','\0'}},
// Pacific/Galapagos	-6:00	-	GALT
{-24,   0,   0, { 'G', 'A', 'L', 'T'}},
// Pacific/Gambier	-9:00	-	GAMT
{-36,   0,   0, { 'G', 'A', 'M', 'T'}},
// Pacific/Guadalcanal	11:00	-	SBT
{ 44,   0,   0, { 'S', 'B', 'T','\0'}},
// Pacific/Guam	10:00	-	ChST
{ 40,   0,   0, { 'C', 'h', 'S', 'T'}},
// Pacific/Kiritimati	14:00	-	LINT
{ 56,   0,   0, { 'L', 'I', 'N', 'T'}},
// Pacific/Kosrae	11:00	-	KOST
{ 44,   0,   0, { 'K', 'O', 'S', 'T'}},
// Pacific/Kwajalein	12:00	-	MHT
// Pacific/Majuro	12:00	-	MHT
{ 48,   0,   0, { 'M', 'H', 'T','\0'}},
// Pacific/Marquesas	-9:30	-	MART
{-34,   0,   0, { 'M', 'A', 'R', 'T'}},
// Pacific/Nauru	12:00	-	NRT
{ 48,   0,   0, { 'N', 'R', 'T','\0'}},
// Pacific/Niue	-11:00	-	NUT
{-44,   0,   0, { 'N', 'U', 'T','\0'}},
// Pacific/Norfolk	11:00	-	NFT
{ 44,   0,   0, { 'N', 'F', 'T','\0'}},
// Pacific/Noumea	11:00	NC	NC%sT
{ 44,   0,   0, { 'N', 'C', 'S', 'T'}},
// Pacific/Pago_Pago	-11:00	-	SST
{-44,   0,   0, { 'S', 'S', 'T','\0'}},
// Pacific/Palau	9:00	-	PWT
{ 36,   0,   0, { 'P', 'W', 'T','\0'}},
// Pacific/Pitcairn	-8:00	-	PST
{-32,   0,   0, { 'P', 'S', 'T','\0'}},
// Pacific/Pohnpei	11:00	-	PONT
{ 44,   0,   0, { 'P', 'O', 'N', 'T'}},
// Pacific/Port_Moresby	10:00	-	PGT
{ 40,   0,   0, { 'P', 'G', 'T','\0'}},
// Pacific/Rarotonga	-10:00	Cook	CK%sT
{-40,   0,   0, { 'C', 'K', 'S', 'T'}},
// Pacific/Tahiti	-10:00	-	TAHT
{-40,   0,   0, { 'T', 'A', 'H', 'T'}},
// Pacific/Tarawa	12:00	-	GILT
{ 48,   0,   0, { 'G', 'I', 'L', 'T'}},
// Pacific/Tongatapu	13:00	Tonga	+13/+14
{ 52,  88,   2, { '-','\0','\0','\0'}},
// Pacific/Wake	12:00	-	WAKT
{ 48,   0,   0, { 'W', 'A', 'K', 'T'}},
// Pacific/Wallis	12:00	-	WFT
{ 48,   0,   0, { 'W', 'F', 'T','\0'}},
};

#endif /* _UTZ_ZONES_H */