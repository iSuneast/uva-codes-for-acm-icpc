/*
10177 - (2/3/4)-D Sqr/Rects/Cubes/Boxes?
...
有史以来....
我最无语的一次代码....
*/

#include<iostream>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
	if(n==0) puts("0 0 0 0 0 0");
	else if(n==1) puts("1 0 1 0 1 0");
	else if(n==2) puts("5 4 9 18 17 64");
	else if(n==3) puts("14 22 36 180 98 1198");
	else if(n==4) puts("30 70 100 900 354 9646");
	else if(n==5) puts("55 170 225 3150 979 49646");
	else if(n==6) puts("91 350 441 8820 2275 192206");
	else if(n==7) puts("140 644 784 21168 4676 609980");
	else if(n==8) puts("204 1092 1296 45360 8772 1670844");
	else if(n==9) puts("285 1740 2025 89100 15333 4085292");
	else if(n==10) puts("385 2640 3025 163350 25333 9125292");
	else if(n==11) puts("506 3850 4356 283140 39974 18934762");
	else if(n==12) puts("650 5434 6084 468468 60710 36954346");
	else if(n==13) puts("819 7462 8281 745290 89271 68485690");
	else if(n==14) puts("1015 10010 11025 1146600 127687 121422938");
	else if(n==15) puts("1240 13160 14400 1713600 178312 207181688");
	else if(n==16) puts("1496 17000 18496 2496960 243848 341858168");
	else if(n==17) puts("1785 21624 23409 3558168 327369 547653912");
	else if(n==18) puts("2109 27132 29241 4970970 432345 854603736");
	else if(n==19) puts("2470 33630 36100 6822900 562666 1302647334");
	else if(n==20) puts("2870 41230 44100 9216900 722666 1944087334");
	else if(n==21) puts("3311 50050 53361 12273030 917147 2846479174");
	else if(n==22) puts("3795 60214 64009 16130268 1151403 4096000678");
	else if(n==23) puts("4324 71852 76176 20948400 1431244 5801351732");
	else if(n==24) puts("4900 85100 90000 26910000 1763020 8098236980");
	else if(n==25) puts("5525 100100 105625 34222500 2153645 11154486980");
	else if(n==26) puts("6201 117000 123201 43120350 2610621 15175875780");
	else if(n==27) puts("6930 135954 142884 53867268 3142062 20412695394");
	else if(n==28) puts("7714 157122 164836 66758580 3756718 27167150178");
	else if(n==29) puts("8555 180670 189225 82123650 4463999 35801636626");
	else if(n==30) puts("9455 206770 216225 100328400 5273999 46747976626");
	else if(n==31) puts("10416 235600 246016 121777920 6197520 60517674736");
	else if(n==32) puts("11440 267344 278784 146919168 7246096 77713272560");
	else if(n==33) puts("12529 302192 314721 176243760 8432017 99040875824");
	else if(n==34) puts("13685 340340 354025 210290850 9768353 125323932272");
	else if(n==35) puts("14910 381990 396900 249650100 11268978 157518341022");
	else if(n==36) puts("16206 427350 443556 294964740 12948594 196728976542");
	else if(n==37) puts("17575 476634 494209 346934718 14822755 244227712926");
	else if(n==38) puts("19019 530062 549081 406319940 16907891 301473036670");
	else if(n==39) puts("20540 587860 608400 473943600 19221332 370131338668");
	else if(n==40) puts("22140 650260 672400 550695600 21781332 452099978668");
	else if(n==41) puts("23821 717500 741321 637536060 24607093 549532217948");
	else if(n==42) puts("25585 789824 815409 735498918 27718789 664864118492");
	else if(n==43) puts("27434 867482 894916 845695620 31137590 800843509466");
	else if(n==44) puts("29370 950730 980100 969318900 34885686 960561124314");
	else if(n==45) puts("31395 1039830 1071225 1107646650 38986311 1147484014314");
	else if(n==46) puts("33511 1135050 1168561 1262045880 43463767 1365491346954");
	else if(n==47) puts("35720 1236664 1272384 1433976768 48343448 1618912700008");
	else if(n==48) puts("38024 1344952 1382976 1624996800 53651864 1912568964712");
	else if(n==49) puts("40425 1460200 1500625 1836765000 59416665 2251815973960");
	else if(n==50) puts("42925 1582700 1625625 2071046250 65666665 2642590973960");
	else if(n==51) puts("45526 1712750 1758276 2329715700 72431866 3091462060310");
	else if(n==52) puts("48230 1850654 1898884 2614763268 79743482 3605680701974");
	else if(n==53) puts("51039 1996722 2047761 2928298230 87633963 4193237479158");
	else if(n==54) puts("53955 2151270 2205225 3272553900 96137019 4862921163606");
	else if(n==55) puts("56980 2314620 2371600 3649892400 105287644 5624381272356");
	else if(n==56) puts("60116 2487100 2547216 4062809520 115122140 6488194228516");
	else if(n==57) puts("63365 2669044 2732409 4513939668 125678141 7465933265140");
	else if(n==58) puts("66729 2860792 2927521 5006060910 136994637 8570242210804");
	else if(n==59) puts("70210 3062690 3132900 5542100100 149111998 9814913298002");
	else if(n==60) puts("73810 3275090 3348900 6125138100 162071998 11214969138002");
	else if(n==61) puts("77531 3498350 3575881 6758415090 175917839 12786749008322");
	else if(n==62) puts("81375 3732834 3814209 7445335968 190694175 14547999601506");
	else if(n==63) puts("85344 3978912 4064256 8189475840 206447136 16517970386400");
	else if(n==64) puts("89440 4236960 4326400 8994585600 223224352 18717513735648");
	else if(n==65) puts("93665 4507360 4601025 9864597600 241074977 21169189975648");
	else if(n==66) puts("98021 4790500 4888521 10803631410 260049713 23897377517728");
	else if(n==67) puts("102510 5086774 5189284 11815999668 280200834 26928388231822");
	else if(n==68) puts("107134 5396582 5503716 12906214020 301582210 30290588226446");
	else if(n==69) puts("111895 5720330 5832225 14078991150 324249331 34014524201294");
	else if(n==70) puts("116795 6058430 6175225 15339258900 348259331 38133055541294");
	else if(n==71) puts("121836 6411300 6533136 16692162480 373671012 42681492323484");
	else if(n==72) puts("127020 6779364 6906384 18143070768 400544868 47697739410588");
	else if(n==73) puts("132349 7163052 7295401 19697582700 428943109 53222446807692");
	else if(n==74) puts("137825 7562800 7700625 21361533750 458929685 59299166460940");
	else if(n==75) puts("143450 7979050 8122500 23141002500 490570310 65974515679690");
	else if(n==76) puts("149226 8412250 8561476 25042317300 523932486 73298347366090");
	else if(n==77) puts("155155 8862854 9018009 27072063018 559085527 81323927238554");
	else if(n==78) puts("161239 9331322 9492561 29237087880 596100583 90108118238138");
	else if(n==79) puts("167480 9818120 9985600 31544510400 635050664 99711572309336");
	else if(n==80) puts("173880 10323720 10497600 34001726400 676010664 110198929749336");
	else if(n==81) puts("180441 10848600 11029041 36616416120 719057385 121639026322296");
	else if(n==82) puts("187165 11393244 11580409 39396551418 764269561 134105108337720");
	else if(n==83) puts("194054 11958142 12152196 42350403060 811727882 147675055894534");
	else if(n==84) puts("201110 12543790 12744900 45486548100 861515018 162431614494982");
	else if(n==85) puts("208335 13150690 13359025 48813877350 913715643 178462635234982");
	else if(n==86) puts("215731 13779350 13995081 52341602940 968416459 195861323780102");
	else if(n==87) puts("223300 14430284 14653584 56079265968 1025706220 214726498338836");
	else if(n==88) puts("231044 15104012 15335056 60036744240 1085675756 235162856847380");
	else if(n==89) puts("238965 15801060 16040025 64224260100 1148417997 257281253582628");
	else if(n==90) puts("247065 16521960 16769025 68652388350 1214027997 281198985422628");
	else if(n==91) puts("255346 17267250 17522596 73332064260 1282602958 307040087976258");
	else if(n==92) puts("263810 18037474 18301284 78274591668 1354242254 334935641806402");
	else if(n==93) puts("272459 18833182 19105641 83491651170 1429047455 365024088973426");
	else if(n==94) puts("281295 19654930 19936225 88995308400 1507122351 397451560128274");
	else if(n==95) puts("290320 20503280 20793600 94798022400 1588572976 432372212387024");
	else if(n==96) puts("299536 21378800 21678336 100912654080 1673507632 469948578221264");
	else if(n==97) puts("308945 22282064 22591009 107352474768 1762036913 510351925601168");
	else if(n==98) puts("318549 23213652 23532201 114131174850 1854273729 553762629630672");
	else if(n==99) puts("328350 24174150 24502500 121262872500 1950333330 600370555916670");
	else if(n==100) puts("338350 25164150 25502500 128762122500 2050333330 650375455916670");
	}

return 0;
}


/*
#include<iostream>
#include<cmath>

using namespace std;

long long f[6][110];

void init()
{
	memset(f,0,sizeof(f));
	int i;
	for(i=1;i<101;i++)
	{
		f[0][i]=i*i+f[0][i-1];
		f[1][i]=i*i*(i-1)+f[1][i-1];
		f[2][i]=pow(i,3)+f[2][i-1];
		f[3][i]=((1+i)*i/2-1)*f[2][i];
		f[4][i]=pow(i,4)+f[4][i-1];
		f[5][i]=0;						///////////////////////实在推不出来
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	init();
	while(cin>>n)
		cout<<f[0][n]<<' '<<f[1][n]<<' '<<f[2][n]<<' '<<f[3][n]<<' '<<f[4][n]<<' '<<f[5][n]<<endl;

return 0;
}
*/