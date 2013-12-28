// Native timers by Emmet

#include <a_http>
#include <amx\amx_header>

#if !defined MAX_NATIVE_TIMERS
	#define MAX_NATIVE_TIMERS (32)
#endif

#if !defined MAX_NATIVE_ARGUMENTS
	#define MAX_NATIVE_ARGUMENTS (16)
#endif

enum g_NativeData
{
	bool:g_NativeActive,
	bool:g_NativeRepeat,
	g_NativeIndex,
	g_NativeTimer,
	g_NativeSpecifiers[MAX_NATIVE_ARGUMENTS]
}

static stock
	g_NativeTimers[MAX_NATIVE_TIMERS][g_NativeData],
	g_NativeArgs[MAX_NATIVE_TIMERS][MAX_NATIVE_ARGUMENTS]
;

// SYSREQ.pri doesn't work unless the function is used somewhere.
// To be on the safe side, we include all of the SA-MP natives here.

forward @function_list(); @function_list()
{
	new
	    Float:X,
	    Float:Y,
	    Float:Z;

    HTTP(0, 0, "", "", "");
    CreateObject(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    AttachObjectToVehicle(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    AttachObjectToObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
    AttachObjectToPlayer(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SetObjectPos(0, 0.0, 0.0, 0.0);
    GetObjectPos(0, X, Y, Z);
    SetObjectRot(0, 0.0, 0.0, 0.0);
    GetObjectRot(0, X, Y, Z);
    IsValidObject(0);
    DestroyObject(0);
    MoveObject(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    StopObject(0);
    IsObjectMoving(0);
    EditObject(0, 0);
    EditPlayerObject(0, 0);
    SelectObject(0);
    CancelEdit(0);
    CreatePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    AttachPlayerObjectToVehicle(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SetPlayerObjectPos(0, 0, 0.0, 0.0, 0.0);
    GetPlayerObjectPos(0, 0, X, Y, Z);
    SetPlayerObjectRot(0, 0, 0.0, 0.0, 0.0);
    GetPlayerObjectRot(0, 0, X, Y, Z);
    IsValidPlayerObject(0, 0);
    DestroyPlayerObject(0, 0);
    MovePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    StopPlayerObject(0, 0);
    IsPlayerObjectMoving(0, 0);
    AttachPlayerObjectToPlayer(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SetObjectMaterial(0, 0, 0, "", "");
    SetPlayerObjectMaterial(0, 0, 0, 0, "", "");
    SetObjectMaterialText(0, "");
    SetPlayerObjectMaterialText(0, 0, "");
    SetSpawnInfo(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
    SpawnPlayer(0);
    SetPlayerPos(0, 0.0, 0.0, 0.0);
    SetPlayerPosFindZ(0, 0.0, 0.0, 0.0);
    GetPlayerPos(0, X, Y, Z);
    SetPlayerFacingAngle(0, 0.0);
    GetPlayerFacingAngle(0, X);
    IsPlayerInRangeOfPoint(0, 0.0, 0.0, 0.0, 0.0);
    print("");
    printf("");
    SendClientMessage(0, 0, "");
    SendClientMessageToAll(0, "");
    SendPlayerMessageToPlayer(0, 0, "");
    SendPlayerMessageToAll(0, "");
    SendDeathMessage(0, 0, 0);
    GameTextForAll("", 0, 0);
    GameTextForPlayer(0, "", 0, 0);
    SetTimer("", 0, 0);
    KillTimer(0);
    GetTickCount();
    GetMaxPlayers();
    SetGravity(0.0);
    AllowAdminTeleport(0);
    SetDeathDropAmount(0);
    CreateExplosion(0.0, 0.0, 0.0, 0, 0);
    EnableZoneNames(0);
    UsePlayerPedAnims();
    DisableInteriorEnterExits();
    SetNameTagDrawDistance(0.0);
    DisableNameTagLOS();
    LimitGlobalChatRadius(0.0);
    LimitPlayerMarkerRadius(0.0);
    ConnectNPC("", "");
    IsPlayerNPC(0);
    IsPlayerAdmin(0);
    Kick(0);
    Ban(0);
    BanEx(0, "");
    SendRconCommand("");
    GetServerVarAsString("", "", 0);
    GetServerVarAsInt("");
    GetServerVarAsBool("");
    GetPlayerNetworkStats(0, "", 0);
    GetNetworkStats("", 0);
    GetPlayerVersion(0, "", 0);
    DestroyMenu(Menu:0);
    AddMenuItem(Menu:0, 0, "");
    SetMenuColumnHeader(Menu:0, 0, "");
    ShowMenuForPlayer(Menu:0, 0);
    HideMenuForPlayer(Menu:0, 0);
    IsValidMenu(Menu:0);
    DisableMenu(Menu:0);
    DisableMenuRow(Menu:0, 0);
    TextDrawFont(Text:0, 0);
    TextDrawSetProportional(Text:0, 0);
    TextDrawSetSelectable(Text:0, 0);
    TextDrawShowForPlayer(0, Text:0);
    TextDrawHideForPlayer(0, Text:0);
    TextDrawShowForAll(Text:0);
    TextDrawHideForAll(Text:0);
    TextDrawSetString(Text:0, "");
    TextDrawSetPreviewModel(Text:0, 0);
    TextDrawSetPreviewRot(Text:0, 0.0, 0.0, 0.0, 0);
    TextDrawSetPreviewVehCol(Text:0, 0, 0);
    GangZoneCreate(0.0, 0.0, 0.0, 0.0);
    GangZoneDestroy(0);
    GangZoneShowForPlayer(0, 0, 0);
    GangZoneShowForAll(0, 0);
    GangZoneHideForPlayer(0, 0);
    GangZoneHideForAll(0);
    GangZoneFlashForPlayer(0, 0, 0);
    GangZoneFlashForAll(0, 0);
    GangZoneStopFlashForPlayer(0, 0);
    GangZoneStopFlashForAll(0);
    db_close(DB:0);
    CreateVehicle(0, 0.0, 0.0, 0.0, 0.0, -1, -1, -1);
    DestroyVehicle(0);
    IsVehicleStreamedIn(0, 0);
    GetVehiclePos(0, X, Y, Z);
    SetVehiclePos(0, 0.0, 0.0, 0.0);
    GetVehicleZAngle(0, X);
    GetVehicleRotationQuat(0, X, Y, Z, X);
    heapspace();
    funcidx("");
    numargs();
    getarg(0);
    setarg(0, 0, 0);
    tolower(0);
    toupper(0);
    swapchars(0);
    random(0);
    min(0, 0);
    max(0, 0);
    clamp(0);
    getproperty();
    setproperty();
    deleteproperty();
    existproperty();
    fwrite(File:0, "");
    fread(File:0, "", 0, false);
    fgetchar(File:0, 0, false);
    fblockwrite(File:0, "", 0);
    fblockread(File:0, "", 0);
    fseek(File:0, 0, seek_whence:0);
    flength(File:0);
    fexist("");
    floatround(0.0, floatround_method:0);
    floatcmp(0.0, 0.0);
    strlen("");
    strpack("", "");
    strunpack("", "");
    strcat("", "");
    strmid("", "", 0, 0);
    gettime();
    getdate();
    tickcount();
    return 0;
}

stock GetVariadicAddress(argument)
{
	#emit LOAD.S.pri argument
	#emit SHL.C.pri 2

	#emit LOAD.S.alt 0
	#emit ADD

	#emit ADD.C 12
    #emit LOAD.I

	#emit RETN
	return 0;
}

stock IsVariadicFunction(function[])
{
	static const aVariadicFunctions[][] =
	{
	    {"printf"},
	    {"format"},
	    {"SetTimerEx"},
	    {"CallLocalFunction"},
	    {"CallRemoteFunction"}
	};
	for (new i = 0; i < sizeof(aVariadicFunctions); i ++)
	{
	    if (!strcmp(aVariadicFunctions[i], function, true)) return 1;
	}
	return 0;
}

stock Native_Timer(function[], interval, repeating, specifiers[] = "", {Float,_}:...)
{
	static timerid;

	for (timerid = 0; g_NativeTimers[timerid][g_NativeActive]; )
	{
	    timerid++;
	}
	if (g_NativeTimers[timerid][g_NativeActive] || timerid >= MAX_NATIVE_TIMERS)
	{
	    return -1;
	}
	else
	{
	    for (new i = 0, len = strlen(specifiers); i != len; i ++)
	    {
			if ((g_NativeTimers[timerid][g_NativeSpecifiers][i] = specifiers[i]))
			{
			    if (IsVariadicFunction(function))
			    {
			        g_NativeArgs[timerid][i] = GetVariadicAddress(i + 4);
			    }
				else g_NativeArgs[timerid][i] = (specifiers[i] == 's') ? (GetVariadicAddress(i + 4)) : (getarg(i + 4));
			}
		}
		g_NativeTimers[timerid][g_NativeActive] = true;
		g_NativeTimers[timerid][g_NativeRepeat] = bool:repeating;

		g_NativeTimers[timerid][g_NativeIndex] = GetNativeIndexFromName(function);
		g_NativeTimers[timerid][g_NativeTimer] = SetTimerEx("@call_native", interval, repeating, "d", timerid);
 	}
	return timerid;
}

stock Native_Kill(timerid)
{
	if (!g_NativeTimers[timerid][g_NativeActive])
	    return 0;

    g_NativeTimers[timerid][g_NativeActive] = false;
	g_NativeTimers[timerid][g_NativeSpecifiers][0] = '\0';

	for (new i = 0; i < MAX_NATIVE_ARGUMENTS; i ++) {
	    g_NativeArgs[timerid][i] = 0;
	}
	return 1;
}

forward @call_native(timerid); @call_native(timerid)
{
 	static
 	    i = 0,
		length,
		index;

	length = strlen(g_NativeTimers[timerid][g_NativeSpecifiers]);
 	index = g_NativeTimers[timerid][g_NativeIndex];

 	for (i = length; --i >= 0; )
	{
  		#emit CONST.pri g_NativeArgs
  		#emit PUSH.pri
    	#emit LOAD.S.pri timerid
    	#emit SHL.C.pri 2
	    #emit POP.alt
	   	#emit ADD
	    #emit PUSH.pri
	    #emit LOAD.I
     	#emit POP.alt
	    #emit ADD
		#emit PUSH.pri
	    #emit LOAD.pri i
	    #emit SHL.C.pri 2
	    #emit POP.alt
	    #emit ADD
	    #emit PUSH.pri
     	#emit LOAD.I
		#emit POP.alt
	 	//#emit ADD
		#emit PUSH.pri
	}
	length <<= 2;

	#emit PUSH.C length

	#emit LOAD.pri index
	#emit SYSREQ.pri

	#emit LCTRL 5
	#emit SCTRL 4

	if (!g_NativeTimers[timerid][g_NativeRepeat])
	{
	    Native_Kill(timerid);
	}
	return 1;
}
