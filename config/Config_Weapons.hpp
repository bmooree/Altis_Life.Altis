/*
*    FORMAT:
*        STRING (Conditions) - Must return boolean :
*            String can contain any amount of conditions, aslong as the entire
*            string returns a boolean. This allows you to check any levels, licenses etc,
*            in any combination. For example:
*                "call life_coplevel && license_civ_someLicense"
*            This will also let you call any other function.
*            
*
*    ARRAY FORMAT:
*        0: STRING (Classname): Item Classname
*        1: STRING (Nickname): Nickname that will appear purely in the shop dialog
*        2: SCALAR (Buy price)
*        3: SCALAR (Sell price): To disable selling, this should be -1
*        4: STRING (Conditions): Same as above conditions string
*
*    Weapon classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Weapons
*    Item classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Items
*
*/
class WeaponShops {
    //Armory Shops
    class gun {
        name = "Billy Joe's Firearms";
        side = "civ";
        conditions = "license_civ_gun";
        items[] = {
            { "hgun_Rook40_F", "", 6500, 500, "" },
            { "hgun_Pistol_heavy_02_F", "", 9850, -1, "" },
            { "hgun_ACPC2_F", "", 11500, -1, "" },
            { "hgun_PDW2000_F", "", 20000, -1, "" }
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 100, "" },
            { "6Rnd_45ACP_Cylinder", "", 150, 100, "" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "" },
            { "30Rnd_9x21_Mag", "", 250, 100, "" }
        };
        accs[] = {
            { "optic_ACO_grn_smg", "", 2500, 100, "" }
        };
    };

    class rebel {
        name = "Mohammed's Jihadi Shop";
        side = "civ";
        conditions = "license_civ_rebel";
        items[] = {
            { "arifle_TRG20_F", "", 25000, 2500, "" },
            { "arifle_Katiba_F", "", 30000, 5000, "" },
            { "srifle_DMR_01_F", "", 50000, -1, "" },
            { "arifle_SDAR_F", "", 20000, 7500, "" }
        };
        mags[] = {
            { "30Rnd_556x45_Stanag", "", 300, 100, "" },
            { "30Rnd_65x39_caseless_green", "", 275, 100, "" },
            { "10Rnd_762x54_Mag", "", 500, 100, "" },
            { "20Rnd_556x45_UW_mag", "", 125, 100, "" }
        };
        accs[] = {
            { "optic_ACO_grn", "", 3500, 100, "" },
            { "optic_Holosight", "", 3600, 100, "" },
            { "optic_Hamr", "", 7500, 100, "" },
            { "acc_flashlight", "", 1000, 100, "" }
        };
    };

    class gang {
        name = "Hideout Armament";
        side = "civ";
        conditions = "";
        items[] = {
            { "hgun_Rook40_F", "", 1500, 500, "" },
            { "hgun_Pistol_heavy_02_F", "", 2500, -1, "" },
            { "hgun_ACPC2_F", "", 4500, -1, "" },
            { "hgun_PDW2000_F", "", 9500, -1, "" }
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 100, "" },
            { "6Rnd_45ACP_Cylinder", "", 150, 100, "" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "" },
            { "30Rnd_9x21_Mag", "", 250, 100, "" }
        };
        accs[] = {
            { "optic_ACO_grn_smg", "", 950, 100, "" }
        };
    };

    //Basic Shops
    class genstore {
        name = "Altis General Store";
        side = "civ";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, -1, "" },
            { "ItemGPS", "", 100, 45, "" },
            { "ItemMap", "", 50, 35, "" },
            { "ItemCompass", "", 50, 25, "" },
            { "ItemWatch", "", 50, -1, "" },
            { "FirstAidKit", "", 150, 65, "" },
            { "NVGoggles", "", 2000, 980, "" },
            { "Chemlight_red", "", 300, -1, "" },
            { "Chemlight_yellow", "", 300, 50, "" },
            { "Chemlight_green", "", 300, 50, "" },
            { "Chemlight_blue", "", 300, 50, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class f_station_store {
        name = "Altis Fuel Station Store";
        side = "";
        conditions = "";
        items[] = {
            { "Binocular", "", 750, -1, "" },
            { "ItemGPS", "", 500, 45, "" },
            { "ItemMap", "", 250, 35, "" },
            { "ItemCompass", "", 250, 25, "" },
            { "ItemWatch", "", 250, -1, "" },
            { "FirstAidKit", "", 750, 65, "" },
            { "NVGoggles", "", 10000, 980, "" },
            { "Chemlight_red", "", 1500, -1, "" },
            { "Chemlight_yellow", "", 1500, 50, "" },
            { "Chemlight_green", "", 1500, 50, "" },
            { "Chemlight_blue", "", 1500, 50, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    //Cop Shops
    class cop_basic {
        name = "Altis Cop Shop";
        side = "cop";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, -1, "" },
            { "ItemGPS", "", 100, 45, "" },
            { "FirstAidKit", "", 150, 65, "" },
            { "NVGoggles", "", 2000, 980, "" },
			{ "NVGogglesB_blk_F", "", 2000, 980, "" },
            { "HandGrenade_Stone", "Flashbang", 1700, -1, "" },
			{ "DemoCharge_Remote_Mag", "Boom", 1700, -1, "call life_coplevel >= 8" },
			{ "SatchelCharge_Remote_Mag", "BoomBoom", 1700, -1, "call life_coplevel >= 29" },
            { "hgun_P07_snds_F", "Stun Pistol", 2000, 650, "" },
            { "arifle_sdar_F", "Taser Rifle", 20000, 7500, "" },
            { "hgun_P07_F", "", 7500, 1500, "" },
            { "SMG_02_ACO_F", "", 30000, -1, "call life_coplevel >= 1" },
            { "arifle_MX_F", "", 35000, 7500, "call life_coplevel >= 2" },
            { "hgun_ACPC2_F", "", 17500, -1, "call life_coplevel >= 3" },
            { "arifle_MXC_F", "", 30000, 5000, "call life_coplevel >= 2" },
			{ "arifle_MXM_F", "", 30000, 15000, "call life_coplevel >= 3" },
			{ "arifle_SPAR_01_snd_F", "", 10000, 1000, "call life_coplevel >= 1" },
			{ "arifle_TRG21_F", "", 10000, 1000, "call life_coplevel >= 1" },
			{ "arifle_SPAR_03_snd_F", "", 10000, 1000, "call life_coplevel >= 4" },
			{ "arifle_MX_SW_F", "", 10000, 1000, "call life_coplevel >= 5" },
			{ "srifle_EBR_F", "", 10000, 1000, "call life_coplevel >= 5" },
			{ "LMG_03_F", "", 10000, 1000, "call life_coplevel >= 6" },
			{ "srifle_DMR_03_tan_F", "", 10000, 1000, "call life_coplevel >= 6" },
			{ "LMG_Mk200_BI_F", "", 10000, 1000, "call life_coplevel >= 7" },
			{ "srifle_DMR_02_sniper_F", "", 10000, 1000, "call life_coplevel >= 8" },
			{ "arifle_AK12_F", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "hgun_Pistol_heavy_02_F", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "srifle_GM6_F", "", 10000, 1000, "call life_coplevel >= 30" },
			{ "MMG_02_camo_F", "", 10000, 1000, "call life_coplevel >= 30" },
			{ "srifle_LRR_F", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "SMG_01_F", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "arifle_SPAR_02_snd_F", "", 10000, 1000, "call life_coplevel >= 4" }
			
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 100, "" },
            { "20Rnd_556x45_UW_mag", "Taser Rifle Magazine", 125, 100, "" },
            { "30Rnd_65x39_caseless_mag", "", 130, 100, "" },
            { "30Rnd_9x21_Mag", "", 250, 100, "call life_coplevel >= 2" },
            { "9Rnd_45ACP_Mag", "", 200, 100, "call life_coplevel >= 3" },
			{ "30Rnd_556x45_Stanag", "", 200, 100, "call life_coplevel >= 1" },
			{ "20Rnd_762x51_Mag", "", 10000, 1000, "call life_coplevel >= 4" },
			{ "200Rnd_556x45_Box_F", "", 10000, 1000, "call life_coplevel >= 6" },
			{ "200Rnd_65x39_cased_Box", "", 10000, 1000, "call life_coplevel >= 7" },
			{ "10Rnd_338_Mag", "", 10000, 1000, "call life_coplevel >= 8" },
			{ "30Rnd_45ACP_Mag_SMG_01", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "30Rnd_762x39_Mag_F", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "6Rnd_45ACP_Cylinder", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "5Rnd_127x108_APDS_Mag", "", 10000, 1000, "call life_coplevel >= 30" },
			{ "130Rnd_338_Mag", "", 10000, 1000, "call life_coplevel >= 30" },
			{ "7Rnd_408_Mag", "", 10000, 1000, "call life_coplevel >= 29" },
			{ "100Rnd_65x39_caseless_mag", "", 200, 100, "call life_coplevel >= 1" },
			{ "150Rnd_556x45_Drum_Mag_F", "", 10000, 1000, "call life_coplevel >= 4" }
        };
        accs[] = {
			{ "muzzle_snds_B_snd_F", "", 10000, 1000, "call life_coplevel >= 4" },
            { "muzzle_snds_L", "", 650, 100, "" },
			{ "optic_Hamr", "", 10000, 1000, "call life_coplevel >= 1" },
			{ "optic_NVS", "", 10000, 1000, "call life_coplevel >= 3" },
			{ "muzzle_snds_H_snd_F", "", 30000, 15000, "call life_coplevel >= 3" },
            { "acc_flashlight", "", 750, 100, "call life_coplevel >= 2" },
            { "optic_Holosight", "", 1200, 100, "call life_coplevel >= 2" },
            { "optic_Arco", "", 2500, 100, "call life_coplevel >= 2" },
            { "muzzle_snds_H", "", 2750, 100, "call life_coplevel >= 2" },
            { "optic_MRD", "", 2750, 100, "call life_coplevel >= 2" },
			{ "optic_AMS_snd", "", 10000, 1000, "call life_coplevel >= 4" },
			{ "optic_ERCO_snd_F", "", 10000, 1000, "call life_coplevel >= 1" },
			{ "optic_MRCO", "", 10000, 1000, "call life_coplevel >= 1" },
			{ "optic_KHS_tan", "", 10000, 1000, "call life_coplevel >= 5" },
			{ "optic_LRPS", "", 10000, 1000, "call life_coplevel >= 6" },
			{ "optic_tws", "", 10000, 1000, "call life_coplevel >= 7" },
			{ "acc_pointer_IR", "", 10000, 1000, "call life_coplevel >= 8" },
			{ "optic_Nightstalker", "", 10000, 1000, "call life_coplevel >= 8" },
			{ "muzzle_snds_338_sand", "", 10000, 1000, "call life_coplevel >= 8" },
			{ "bipod_01_F_snd", "", 10000, 1000, "call life_coplevel >= 3" }
        };
    };

    //Medic Shops
    class med_basic {
        name = "store";
        side = "med";
        conditions = "";
        items[] = {
            { "ItemGPS", "", 100, 45, "" },
            { "Binocular", "", 150, -1, "" },
            { "FirstAidKit", "", 150, 65, "" },
            { "NVGoggles", "", 1200, 980, "" }
        };
        mags[] = {};
        accs[] = {};
    };
};
