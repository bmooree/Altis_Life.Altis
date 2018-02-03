#include "..\..\script_macros.hpp"
/*
	File: fn_adminGodMode.sqf
	Author: Tobias 'Xetoxyc' Sittenauer

	Description: Enables God mode for Admin
*/

// 1 - helpdesk, 2 - moderator, 3 - admin, 4 -server admin, 5 - server manager, 6 - server exec
if(FETCH_CONST(life_adminlevel) < 2) exitWith {hint localize "STR_ANOTF_ErrorLevel";};
if !life_adminVerified exitWith {};
if (life_god && (["zeus_",str player] call BIS_fnc_inString)) exitWith {hint "You cannot exit godmode as GM";};
if (life_god && (["admin_",str player] call BIS_fnc_inString)) exitWith {hint "You cannot exit godmode while in an Admin Slot";};
if (life_currentEvent) exitWith {hint "Event Participants cannot use godmode!"};

if(life_god) then {
	/* Admin Disabled */
	titleText ["God mode disabled","PLAIN"]; titleFadeOut 2;

	/* Damage True */
	player allowDamage true;
	player removeAllEventHandlers "handleDamage";
	player addEventHandler ["handleDamage", {_this call life_fnc_handleDamage;}];
	player enableFatigue true;

	/* Admin Suit Remove & Load Old Gear */
	[] call life_fnc_saveGear;
	[] call life_fnc_stripDownPlayer;
	life_gear = life_gear_prev;
	[] spawn life_fnc_loadGear;
	life_gear_prev = [];
	if(!("ItemMap" in (assignedItems player))) then {player linkItem "ItemMap";};

	/* Load Textures */
	[] spawn life_fnc_copUniform;
	life_god = false;

	/* Logging */
	_logText=format["God mode disabled for %1 who is at %2 (%3)", name player, getPosATL player, mapGridPosition player];
	_logText=[_logText,":",";"] call KRON_Replace;
	["adminGodMode",getPlayerUID player, "", _logText] call OG_fnc_logAction;
} else {
	/* Admin Enabled */
	life_god = true;
	titleText ["God mode enabled","PLAIN"]; titleFadeOut 2;

	/* Damage False */
	player removeAllEventHandlers "handleDamage";
	player addEventHandler ["handleDamage", {false}];
	player allowDamage false;
	player enableFatigue false;
	player setDamage 0;

	/* Save Old Gear */
	//[] call SOCK_fnc_syncData; //This has issue since players can only since once every 5min, maybe allow admins bypass

	/* Admin Suit Add */
	[] call life_fnc_saveGear;
	life_gear_prev = life_gear;
	[] call life_fnc_stripDownPlayer;
	life_carryweight = 0;

	player addGoggles "NVGoggles_OPFOR";
	player addHeadGear "H_CrewHelmetHeli_B";
	player linkItem "NVGoggles";
	player forceAddUniform "U_B_Soldier_VR";
	if(!("ItemMap" in (assignedItems player))) then {player linkItem "ItemMap";};

	/* Logging */
	_logText=format["God mode enabled for %1 who is at %2 (%3)", name player, getPosATL player, mapGridPosition player];
	_logText=[_logText,":",";"] call KRON_Replace;
	["adminGodMode",getPlayerUID player, "", _logText] call OG_fnc_logAction;

	[]spawn{
		while {life_god} do {
			life_hunger = 100;
			life_thirst = 100;
			[] call life_fnc_hudUpdate;
			sleep 600;
		};
	};
};