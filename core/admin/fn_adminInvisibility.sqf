#include "..\..\scripts\macro.h"
/*
	File: fn_adminInvisibility.sqf
*/
private ["_unit","_mode"];
// 1 - helpdesk, 2 - moderator, 3 - admin, 4 -server admin, 5 - server manager, 6 - server exec
if(FETCH_CONST(life_adminlevel) < 3) exitWith {hint localize "STR_ANOTF_ErrorLevel";};
if !life_adminVerified exitWith {};

_unit = player;
_mode = player GVAR "adminInvisible";

if !(_mode) then {
	player SVAR ["adminInvisible",true,true];

	[[_unit,true],"OG_fnc_hideObjectGlobal",false,false] spawn life_fnc_MP;
	hint "Invisibility activated";

	_logText=format["Invisibility enabled for %1 who is at %2 (%3)", name player, getPosATL player, mapGridPosition player];
	_logText=[_logText,":",";"] call KRON_Replace;
	["adminInvisibility",getPlayerUID player, "", _logText] call fnc_logAction;
}else{
	player SVAR ["adminInvisible",false,true];

	[[_unit,false],"OG_fnc_hideObjectGlobal",false,false] spawn life_fnc_MP;
	hint "Invisibility deactivated";

	_logText=format["Invisibility disabled for %1 who is at %2 (%3)", name player, getPosATL player, mapGridPosition player];
	_logText=[_logText,":",";"] call KRON_Replace;
	["adminInvisibility",getPlayerUID player, "", _logText] call fnc_logAction;
};

/* ---------- END OF SCRIPT ------------ */