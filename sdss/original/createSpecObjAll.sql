BEGIN;
CREATE TABLE "public"."specObjAll" (  
	"specObjID" bigint,
"mjd" int,
"plate" smallint,
"tile" smallint,
"xFocal" float,
"yFocal" float,
"fiberID" smallint,
"z" real,
"zErr" real,
"zConf" real,
"zStatus" smallint,
"specClass" smallint,
"zWarning" int,
"velDisp" real,
"velDispErr" real,
"eCoeff_0" real,
"eCoeff_1" real,
"eCoeff_2" real,
"eCoeff_3" real,
"eCoeff_4" real,
"eClass" real,
"nGood" int,
"sn_0" real,
"sn_1" real,
"sn_2" real,
"mag_0" real,
"mag_1" real,
"mag_2" real,
"ra" float,
"dec" float,
"cx" float,
"cy" float,
"cz" float,
"htmID" bigint,
"fiberMag_u" real,
"fiberMag_g" real,
"fiberMag_r" real,
"fiberMag_i" real,
"fiberMag_z" real,
"primTarget" int,
"secTarget" int,
"pixMin" smallint,
"pixMax" smallint,
"sci_sn" real,
"smear_sn" real,
"sm_leg_0" real,
"sm_leg_1" real,
"sm_leg_2" real,
"sciencePrimary" smallint,
"loadVersion" int,
"plateID" bigint,
"spectrographID" smallint,
"throughput" int,
"objType" int,
"objTypeName" varchar,
"targetID" bigint,
"targetObjID" bigint,
"bestObjID" bigint
);
;

commit;
