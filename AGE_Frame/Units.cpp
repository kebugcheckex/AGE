#include "../AGE_Frame.h"

//const wxString AGE_Frame::CIVCOUNTWARNING = "Fewer civilizations copied than needed to paste!\nPasting data to extra civilizations from civilization 1!";

void AGE_Frame::OnUnitSubList(wxCommandEvent &event)
{
	short Selection = Units_Civs_List->GetSelection();
	if(Selection == wxNOT_FOUND) return;

	ListUnits(Selection, false);	// List units by selected civ.
}

string AGE_Frame::GetUnitName(short Index, short civ, bool Filter)
{
	string Name = "";

	if(dataset->Civs[civ].UnitPointers[Index] == 0)
	{
		return "*Disabled*";
	}
	if(Filter)
	{
		int filters = 2;
		short Selection[filters];
		for(short loop = 0; loop < filters; ++loop)
		Selection[loop] = Units_SearchFilters[loop]->GetSelection();
		genie::Unit * UnitPointer = &dataset->Civs[civ].Units[Index];

		if(Selection[0] > 0)
		switch(Units_FilterSelector->GetSelection())
		{
			case 0: // Type20
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type20[0]) == 0) Name += "T "+FormatInt(UnitPointer->Type);
				else if(label.compare(Type20[1]) == 0) Name += "NL "+FormatInt(UnitPointer->NameLength);
				else if(label.compare(Type20[2]) == 0) Name += "I1 "+FormatInt(UnitPointer->ID1);
				else if(label.compare(Type20[3]) == 0) Name += "LN "+FormatInt(UnitPointer->LanguageDLLName);
				else if(label.compare(Type20[4]) == 0) Name += "LC "+FormatInt(UnitPointer->LanguageDLLCreation);
				else if(label.compare(Type20[5]) == 0) Name += "C "+FormatInt(UnitPointer->Class);
				else if(label.compare(Type20[6]) == 0) Name += "SG "+FormatInt(UnitPointer->StandingGraphic.first)+" "+FormatInt(UnitPointer->StandingGraphic.second);
				else if(label.compare(Type20[7]) == 0) Name += "DG "+FormatInt(UnitPointer->DyingGraphic.first)+" "+FormatInt(UnitPointer->DyingGraphic.second);
				else if(label.compare(Type20[8]) == 0) Name += "DM "+FormatInt(UnitPointer->DeathMode);
				else if(label.compare(Type20[9]) == 0) Name += "HP "+FormatInt(UnitPointer->HitPoints);
				else if(label.compare(Type20[10]) == 0) Name += "LS "+FormatFloat(UnitPointer->LineOfSight);
				else if(label.compare(Type20[11]) == 0) Name += "GC "+FormatInt(UnitPointer->GarrisonCapacity);
				else if(label.compare(Type20[12]) == 0) Name += "SR "+FormatInt(UnitPointer->SizeRadius.first)+" "+FormatInt(UnitPointer->SizeRadius.second);
				else if(label.compare(Type20[13]) == 0) Name += "B1 "+FormatFloat(UnitPointer->HPBarHeight1);
				else if(label.compare(Type20[14]) == 0) Name += "TS "+FormatInt(UnitPointer->TrainSound.first)+" "+FormatInt(UnitPointer->TrainSound.second);
				else if(label.compare(Type20[15]) == 0) Name += "DU "+FormatInt(UnitPointer->DeadUnitID);
				else if(label.compare(Type20[16]) == 0) Name += "PM "+FormatInt(UnitPointer->PlacementMode);
				else if(label.compare(Type20[17]) == 0) Name += "AM "+FormatInt(UnitPointer->AirMode);
				else if(label.compare(Type20[18]) == 0) Name += "I "+FormatInt(UnitPointer->IconID);
				else if(label.compare(Type20[19]) == 0) Name += "HE "+FormatInt(UnitPointer->HideInEditor);
				else if(label.compare(Type20[20]) == 0) Name += "U1 "+FormatInt(UnitPointer->Unknown1);
				else if(label.compare(Type20[21]) == 0) Name += "E "+FormatInt(UnitPointer->Enabled);
				else if(label.compare(Type20[22]) == 0) Name += "D "+FormatInt(UnitPointer->Disabled);
				else if(label.compare(Type20[23]) == 0) Name += "PBT "+FormatInt(UnitPointer->PlacementBypassTerrain.first)+" "+FormatInt(UnitPointer->PlacementBypassTerrain.second);
				else if(label.compare(Type20[24]) == 0) Name += "PT "+FormatInt(UnitPointer->PlacementTerrain.first)+" "+FormatInt(UnitPointer->PlacementTerrain.second);
				else if(label.compare(Type20[25]) == 0) Name += "ER "+FormatInt(UnitPointer->EditorRadius.first)+" "+FormatInt(UnitPointer->EditorRadius.second);
				else if(label.compare(Type20[26]) == 0) Name += "HM "+FormatInt(UnitPointer->HillMode);
				else if(label.compare(Type20[27]) == 0) Name += "VF "+FormatInt(UnitPointer->VisibleInFog);
				else if(label.compare(Type20[28]) == 0) Name += "TR "+FormatInt(UnitPointer->TerrainRestriction);
				else if(label.compare(Type20[29]) == 0) Name += "FM "+FormatInt(UnitPointer->FlyMode);
				else if(label.compare(Type20[30]) == 0) Name += "RC "+FormatInt(UnitPointer->ResourceCapacity);
				else if(label.compare(Type20[31]) == 0) Name += "RD "+FormatFloat(UnitPointer->ResourceDecay);
				else if(label.compare(Type20[32]) == 0) Name += "BA "+FormatInt(UnitPointer->BlastArmorLevel);
				else if(label.compare(Type20[33]) == 0) Name += "U2 "+FormatInt(UnitPointer->TriggerType);
				else if(label.compare(Type20[34]) == 0) Name += "IM "+FormatInt(UnitPointer->InteractionMode);
				else if(label.compare(Type20[35]) == 0) Name += "MM "+FormatInt(UnitPointer->MinimapMode);
				else if(label.compare(Type20[36]) == 0) Name += "CA "+FormatInt(UnitPointer->CommandAttribute);
				else if(label.compare(Type20[37]) == 0) Name += "U3A "+FormatFloat(UnitPointer->Unknown3A);
				else if(label.compare(Type20[38]) == 0) Name += "MC "+FormatInt(UnitPointer->MinimapColor);
				else if(label.compare(Type20[39]) == 0) Name += "LH "+FormatInt(UnitPointer->LanguageDLLHelp);
				else if(label.compare(Type20[40]) == 0) Name += "LT "+FormatInt(UnitPointer->LanguageDLLHotKeyText);
				else if(label.compare(Type20[41]) == 0) Name += "HK "+FormatInt(UnitPointer->HotKey);
				else if(label.compare(Type20[42]) == 0) Name += "US "+FormatInt(UnitPointer->Unselectable);
				else if(label.compare(Type20[43]) == 0) Name += "U6 "+FormatInt(UnitPointer->Unknown6);
				else if(label.compare(Type20[44]) == 0) Name += "U7 "+FormatInt(UnitPointer->UnknownSelectionMode);
				else if(label.compare(Type20[45]) == 0) Name += "U8 "+FormatInt(UnitPointer->Unknown8);
				else if(label.compare(Type20[46]) == 0) Name += "SM "+FormatInt(UnitPointer->SelectionMask);
				else if(label.compare(Type20[47]) == 0) Name += "ST "+FormatInt(UnitPointer->SelectionShapeType);
				else if(label.compare(Type20[48]) == 0) Name += "SSh "+FormatInt(UnitPointer->SelectionShape);
				else if(label.compare(Type20[49]) == 0) Name += "A "+FormatInt(UnitPointer->Attribute);
				else if(label.compare(Type20[50]) == 0) Name += "Ci "+FormatInt(UnitPointer->Civilization);
				else if(label.compare(Type20[51]) == 0) Name += "No "+FormatInt(UnitPointer->Nothing);
				else if(label.compare(Type20[52]) == 0) Name += "SE "+FormatInt(UnitPointer->SelectionEffect);
				else if(label.compare(Type20[53]) == 0) Name += "EC "+FormatInt(UnitPointer->EditorSelectionColour);
				else if(label.compare(Type20[54]) == 0) Name += "SS "+FormatInt(UnitPointer->SelectionRadius.first)+" "+FormatInt(UnitPointer->SelectionRadius.second);
				else if(label.compare(Type20[55]) == 0) Name += "B2 "+FormatFloat(UnitPointer->HPBarHeight2);
				else if(label.compare(Type20[56]) == 0) Name += "Ask Tapsa";
				else if(label.compare(Type20[57]) == 0) Name += "DC "+FormatInt(UnitPointer->DamageGraphics.size());
				else if(label.compare(Type20[58]) == 0) Name += "Ask Tapsa";
				else if(label.compare(Type20[59]) == 0) Name += "SSo "+FormatInt(UnitPointer->SelectionSound);
				else if(label.compare(Type20[60]) == 0) Name += "DS "+FormatInt(UnitPointer->DyingSound);
				else if(label.compare(Type20[61]) == 0) Name += "AtM "+FormatInt(UnitPointer->AttackMode);
				else if(label.compare(Type20[62]) == 0) Name += "EM "+FormatInt(UnitPointer->EdibleMeat);
				else if(label.compare(Type20[63]) == 0) Name += UnitPointer->Name;
				else if(label.compare(Type20[64]) == 0) Name += "NL2 "+FormatInt(UnitPointer->NameLength2);
				else if(label.compare(Type20[65]) == 0) Name += UnitPointer->Name2;
				else if(label.compare(Type20[66]) == 0) Name += "UL "+FormatInt(UnitPointer->Unitline);
				else if(label.compare(Type20[67]) == 0) Name += "MT "+FormatInt(UnitPointer->MinTechLevel);
				else if(label.compare(Type20[68]) == 0) Name += "I2 "+FormatInt(UnitPointer->ID2);
				else if(label.compare(Type20[69]) == 0) Name += "I3 "+FormatInt(UnitPointer->ID3);
				else if(label.compare(Type20[70]) == 0) Name += "S "+FormatFloat(UnitPointer->Speed);
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 1: // Type30
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type30[0]) == 0) Name += "WG "+FormatInt(UnitPointer->DeadFish.WalkingGraphic.first)+" "+FormatInt(UnitPointer->DeadFish.WalkingGraphic.second);
				else if(label.compare(Type30[1]) == 0) Name += "RS "+FormatFloat(UnitPointer->DeadFish.RotationSpeed);
				else if(label.compare(Type30[2]) == 0) Name += "U11 "+FormatInt(UnitPointer->DeadFish.Unknown11);
				else if(label.compare(Type30[3]) == 0) Name += "TU "+FormatInt(UnitPointer->DeadFish.TrackingUnit);
				else if(label.compare(Type30[4]) == 0) Name += "UU "+FormatInt(UnitPointer->DeadFish.TrackingUnitUsed);
				else if(label.compare(Type30[5]) == 0) Name += "UD "+FormatFloat(UnitPointer->DeadFish.TrackingUnitDensity);
				else if(label.compare(Type30[6]) == 0) Name += "U16 "+FormatInt(UnitPointer->DeadFish.Unknown16);
				else if(label.compare(Type30[7]) == 0)
				{
					Name += "a"+FormatFloat(UnitPointer->DeadFish.RotationAngles[0]);
					Name += " b"+FormatFloat(UnitPointer->DeadFish.RotationAngles[1]);
					Name += " c"+FormatFloat(UnitPointer->DeadFish.RotationAngles[2]);
					Name += " d"+FormatFloat(UnitPointer->DeadFish.RotationAngles[3]);
					Name += " e"+FormatFloat(UnitPointer->DeadFish.RotationAngles[4]);
				}
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 2: // Type40
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type40[0]) == 0) Name += "SC "+FormatInt(UnitPointer->Bird.SheepConversion);
				else if(label.compare(Type40[1]) == 0) Name += "SR "+FormatFloat(UnitPointer->Bird.SearchRadius);
				else if(label.compare(Type40[2]) == 0) Name += "WR "+FormatFloat(UnitPointer->Bird.WorkRate);
				else if(label.compare(Type40[3]) == 0) Name += "DS "+FormatInt(UnitPointer->Bird.DropSite.first)+" "+FormatInt(UnitPointer->Bird.DropSite.second);
				else if(label.compare(Type40[4]) == 0) Name += "VM "+FormatInt(UnitPointer->Bird.VillagerMode);
				else if(label.compare(Type40[5]) == 0) Name += "AS "+FormatInt(UnitPointer->Bird.AttackSound);
				else if(label.compare(Type40[6]) == 0) Name += "MS "+FormatInt(UnitPointer->Bird.MoveSound);
				else if(label.compare(Type40[7]) == 0) Name += "AM "+FormatInt(UnitPointer->Bird.AnimalMode);
				else if(label.compare(Type40[8]) == 0) Name += "CC "+FormatInt(UnitPointer->Bird.Commands.size());
				else if(label.compare(Type40[9]) == 0) Name += "Ask Tapsa";
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 3: // Type50
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type50[0]) == 0) Name += "DA "+FormatInt(UnitPointer->Type50.DefaultArmor);
				else if(label.compare(Type50[1]) == 0) Name += "AtC "+FormatInt(UnitPointer->Type50.Attacks.size());
				else if(label.compare(Type50[2]) == 0) for(short i = 0; i < UnitPointer->Type50.Attacks.size(); ++i)
				Name += "c" + FormatInt(UnitPointer->Type50.Attacks[i].Class) + " ";
				else if(label.compare(Type50[3]) == 0) Name += "ArC "+FormatInt(UnitPointer->Type50.Armours.size());
				else if(label.compare(Type50[4]) == 0) for(short i = 0; i < UnitPointer->Type50.Armours.size(); ++i)
				Name += "c" + FormatInt(UnitPointer->Type50.Armours[i].Class) + " ";
				else if(label.compare(Type50[5]) == 0) Name += "TR "+FormatInt(UnitPointer->Type50.TerRestrictionForDmgMultiplying);
				else if(label.compare(Type50[6]) == 0) Name += "MaR "+FormatFloat(UnitPointer->Type50.MaxRange);
				else if(label.compare(Type50[7]) == 0) Name += "BR "+FormatFloat(UnitPointer->Type50.BlastRadius);
				else if(label.compare(Type50[8]) == 0) Name += "RT "+FormatFloat(UnitPointer->Type50.ReloadTime);
				else if(label.compare(Type50[9]) == 0) Name += "PU "+FormatInt(UnitPointer->Type50.ProjectileUnitID);
				else if(label.compare(Type50[10]) == 0) Name += "AP "+FormatInt(UnitPointer->Type50.AccuracyPercent);
				else if(label.compare(Type50[11]) == 0) Name += "TM "+FormatInt(UnitPointer->Type50.TowerMode);
				else if(label.compare(Type50[12]) == 0) Name += "D "+FormatInt(UnitPointer->Type50.FrameDelay);
				else if(label.compare(Type50[13]) == 0)
				{
					Name += "x"+FormatInt(UnitPointer->Type50.GraphicDisplacement[0]);
					Name += " y"+FormatInt(UnitPointer->Type50.GraphicDisplacement[1]);
					Name += " z"+FormatInt(UnitPointer->Type50.GraphicDisplacement[2]);
				}
				else if(label.compare(Type50[14]) == 0) Name += "BL "+FormatInt(UnitPointer->Type50.BlastAttackLevel);
				else if(label.compare(Type50[15]) == 0) Name += "MiR "+FormatFloat(UnitPointer->Type50.MinRange);
				else if(label.compare(Type50[16]) == 0) Name += "AE "+FormatFloat(UnitPointer->Type50.AccuracyErrorRadius);
				else if(label.compare(Type50[17]) == 0) Name += "AG "+FormatInt(UnitPointer->Type50.AttackGraphic);
				else if(label.compare(Type50[18]) == 0) Name += "DM "+FormatInt(UnitPointer->Type50.DisplayedMeleeArmour);
				else if(label.compare(Type50[19]) == 0) Name += "DP "+FormatInt(UnitPointer->Type50.DisplayedAttack);
				else if(label.compare(Type50[20]) == 0) Name += "DR "+FormatFloat(UnitPointer->Type50.DisplayedRange);
				else if(label.compare(Type50[21]) == 0) Name += "DT "+FormatFloat(UnitPointer->Type50.DisplayedReloadTime);
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 4: // Type60
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type60[0]) == 0) Name += "SM "+FormatInt(UnitPointer->Projectile.StretchMode);
				else if(label.compare(Type60[1]) == 0) Name += "CM "+FormatInt(UnitPointer->Projectile.CompensationMode);
				else if(label.compare(Type60[2]) == 0) Name += "DA "+FormatInt(UnitPointer->Projectile.DropAnimationMode);
				else if(label.compare(Type60[3]) == 0) Name += "PM "+FormatInt(UnitPointer->Projectile.PenetrationMode);
				else if(label.compare(Type60[4]) == 0) Name += "U24 "+FormatInt(UnitPointer->Projectile.Unknown24);
				else if(label.compare(Type60[5]) == 0) Name += "PA "+FormatFloat(UnitPointer->Projectile.ProjectileArc);
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 5: // Type70
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type70[0]) == 0) Name += "Ask Tapsa";
				else if(label.compare(Type70[1]) == 0) Name += "TT "+FormatInt(UnitPointer->Creatable.TrainTime);
				else if(label.compare(Type70[2]) == 0) Name += "TL "+FormatInt(UnitPointer->Creatable.TrainLocationID);
				else if(label.compare(Type70[3]) == 0) Name += "B "+FormatInt(UnitPointer->Creatable.ButtonID);
				else if(label.compare(Type70[4]) == 0) Name += "U26 "+FormatInt(UnitPointer->Creatable.Unknown26);
				else if(label.compare(Type70[5]) == 0) Name += "U27 "+FormatInt(UnitPointer->Creatable.Unknown27);
				else if(label.compare(Type70[6]) == 0) Name += "U28 "+FormatInt(UnitPointer->Creatable.Unknown28);
				else if(label.compare(Type70[7]) == 0) Name += "HM "+FormatInt(UnitPointer->Creatable.HeroMode);
				else if(label.compare(Type70[8]) == 0) Name += "GG "+FormatInt(UnitPointer->Creatable.GarrisonGraphic);
				else if(label.compare(Type70[9]) == 0) Name += "Di "+FormatFloat(UnitPointer->Creatable.TotalMissiles);
				else if(label.compare(Type70[10]) == 0) Name += "Da "+FormatInt(UnitPointer->Creatable.TotalMissilesMax);
				else if(label.compare(Type70[11]) == 0)
				{
					Name += "x"+FormatInt(UnitPointer->Creatable.MissileSpawningArea[0]);
					Name += " y"+FormatInt(UnitPointer->Creatable.MissileSpawningArea[1]);
					Name += " z"+FormatInt(UnitPointer->Creatable.MissileSpawningArea[2]);
				}
				else if(label.compare(Type70[12]) == 0) Name += "AP "+FormatInt(UnitPointer->Creatable.AlternativeProjectileUnit);
				else if(label.compare(Type70[13]) == 0) Name += "CG "+FormatInt(UnitPointer->Creatable.ChargingGraphic);
				else if(label.compare(Type70[14]) == 0) Name += "CM "+FormatInt(UnitPointer->Creatable.ChargingMode);
				else if(label.compare(Type70[15]) == 0) Name += "DP "+FormatInt(UnitPointer->Creatable.DisplayedPierceArmour);
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
			case 6: // Type80
			for(short loop = 0; loop < filters; ++loop)
			{
				wxString label = Units_SearchFilters[loop]->GetString(Selection[loop]);
				if(label.compare(Type80[0]) == 0) Name += "CG "+FormatInt(UnitPointer->Building.ConstructionGraphicID);
				else if(label.compare(Type80[1]) == 0) Name += "SG "+FormatInt(UnitPointer->Building.SnowGraphicID);
				else if(label.compare(Type80[2]) == 0) Name += "AM "+FormatInt(UnitPointer->Building.AdjacentMode);
				else if(label.compare(Type80[3]) == 0) Name += "GA "+FormatInt(UnitPointer->Building.GraphicsAngle);
				else if(label.compare(Type80[4]) == 0) Name += "DB "+FormatInt(UnitPointer->Building.DisappearsWhenBuilt);
				else if(label.compare(Type80[5]) == 0) Name += "SU "+FormatInt(UnitPointer->Building.StackUnitID);
				else if(label.compare(Type80[6]) == 0) Name += "FT "+FormatInt(UnitPointer->Building.FoundationTerrainID);
				else if(label.compare(Type80[7]) == 0) Name += "OT "+FormatInt(UnitPointer->Building.OldTerrainLikeID);
				else if(label.compare(Type80[8]) == 0) Name += "R "+FormatInt(UnitPointer->Building.ResearchID);
				else if(label.compare(Type80[9]) == 0) Name += "U33 "+FormatInt(UnitPointer->Building.Unknown33);
				else if(label.compare(Type80[10]) == 0) Name += "Ask Tapsa";
				else if(label.compare(Type80[11]) == 0) Name += "HU "+FormatInt(UnitPointer->Building.HeadUnit);
				else if(label.compare(Type80[12]) == 0) Name += "TU "+FormatInt(UnitPointer->Building.TransformUnit);
				else if(label.compare(Type80[13]) == 0) Name += "US "+FormatInt(UnitPointer->Building.UnknownSound);
				else if(label.compare(Type80[14]) == 0) Name += "CS "+FormatInt(UnitPointer->Building.ConstructionSound);
				else if(label.compare(Type80[15]) == 0) Name += "GT "+FormatInt(UnitPointer->Building.GarrisonType);
				else if(label.compare(Type80[16]) == 0) Name += "GH "+FormatFloat(UnitPointer->Building.GarrisonHealRate);
				else if(label.compare(Type80[17]) == 0) Name += "U35 "+FormatFloat(UnitPointer->Building.Unknown35);
				else if(label.compare(Type80[18]) == 0) Name += "PU "+FormatInt(UnitPointer->Building.PileUnit);
				else if(label.compare(Type80[19]) == 0) Name += "Ask Tapsa";
				Name += ", ";
				if(Selection[1] == 0) break;
			}
			break;
		}
	}

//Names:
	if(!LangDLLstring(dataset->Civs[civ].Units[Index].LanguageDLLName, 2).empty())
	{
		return Name + LangDLLstring(dataset->Civs[civ].Units[Index].LanguageDLLName, 64);
	}
//InternalName:
	if(!dataset->Civs[civ].Units[Index].Name.empty())
	{
		return Name + dataset->Civs[civ].Units[Index].Name;
	}
	return Name + "New Unit";
}

void AGE_Frame::OnUnitsSearch(wxCommandEvent &event)
{
	short Selection = Units_Civs_List->GetSelection();
	if(Selection == wxNOT_FOUND) return;

	How2List = SEARCH;
	ListUnits(Selection, false);
}

void AGE_Frame::ListUnits(short civ, bool all)
{
	InitUnits(civ, all);
	wxTimerEvent E;
	OnUnitsTimer(E);
}

void AGE_Frame::InitUnits(short civ, bool all)
{
	searchText = Units_Search->GetValue().Lower();
	excludeText = Units_Search_R->GetValue().Lower();
	for(short loop = 0; loop < 2; ++loop)
	useAnd[loop] = Units_UseAnd[loop]->GetValue();

	Units_Civs_List->SetSelection(civ);

    Units_ListV->names.clear();
    Units_ListV->indexes.clear();
	if(all)
	{
		AGE_AreaTT84::units.Clear();
		AGE_AreaTT84::units.Alloc(dataset->Civs[0].Units.size());
	}

	short matcher = genie::UT_Trees;
	switch(Units_FilterSelector->GetSelection())
	{
		case 0: matcher = genie::UT_25; break;
		case 1: matcher = genie::UT_Dead_Fish; break;
		case 2: matcher = genie::UT_Bird; break;
		case 3: matcher = genie::UT_Unknown; break;
		case 4: matcher = genie::UT_Projectile; break;
		case 5: matcher = genie::UT_Creatable; break;
		case 6: matcher = genie::UT_Building; break;
	}
	for(short loop = 0; loop < dataset->Civs[civ].Units.size(); ++loop)
	{
		if(all) AGE_AreaTT84::units.Add(" "+FormatInt(loop)+" - "+GetUnitName(loop, 0));
		if(matcher > genie::UT_25)
		{
			if(matcher == genie::UT_Projectile)
			if(dataset->Civs[civ].Units[loop].Type != genie::UT_Projectile) continue;
			if(dataset->Civs[civ].Units[loop].Type < matcher) continue;
			if(dataset->Civs[civ].Units[loop].Type == genie::UT_AoeTrees) continue;
		}
		wxString Name = " "+FormatInt(loop)+" - "+GetUnitName(loop, civ, true)+" ";
		if(SearchMatches(Name.Lower()))
		{
			Units_ListV->names.Add(Name);
            Units_ListV->indexes.push_back(loop);
		}
	}

    virtualListing(Units_ListV);
	if(all)
	{
		FillLists(UnitComboBoxList, AGE_AreaTT84::units);
		if(GenieVersion >= genie::GV_AoKA)
		{
			TechTrees_Ages_Items.FillItemCombo(TechTrees_Ages_Items.ItemCombo->GetSelection(), true);
			TechTrees_Buildings_Items.FillItemCombo(TechTrees_Buildings_Items.ItemCombo->GetSelection(), true);
			TechTrees_Units_Items.FillItemCombo(TechTrees_Units_Items.ItemCombo->GetSelection(), true);
			TechTrees_Researches_Items.FillItemCombo(TechTrees_Researches_Items.ItemCombo->GetSelection(), true);
		}
	}

	for(short loop = 0; loop < 2; ++loop)
	useAnd[loop] = false;
}

void AGE_Frame::OnChooseGraphic(wxCommandEvent &event)
{
    unitSLP.slpID = -2;
    if(NULL != slpwindow) slpview->Refresh();
}

void AGE_Frame::OnUnitsSelect(wxCommandEvent &event)
{
    if(!unitTimer.IsRunning())
        unitTimer.Start(150);
}

//	This links data into user interface
void AGE_Frame::OnUnitsTimer(wxTimerEvent &event)
{
    unitTimer.Stop();
	auto selections = Units_ListV->GetSelectedItemCount();

	wxBusyCursor WaitCursor;
    getSelectedItems(selections, Units_ListV, UnitIDs);
	UnitCivID = Units_Civs_List->GetSelection();

	// Auto-copy stuff
	SelectedCivs.resize(1);
	SelectedCivs[0] = UnitCivID;
	if(AutoCopy)
	{
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			// Counts all selected civs and always the one being edited.
			if(Units_CivBoxes[civ]->IsChecked() && civ != UnitCivID)
				SelectedCivs.push_back(civ);
		}
	}

    for(auto &box: uiGroupUnit) box->clear();

	short unitType = -1;
	genie::Unit * UnitPointer = NULL;
	for(auto sel = selections; sel--> 0;)
	{
        unitType = -1;
		// This makes auto-copy automatic.
		for(short vecCiv = SelectedCivs.size(); vecCiv--> 0;)
		{
			if(dataset->Civs[SelectedCivs[vecCiv]].UnitPointers[UnitIDs[sel]] == 0) continue;
            UnitCivID = SelectedCivs[vecCiv];
			UnitPointer = &dataset->Civs[UnitCivID].Units[UnitIDs[sel]];
			unitType = (short)UnitPointer->Type;
			// Assing data to editing boxes
			switch(unitType)
			{
				case 80:
				{
					if(CopyGraphics || vecCiv == 0)
					Units_ConstructionGraphicID->prepend(&UnitPointer->Building.ConstructionGraphicID);
					Units_AdjacentMode->prepend(&UnitPointer->Building.AdjacentMode);
					Units_IconAngle->prepend(&UnitPointer->Building.GraphicsAngle);
					Units_DisappearsWhenBuilt->prepend(&UnitPointer->Building.DisappearsWhenBuilt);
					Units_StackUnitID->prepend(&UnitPointer->Building.StackUnitID);
					Units_TerrainID->prepend(&UnitPointer->Building.FoundationTerrainID);
					Units_OldTerrainLikeID->prepend(&UnitPointer->Building.OldTerrainLikeID);
					Units_ResearchID->prepend(&UnitPointer->Building.ResearchID);
					if(GenieVersion >= genie::GV_AoKA)
					{
						if(GenieVersion >= genie::GV_TC)
						{
							if(CopyGraphics || vecCiv == 0)
							Units_SnowGraphicID->prepend(&UnitPointer->Building.SnowGraphicID);
						}
						Units_Unknown33->prepend(&UnitPointer->Building.Unknown33);
						for(short loop = 0; loop < 4; ++loop)
						{
							Units_AnnexUnit[loop]->prepend(&UnitPointer->Building.Annexes[loop].UnitID);
							Units_AnnexUnitMisplacement[loop][0]->prepend(&UnitPointer->Building.Annexes[loop].Misplacement.first);
							Units_AnnexUnitMisplacement[loop][1]->prepend(&UnitPointer->Building.Annexes[loop].Misplacement.second);
						}
						Units_HeadUnit->prepend(&UnitPointer->Building.HeadUnit);
						Units_TransformUnit->prepend(&UnitPointer->Building.TransformUnit);
						Units_UnknownSound->prepend(&UnitPointer->Building.UnknownSound);
						Units_GarrisonType->prepend(&UnitPointer->Building.GarrisonType);
						Units_GarrisonHealRate->prepend(&UnitPointer->Building.GarrisonHealRate);
						Units_Unknown35->prepend(&UnitPointer->Building.Unknown35);
						Units_PileUnit->prepend(&UnitPointer->Building.PileUnit);
						for(short loop = 0; loop < Units_LootSwitch.size(); ++loop)
						Units_LootSwitch[loop]->prepend(&UnitPointer->Building.LootingTable[loop]);
					}
					Units_ConstructionSound->prepend(&UnitPointer->Building.ConstructionSound);
				}
				case 70:
				{
					for(short loop = 0; loop < 3; ++loop)
					{
						Units_CostType[loop]->prepend(&UnitPointer->Creatable.ResourceCosts[loop].Type);
						Units_CostAmount[loop]->prepend(&UnitPointer->Creatable.ResourceCosts[loop].Amount);
						Units_CostUsed[loop]->prepend(&UnitPointer->Creatable.ResourceCosts[loop].Enabled);
					}
					Units_TrainTime->prepend(&UnitPointer->Creatable.TrainTime);
					Units_TrainLocationID->prepend(&UnitPointer->Creatable.TrainLocationID);
					Units_ButtonID->prepend(&UnitPointer->Creatable.ButtonID);
					if(GenieVersion >= genie::GV_AoKA)
					{
						Units_Unknown26->prepend(&UnitPointer->Creatable.Unknown26);
						Units_Unknown27->prepend(&UnitPointer->Creatable.Unknown27);
						Units_Unknown28->prepend(&UnitPointer->Creatable.Unknown28);
						if(GenieVersion >= genie::GV_AoKB)
						{
							Units_HeroMode->prepend(&UnitPointer->Creatable.HeroMode);
							if(CopyGraphics || vecCiv == 0)
							{
								Units_GarrisonGraphic->prepend(&UnitPointer->Creatable.GarrisonGraphic);
							}
						}
						Units_MissileCount->prepend(&UnitPointer->Creatable.TotalMissiles);
						Units_MissileDuplicationCount->prepend(&UnitPointer->Creatable.TotalMissilesMax);
						for(short loop = 0; loop < 3; ++loop)
						{
							Units_AttackMissileDuplicationSpawning[loop]->prepend(&UnitPointer->Creatable.MissileSpawningArea[loop]);
						}
						Units_AttackMissileDuplicationUnit->prepend(&UnitPointer->Creatable.AlternativeProjectileUnit);
						Units_ChargingGraphic->prepend(&UnitPointer->Creatable.ChargingGraphic);
						Units_ChargingMode->prepend(&UnitPointer->Creatable.ChargingMode);
					}
					Units_DisplayedPierceArmour->prepend(&UnitPointer->Creatable.DisplayedPierceArmour);
				}
				case 60:
				case 50:
				{
					Units_DefaultArmor->prepend(&UnitPointer->Type50.DefaultArmor);
					Units_TerRestrictionForDmgMultiply->prepend(&UnitPointer->Type50.TerRestrictionForDmgMultiplying);
					Units_MaxRange->prepend(&UnitPointer->Type50.MaxRange);
					Units_BlastRadius->prepend(&UnitPointer->Type50.BlastRadius);
					Units_ReloadTime1->prepend(&UnitPointer->Type50.ReloadTime);
					Units_ProjectileUnitID->prepend(&UnitPointer->Type50.ProjectileUnitID);
					Units_AccuracyPercent->prepend(&UnitPointer->Type50.AccuracyPercent);
					Units_TowerMode->prepend(&UnitPointer->Type50.TowerMode);
					Units_Delay->prepend(&UnitPointer->Type50.FrameDelay);
					for(short loop = 0; loop < 3; ++loop)
					{
						Units_GraphicDisplacement[loop]->prepend(&UnitPointer->Type50.GraphicDisplacement[loop]);
					}
					Units_BlastAttackLevel->prepend(&UnitPointer->Type50.BlastAttackLevel);
					Units_MinRange->prepend(&UnitPointer->Type50.MinRange);
					if(GenieVersion >= genie::GV_AoKB)
					{
						Units_AccuracyErrorRadius->prepend(&UnitPointer->Type50.AccuracyErrorRadius);
					}
					if(CopyGraphics || vecCiv == 0)
					Units_AttackGraphic->prepend(&UnitPointer->Type50.AttackGraphic);
					Units_DisplayedMeleeArmour->prepend(&UnitPointer->Type50.DisplayedMeleeArmour);
					Units_DisplayedAttack->prepend(&UnitPointer->Type50.DisplayedAttack);
					Units_DisplayedRange->prepend(&UnitPointer->Type50.DisplayedRange);
					Units_ReloadTime2->prepend(&UnitPointer->Type50.DisplayedReloadTime);
				}
				case 40:
				{
					Units_SheepConversion->prepend(&UnitPointer->Bird.SheepConversion);
					Units_SearchRadius->prepend(&UnitPointer->Bird.SearchRadius);
					Units_WorkRate->prepend(&UnitPointer->Bird.WorkRate);
					Units_DropSite[0]->prepend(&UnitPointer->Bird.DropSite.first);
					Units_DropSite[1]->prepend(&UnitPointer->Bird.DropSite.second);
					Units_VillagerMode->prepend(&UnitPointer->Bird.VillagerMode);
					Units_AttackSound->prepend(&UnitPointer->Bird.AttackSound);
					Units_MoveSound->prepend(&UnitPointer->Bird.MoveSound);
					Units_AnimalMode->prepend(&UnitPointer->Bird.AnimalMode);
				}
				case 30:
				{
					if(CopyGraphics || vecCiv == 0)
					{
						Units_WalkingGraphic[0]->prepend(&UnitPointer->DeadFish.WalkingGraphic.first);
						Units_WalkingGraphic[1]->prepend(&UnitPointer->DeadFish.WalkingGraphic.second);
					}
					Units_RotationSpeed->prepend(&UnitPointer->DeadFish.RotationSpeed);
					Units_Unknown11->prepend(&UnitPointer->DeadFish.Unknown11);
					Units_TrackingUnit->prepend(&UnitPointer->DeadFish.TrackingUnit);
					Units_TrackingUnitUsed->prepend(&UnitPointer->DeadFish.TrackingUnitUsed);
					Units_TrackingUnitDensity->prepend(&UnitPointer->DeadFish.TrackingUnitDensity);
					Units_Unknown16->prepend(&UnitPointer->DeadFish.Unknown16);
					if(GenieVersion >= genie::GV_AoKB)
					{
						string newLabel = " ( ", aste = "� ";
						for(short loop = 0; loop < Units_RotationAngles.size(); ++loop)
						{
							int angle = UnitPointer->DeadFish.RotationAngles[loop] * 57.2957802;
							if(angle == 0x80000000) newLabel += "max" + aste;
							else newLabel += lexical_cast<string>(angle) + aste;
							Units_RotationAngles[loop]->prepend(&UnitPointer->DeadFish.RotationAngles[loop]);
						}
						Units_RotationAngles_Text->SetLabel(Units_RotationAngles_Label + newLabel + ")");
					}
				}
				case 25:
				case 20:
				{
					Units_Speed->prepend(&UnitPointer->Speed);
				}
				case 90:
				case 15:
				case 10:
                {
                    Units_Type->prepend(&UnitPointer->Type);
                    Units_ID1->prepend(&UnitPointer->ID1);
                    Units_LanguageDLLName->prepend(&UnitPointer->LanguageDLLName);
                    Units_LanguageDLLCreation->prepend(&UnitPointer->LanguageDLLCreation);
                    Units_Class->prepend(&UnitPointer->Class);
                    if(CopyGraphics || vecCiv == 0)
                    {
                        Units_StandingGraphic[0]->prepend(&UnitPointer->StandingGraphic.first);
                        Units_DyingGraphic[0]->prepend(&UnitPointer->DyingGraphic.first);
                        Units_DyingGraphic[1]->prepend(&UnitPointer->DyingGraphic.second);
                        Units_IconID->prepend(&UnitPointer->IconID);
                    }
                    Units_DeathMode->prepend(&UnitPointer->DeathMode);
                    Units_HitPoints->prepend(&UnitPointer->HitPoints);
                    Units_LineOfSight->prepend(&UnitPointer->LineOfSight);
                    Units_GarrisonCapacity->prepend(&UnitPointer->GarrisonCapacity);
                    Units_SizeRadius[0]->prepend(&UnitPointer->SizeRadius.first);
                    Units_SizeRadius[1]->prepend(&UnitPointer->SizeRadius.second);
                    Units_HPBarHeight1->prepend(&UnitPointer->HPBarHeight1);
                    Units_TrainSound[0]->prepend(&UnitPointer->TrainSound.first);
                    Units_DeadUnitID->prepend(&UnitPointer->DeadUnitID);
                    Units_PlacementMode->prepend(&UnitPointer->PlacementMode);
                    Units_AirMode->prepend(&UnitPointer->AirMode);
                    Units_HideInEditor->prepend(&UnitPointer->HideInEditor);
                    Units_Unknown1->prepend(&UnitPointer->Unknown1);
                    Units_PlacementBypassTerrain[0]->prepend(&UnitPointer->PlacementBypassTerrain.first);
                    Units_PlacementBypassTerrain[1]->prepend(&UnitPointer->PlacementBypassTerrain.second);
                    Units_PlacementTerrain[0]->prepend(&UnitPointer->PlacementTerrain.first);
                    Units_PlacementTerrain[1]->prepend(&UnitPointer->PlacementTerrain.second);
                    Units_EditorRadius[0]->prepend(&UnitPointer->EditorRadius.first);
                    Units_EditorRadius[1]->prepend(&UnitPointer->EditorRadius.second);
                    Units_HillMode->prepend(&UnitPointer->HillMode);
                    Units_VisibleInFog->prepend(&UnitPointer->VisibleInFog);
                    Units_TerrainRestriction->prepend(&UnitPointer->TerrainRestriction);
                    Units_FlyMode->prepend(&UnitPointer->FlyMode);
                    Units_ResourceCapacity->prepend(&UnitPointer->ResourceCapacity);
                    Units_ResourceDecay->prepend(&UnitPointer->ResourceDecay);
                    Units_BlastArmorLevel->prepend(&UnitPointer->BlastArmorLevel);
                    Units_TriggerType->prepend(&UnitPointer->TriggerType);
                    Units_InteractionMode->prepend(&UnitPointer->InteractionMode);
                    Units_MinimapMode->prepend(&UnitPointer->MinimapMode);
                    Units_SelectionEffect->prepend(&UnitPointer->SelectionEffect);
                    Units_EditorSelectionColour->prepend(&UnitPointer->EditorSelectionColour);
                    if(GenieVersion >= genie::GV_AoKA)
                    {
                        Units_TrainSound[1]->prepend(&UnitPointer->TrainSound.second);
                        Units_SelectionMask->prepend(&UnitPointer->SelectionMask);
                        Units_SelectionShapeType->prepend(&UnitPointer->SelectionShapeType);
                        Units_SelectionShape->prepend(&UnitPointer->SelectionShape);
                        Units_ID3->prepend(&UnitPointer->ID3);
                        if(GenieVersion >= genie::GV_AoKB)
                        {
                            if(CopyGraphics || vecCiv == 0)
                            Units_StandingGraphic[1]->prepend(&UnitPointer->StandingGraphic.second);
                            if(GenieVersion >= genie::GV_AoK)
                            {
                                Units_Disabled->prepend(&UnitPointer->Disabled);
                                if(GenieVersion >= genie::GV_TC)
                                {
                                    Units_Attribute->prepend(&UnitPointer->Attribute);
                                    Units_Civ->prepend(&UnitPointer->Civilization);
                                    Units_Unknown9->prepend(&UnitPointer->Nothing);
                                    if(GenieVersion >= genie::GV_SWGB)
                                    {
                                        Units_Name2->prepend(&UnitPointer->Name2);
                                        Units_Unitline->prepend(&UnitPointer->Unitline);
                                        Units_MinTechLevel->prepend(&UnitPointer->MinTechLevel);
                                    }
                                }
                            }
                        }
                    }
                    Units_Enabled->prepend(&UnitPointer->Enabled);
                    Units_CommandID->prepend(&UnitPointer->CommandAttribute);
                    Units_Unknown3A->prepend(&UnitPointer->Unknown3A);
                    Units_MinimapColor->prepend(&UnitPointer->MinimapColor);
                    Units_LanguageDLLHelp->prepend(&UnitPointer->LanguageDLLHelp);
                    Units_LanguageDLLHotKeyText->prepend(&UnitPointer->LanguageDLLHotKeyText);
                    Units_HotKey->prepend(&UnitPointer->HotKey);
                    Units_Unselectable->prepend(&UnitPointer->Unselectable);
                    Units_Unknown6->prepend(&UnitPointer->Unknown6);
                    Units_Unknown7->prepend(&UnitPointer->UnknownSelectionMode);
                    Units_Unknown8->prepend(&UnitPointer->Unknown8);
                    Units_SelectionRadius[0]->prepend(&UnitPointer->SelectionRadius.first);
                    Units_SelectionRadius[1]->prepend(&UnitPointer->SelectionRadius.second);
                    Units_HPBarHeight2->prepend(&UnitPointer->HPBarHeight2);
                    Units_SelectionSound->prepend(&UnitPointer->SelectionSound);
                    Units_DyingSound->prepend(&UnitPointer->DyingSound);
                    Units_AttackMode->prepend(&UnitPointer->AttackMode);
                    Units_EdibleMeat->prepend(&UnitPointer->EdibleMeat);
                    Units_Name->prepend(&UnitPointer->Name);
                    Units_ID2->prepend(&UnitPointer->ID2);
                    for(short loop = 0; loop < 3; ++loop)
                    {
                        ResourceStorage_Type[loop]->prepend(&UnitPointer->ResourceStorages[loop].Type);
                        ResourceStorage_Amount[loop]->prepend(&UnitPointer->ResourceStorages[loop].Amount);
                        ResourceStorage_Enabled[loop]->prepend(&UnitPointer->ResourceStorages[loop].Enabled);
                    }
                }
			}
			if(unitType == 60)
			{
				Units_StretchMode->prepend(&UnitPointer->Projectile.StretchMode);
				Units_CompensationMode->prepend(&UnitPointer->Projectile.CompensationMode);
				Units_DropAnimationMode->prepend(&UnitPointer->Projectile.DropAnimationMode);
				Units_PenetrationMode->prepend(&UnitPointer->Projectile.PenetrationMode);
				Units_Unknown24->prepend(&UnitPointer->Projectile.Unknown24);
				Units_ProjectileArc->prepend(&UnitPointer->Projectile.ProjectileArc);
			}
		}
	}
	SetStatusText("Civilization: "+lexical_cast<string>(UnitCivID)+"    Selections: "+lexical_cast<string>(selections)+"    Selected unit: "+lexical_cast<string>(UnitIDs[0]), 0);

    bool showUnitData = -1 != unitType;
	switch(unitType)
	{
		case 10: Units_Type_ComboBox->SetSelection(1); break;
		case 15: Units_Type_ComboBox->SetSelection(2); break;
		case 20: Units_Type_ComboBox->SetSelection(3); break;
		case 25: Units_Type_ComboBox->SetSelection(4); break;
		case 30: Units_Type_ComboBox->SetSelection(5); break;
		case 40: Units_Type_ComboBox->SetSelection(6); break;
		case 50: Units_Type_ComboBox->SetSelection(7); break;
		case 60: Units_Type_ComboBox->SetSelection(8); break;
		case 70: Units_Type_ComboBox->SetSelection(9); break;
		case 80: Units_Type_ComboBox->SetSelection(10); break;
		case 90: Units_Type_ComboBox->SetSelection(11); break;
		default: Units_Type_ComboBox->SetSelection(0);
	}
    Units_DLL_LanguageName->index = Units_DLL_LanguageHelp->index = 5000;
    Units_DLL_LanguageCreation->index = Units_DLL_LanguageHKText->index = 6000;
    Units_DLL_HotKey4->index = 16000;
    if(NULL != UnitPointer)
    {
        if(80 == unitType)
        {
            if(GenieVersion >= genie::GV_AoKA)
            {
                Units_GarrisonType_CheckBox[0]->SetValue(UnitPointer->Building.GarrisonType & 0x01);
                Units_GarrisonType_CheckBox[1]->SetValue(UnitPointer->Building.GarrisonType & 0x02);
                Units_GarrisonType_CheckBox[2]->SetValue(UnitPointer->Building.GarrisonType & 0x04);
                Units_GarrisonType_CheckBox[3]->SetValue(UnitPointer->Building.GarrisonType & 0x08);
                Units_GarrisonType_CheckBox[4]->SetValue(UnitPointer->Building.GarrisonType & 0x10);
                Units_GarrisonType_CheckBox[5]->SetValue(UnitPointer->Building.GarrisonType & 0x20);
                Units_GarrisonType_CheckBox[6]->SetValue(UnitPointer->Building.GarrisonType & 0x40);
                Units_GarrisonType_CheckBox[7]->SetValue(UnitPointer->Building.GarrisonType & 0x80);
            }
        }
        else
        {
            Units_DLL_LanguageName->index = UnitPointer->LanguageDLLName;
            Units_DLL_LanguageCreation->index = UnitPointer->LanguageDLLCreation;
            if(GenieVersion >= genie::GV_AoKA)
            {
                Units_DLL_LanguageHelp->index = UnitPointer->LanguageDLLHelp - 79000;
                Units_DLL_LanguageHKText->index = UnitPointer->LanguageDLLHotKeyText - 140000;
                if(GenieVersion >= genie::GV_TC)
                {
                    Units_Attribute_CheckBox[0]->SetValue(UnitPointer->Attribute & 0x01);
                    Units_Attribute_CheckBox[1]->SetValue(UnitPointer->Attribute & 0x02);
                    Units_Attribute_CheckBox[2]->SetValue(UnitPointer->Attribute & 0x04);
                    Units_Attribute_CheckBox[3]->SetValue(UnitPointer->Attribute & 0x08);
                    Units_Attribute_CheckBox[4]->SetValue(UnitPointer->Attribute & 0x10);
                    Units_Attribute_CheckBox[5]->SetValue(UnitPointer->Attribute & 0x20);
                    Units_Attribute_CheckBox[6]->SetValue(UnitPointer->Attribute & 0x40);
                    Units_Attribute_CheckBox[7]->SetValue(UnitPointer->Attribute & 0x80);
                }
            }
            else
            {
                Units_DLL_LanguageHelp->index = (uint16_t)UnitPointer->LanguageDLLHelp;
                Units_DLL_LanguageHKText->index = (uint16_t)UnitPointer->LanguageDLLHotKeyText;
            }
            Units_DLL_HotKey4->index = UnitPointer->HotKey;
        }
        visibleUnitCiv->SetLabel(dataset->Civs[UnitCivID].Name);
        if(!palette.empty())
        {
            genie::Color minimap = palette[(uint8_t)UnitPointer->MinimapColor];
            genie::Color editorSel = palette[(uint8_t)UnitPointer->EditorSelectionColour];
            setForeAndBackColors(Units_MinimapColor, wxColour(minimap.r, minimap.g, minimap.b));
            setForeAndBackColors(Units_EditorSelectionColour, wxColour(editorSel.r, editorSel.g, editorSel.b));
        }
        if(UnitPointer->Type == 80)
        {
            int set0 = 50704;
            if(GenieVersion == genie::GV_CC) set0 = 53240;
            iconSLP.slpID = set0 + dataset->Civs[UnitCivID].IconSet;
        }
        else if(GenieVersion == genie::GV_CC)
        {
            iconSLP.slpID = 53250 + dataset->Civs[UnitCivID].IconSet;
        }
        else if(GenieVersion == genie::GV_SWGB)
        {
            iconSLP.slpID = 50733 + dataset->Civs[UnitCivID].IconSet;
        }
        else
        {
            iconSLP.slpID = 50730;
        }
        iconSLP.frameID = UnitPointer->IconID + UnitPointer->Building.GraphicsAngle; // frame
        unitSLP.datID = loadChosenGraphic(UnitPointer);
        unitSLP.slpID = -2;
	}
    else
    {
        visibleUnitCiv->SetLabel("None");
        iconSLP.slpID = unitSLP.datID = -1;
    }
    Units_DLL_LanguageName->SetLabel(LangDLLstring(Units_DLL_LanguageName->index, 64));
    Units_DLL_LanguageCreation->SetLabel(LangDLLstring(Units_DLL_LanguageCreation->index, 64));
    Units_DLL_LanguageHelp->SetLabel(LangDLLstring(Units_DLL_LanguageHelp->index, 512));
    Units_LanguageDLLConverter[0]->SetLabel(lexical_cast<string>(Units_DLL_LanguageHelp->index));
    Units_DLL_LanguageHKText->SetLabel(LangDLLstring(Units_DLL_LanguageHKText->index, 64));
    Units_LanguageDLLConverter[1]->SetLabel(lexical_cast<string>(Units_DLL_LanguageHKText->index));
    Units_DLL_HotKey4->SetLabel(LangDLLstring(Units_DLL_HotKey4->index, 16));

    Units_Type_ComboBox->Enable(showUnitData);
    Units_DLL_LanguageName->Enable(showUnitData);
    Units_DLL_LanguageCreation->Enable(showUnitData);
    Units_DLL_LanguageHelp->Enable(showUnitData);
    Units_DLL_LanguageHKText->Enable(showUnitData);
    Units_DLL_HotKey4->Enable(showUnitData);
    Units_LanguageDLLConverter[0]->Enable(showUnitData);
    Units_LanguageDLLConverter[1]->Enable(showUnitData);

	// Don't count disabled units anymore.
	for(short loop = SelectedCivs.size(); loop--> 0;)
	{
		if(dataset->Civs[SelectedCivs[loop]].UnitPointers[UnitIDs[0]] == 0)
			SelectedCivs.erase(SelectedCivs.begin() + loop);
	}

	ListUnitDamageGraphics();
	ListUnitAttacks();
	ListUnitArmors();
	if(GenieVersion >= genie::GV_AoK)	// AoK, TC, SWGB or CC
	{
		genie::UnitHeader * UnitHeadPointer;
		for(auto sel = selections; sel--> 0;)
		{
			UnitHeadPointer = &dataset->UnitHeaders[UnitIDs[sel]];

			Units_Exists->prepend(&UnitHeadPointer->Exists);
		}

		Units_UnitHeads_Name->SetLabel(" "+lexical_cast<string>(UnitIDs[0])+" - "+GetUnitName(UnitIDs[0], 0));
	}
	else	// AoE or RoR
	{
		Units_UnitHeads_Name->SetLabel("");
	}
	ListUnitCommands();

    for(auto &box: uiGroupUnit) box->update();
    Units_ID1->Enable(false);
    Units_ID2->Enable(false);
    Units_ID3->Enable(false);
	//	Refresh(); // Too much lag.
    Units_IconID_SLP->Refresh();
    if(NULL != slpwindow) slpview->Refresh();
}

void AGE_Frame::OnDrawIconSLP(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(Units_IconID_SLP);
    dc.Clear();
    if(iconSLP.slpID == -1)
    {
        dc.DrawLabel("No unit", wxNullBitmap, wxRect(0, 0, 100, 40));
        return;
    }
    if(iconSLP.frameID == -1)
    {
        dc.DrawLabel("No icon", wxNullBitmap, wxRect(0, 0, 100, 40));
        return;
    }
    SLPtoBitMap(&iconSLP);
    if(iconSLP.bitmap.IsOk())
    dc.DrawBitmap(iconSLP.bitmap, 0, 0, true);
    else dc.DrawLabel("!SLP/frame " + FormatInt(iconSLP.slpID), wxNullBitmap, wxRect(0, 0, 100, 40));
}

int AGE_Frame::loadChosenGraphic(genie::Unit *unit)
{
    switch(slpradio->GetSelection())
    {
        case 0: return unit->StandingGraphic.first;
        case 1: return unit->StandingGraphic.second;
        case 2: return unit->DyingGraphic.first;
        case 3: return unit->DyingGraphic.second;
        case 4: return unit->DeadFish.WalkingGraphic.first;
        case 5: return unit->DeadFish.WalkingGraphic.second;
        case 6: return unit->Building.SnowGraphicID;
        case 7: return unit->Building.ConstructionGraphicID;
        case 8: return unit->Type50.AttackGraphic;
        case 9: return unit->Creatable.GarrisonGraphic;
        default: return -1;
    }
}

void AGE_Frame::AddAnnexAndStackGraphics(unsigned int unitID, int offsetX, int offsetY, bool dmg)
{
    if(unitID >= dataset->Civs[UnitCivID].Units.size()) return;
    unsigned int unitGraphic;
    if(dmg)
    {
        if(DamageGraphicIDs.size() && DamageGraphicIDs[0] < dataset->Civs[UnitCivID].Units[unitID].DamageGraphics.size())
        {
            unitGraphic = dataset->Civs[UnitCivID].Units[unitID].DamageGraphics[DamageGraphicIDs[0]].GraphicID;
            if(dataset->Civs[UnitCivID].Units[unitID].DamageGraphics[DamageGraphicIDs[0]].ApplyMode == 2)
            unitSLP.deltas.clear();
        }
        else return;
    }
    else unitGraphic = loadChosenGraphic(&dataset->Civs[UnitCivID].Units[unitID]);
    if(unitGraphic >= dataset->Graphics.size()) return;
    unitSLP.frameID = 0;
    unitSLP.datID = unitGraphic;
    unitSLP.filename = dataset->Graphics[unitGraphic].Name2;
    unitSLP.slpID = dataset->Graphics[unitGraphic].SLP;
    if(dataset->Graphics[unitGraphic].Deltas.size())
    for(auto &delta: dataset->Graphics[unitGraphic].Deltas)
    {
        AGE_SLP deltaSLP;
        if(delta.GraphicID < dataset->Graphics.size())
        {
            deltaSLP.datID = delta.GraphicID;
            deltaSLP.filename = dataset->Graphics[delta.GraphicID].Name2;
            deltaSLP.slpID = dataset->Graphics[delta.GraphicID].SLP;
        }
        else
        {
            deltaSLP = unitSLP;
        }
        deltaSLP.xdelta = delta.DirectionX + offsetX;
        deltaSLP.ydelta = delta.DirectionY + offsetY;
        unitSLP.deltas.insert(make_pair(offsetY, deltaSLP));
    }
    else
    {
        unitSLP.xdelta = offsetX;
        unitSLP.ydelta = offsetY;
        unitSLP.deltas.insert(make_pair(offsetY, unitSLP));
    }
}

void AGE_Frame::CalcAnnexCoords(genie::unit::BuildingAnnex *annex)
{
    float offsetX = dataset->TerrainBlock.TileHalfWidth * (annex->Misplacement.first - -annex->Misplacement.second);
    float offsetY = dataset->TerrainBlock.TileHalfHeight * (-annex->Misplacement.first - -annex->Misplacement.second);
    AddAnnexAndStackGraphics(annex->UnitID, offsetX, offsetY);
}

void AGE_Frame::OnUnitAnim(wxTimerEvent &event)
{
    unitAnimTimer.Stop();
    if(NULL != slpwindow)
    {
        if(slpview->IsShownOnScreen())
        slpview->Refresh();
        else unitAnimTimer.Start(1000);
    }
}

void AGE_Frame::OnUnitsAdd(wxCommandEvent &event)
{
	if(NULL == dataset) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)	// AoK, TC, SWGB or CC
	{
		genie::UnitHeader Temp1;
		Temp1.setGameVersion(GenieVersion);
		dataset->UnitHeaders.push_back(Temp1);
	}

	genie::Unit Temp2;
	Temp2.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		dataset->Civs[loop].Units.push_back(Temp2);
		dataset->Civs[loop].UnitPointers.push_back(1);
		if(EnableIDFix)
		{
			dataset->Civs[loop].Units[dataset->Civs[0].Units.size()-1].ID1 = (int16_t)(dataset->Civs[0].Units.size()-1); // ID Fix
			dataset->Civs[loop].Units[dataset->Civs[0].Units.size()-1].ID2 = (int16_t)(dataset->Civs[0].Units.size()-1);
			if(GenieVersion >= genie::GV_AoK)
			dataset->Civs[loop].Units[dataset->Civs[0].Units.size()-1].ID3 = (int16_t)(dataset->Civs[0].Units.size()-1);
		}
	}
	How2List = ADD;
	ListUnits(UnitCivID);

	if(GenieVersion <= genie::GV_TC && dataset->Civs[0].Units.size() > 900) SetStatusText("Units over 900 mess up the AI!!!", 0);
}

void AGE_Frame::OnUnitsInsert(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)	// AoK, TC, SWGB or CC
	{
		genie::UnitHeader Temp1;
		Temp1.setGameVersion(GenieVersion);
		dataset->UnitHeaders.insert(dataset->UnitHeaders.begin() + UnitIDs[0], Temp1);
	}

	genie::Unit Temp2;
	Temp2.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		dataset->Civs[loop].Units.insert(dataset->Civs[loop].Units.begin() + UnitIDs[0], Temp2);
		dataset->Civs[loop].UnitPointers.insert(dataset->Civs[loop].UnitPointers.begin() + UnitIDs[0], 1);
		if(EnableIDFix)
		for(short loop2 = UnitIDs[0];loop2 < dataset->Civs[0].Units.size(); ++loop2) // ID Fix
		{
			dataset->Civs[loop].Units[loop2].ID1 = loop2;
			dataset->Civs[loop].Units[loop2].ID2 = loop2;
			if(GenieVersion >= genie::GV_AoK)
			dataset->Civs[loop].Units[loop2].ID3 = loop2;
		}
	}
	How2List = INSNEW;
	ListUnits(UnitCivID);
}

void AGE_Frame::OnUnitsDelete(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)
	{
		for(auto loop = selections; loop--> 0;)
		dataset->UnitHeaders.erase(dataset->UnitHeaders.begin() + UnitIDs[loop]);
	}

	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		for(auto loop = selections; loop--> 0;)
		{
			dataset->Civs[civ].Units.erase(dataset->Civs[civ].Units.begin() + UnitIDs[loop]);
			dataset->Civs[civ].UnitPointers.erase(dataset->Civs[civ].UnitPointers.begin() + UnitIDs[loop]);
		}
		if(EnableIDFix)
		for(short loop = UnitIDs[0]; loop < dataset->Civs[0].Units.size(); ++loop) // ID Fix
		{
			dataset->Civs[civ].Units[loop].ID1 = loop;
			dataset->Civs[civ].Units[loop].ID2 = loop;
			if(GenieVersion >= genie::GV_AoK)
			dataset->Civs[civ].Units[loop].ID3 = loop;
		}
	}
	How2List = DEL;
	ListUnits(UnitCivID);
}

void AGE_Frame::OnUnitsCopy(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion < genie::GV_AoK)
	{
		copies.Dat.AllCivs |= 0x08;
	}
	else
	{
		copies.Dat.AllCivs &= ~0x08;
		copies.UnitHeader.resize(selections);
		for(short loop = 0; loop < selections; ++loop)
		copies.UnitHeader[loop] = dataset->UnitHeaders[UnitIDs[loop]];
	}

	short CivCount = dataset->Civs.size();
	copies.Dat.UnitExists.resize(CivCount);
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x01; else copies.Dat.AllCivs &= ~0x01;
	if(copies.Dat.AllCivs & 0x01)
	{
		copies.Dat.UnitCopies.resize(CivCount);
		for(short civ = 0; civ < CivCount; ++civ)
		{
			copies.Dat.UnitExists[civ].resize(selections);
			copies.Dat.UnitCopies[civ].resize(selections);
			for(short loop = 0; loop < selections; ++loop)
			{
				copies.Dat.UnitExists[civ][loop] = (bool)dataset->Civs[civ].UnitPointers[UnitIDs[loop]];
				copies.Dat.UnitCopies[civ][loop] = dataset->Civs[civ].Units[UnitIDs[loop]];
			}
		}
	}
	else
	{
		copies.Dat.UnitGraphics.resize(CivCount);
		for(short civ = 0; civ < CivCount; ++civ)
		{
			copies.Dat.UnitExists[civ].resize(selections);
			if(AutoCopy && !CopyGraphics)
			copies.Dat.UnitGraphics[civ].resize(selections);
			for(short loop = 0; loop < selections; ++loop)
			{
				copies.Dat.UnitExists[civ][loop] = (bool)dataset->Civs[civ].UnitPointers[UnitIDs[loop]];
				if(AutoCopy && !CopyGraphics)
				{// Let's copy graphics separately.
					// Collects only graphic data, not all data again.
					UnitsGraphicsCopy(copies.Dat.UnitGraphics[civ][loop], civ, UnitIDs[loop]);
				}
			}
		}
		copies.Dat.UnitCopies[0].resize(selections);
		for(short loop = 0; loop < selections; ++loop)
		copies.Dat.UnitCopies[0][loop] = dataset->Civs[UnitCivID].Units[UnitIDs[loop]];
	}
	Units_ListV->SetFocus();
}

void AGE_Frame::OnAutoCopy(wxCommandEvent &event)
{
	if(event.GetId() == Units_AutoCopy->GetId())
	{
		AutoCopy = event.IsChecked();
		Units_CopyTo->Enable(!AutoCopy);
	}
	else if(event.GetId() == Units_CopyGraphics->GetId())
	{
		CopyGraphics = event.IsChecked();
	}
	else if(event.GetId() == Units_SelectAll->GetId())
	{
		for(short loop = 0; loop < dataset->Civs.size(); ++loop)
		Units_CivBoxes[loop]->SetValue(true);
	}
	else if(event.GetId() == Units_SelectClear->GetId())
	{
		for(short loop = 0; loop < dataset->Civs.size(); ++loop)
		Units_CivBoxes[loop]->SetValue(false);
	}
	else if(event.GetId() == Units_GraphicSet->GetId())
	{
		short Selection = Units_GraphicSet->GetSelection();
		for(short loop = 0; loop < dataset->Civs.size(); ++loop)
		{
			if((short)dataset->Civs[loop].IconSet == Selection)
			{
				Units_CivBoxes[loop]->SetValue(true);
			}
			else
			{
				Units_CivBoxes[loop]->SetValue(false);
			}
		}
	}
	// This ensures that proper data pointers are assigned to editing boxes.
	// MAKE THIS SO THAT THE SELECTIONS REMAIN!!!
	wxTimerEvent E;
	OnUnitsTimer(E);
}

void AGE_Frame::UnitsAutoCopy(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	int edits = 0;
	GraphicCopies graphics;
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		if(Units_CivBoxes[civ]->IsChecked() && civ != UnitCivID)
		{
			for(short loop = 0; loop < selections; ++loop)
			{
				if(!CopyGraphics)// Let's copy graphics separately.
				UnitsGraphicsCopy(graphics, civ, UnitIDs[loop]);
				dataset->Civs[civ].Units[UnitIDs[loop]] = dataset->Civs[UnitCivID].Units[UnitIDs[loop]];
				if(!CopyGraphics)// Let's paste graphics separately.
				UnitsGraphicsPaste(graphics, civ, UnitIDs[loop]);
			}
			++edits;
		}
	}

	SetStatusText("Manual unit copy", 2);
	SetStatusText("Edits: "+lexical_cast<string>(AGETextCtrl::unSaved[AGEwindow])+" + "+lexical_cast<string>(edits), 3);
	AGETextCtrl::unSaved[AGEwindow] += edits;
}

void AGE_Frame::UnitsGraphicsCopy(GraphicCopies &store, short civ, short unit)
{
	store.IconID = dataset->Civs[civ].Units[unit].IconID;// This probably shouldn't be here.
	store.StandingGraphic = dataset->Civs[civ].Units[unit].StandingGraphic;
	store.DyingGraphic = dataset->Civs[civ].Units[unit].DyingGraphic;
	store.DamageGraphics = dataset->Civs[civ].Units[unit].DamageGraphics;
	switch((short)dataset->Civs[civ].Units[unit].Type)
	{
		case 80:
		store.ConstructionGraphicID = dataset->Civs[civ].Units[unit].Building.ConstructionGraphicID;
		store.SnowGraphicID = dataset->Civs[civ].Units[unit].Building.SnowGraphicID;
		case 70:
		store.GarrisonGraphic = dataset->Civs[civ].Units[unit].Creatable.GarrisonGraphic;
		case 60:
		case 50:
		store.AttackGraphic = dataset->Civs[civ].Units[unit].Type50.AttackGraphic;
		case 40:
		case 30:
		store.WalkingGraphic = dataset->Civs[civ].Units[unit].DeadFish.WalkingGraphic;
	}
}

void AGE_Frame::OnUnitsSpecialCopy(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x02; else copies.Dat.AllCivs &= ~0x02;
	if(copies.Dat.AllCivs & 0x02)
	{
		short CivCount = dataset->Civs.size();
		copies.Dat.UnitGraphics.resize(CivCount);
		for(short civ = 0; civ < CivCount; ++civ)
		{
			copies.Dat.UnitGraphics[civ].resize(selections);
			for(short loop = 0; loop < selections; ++loop)
			UnitsGraphicsCopy(copies.Dat.UnitGraphics[civ][loop], civ, UnitIDs[loop]);
		}
	}
	else
	{
		copies.Dat.UnitGraphics[0].resize(selections);
		for(short loop = 0; loop < selections; ++loop)
		UnitsGraphicsCopy(copies.Dat.UnitGraphics[0][loop], UnitCivID, UnitIDs[loop]);
	}
	Units_ListV->SetFocus();
}

void AGE_Frame::OnUnitsPaste(wxCommandEvent &event)
{
	if(!Units_ListV->GetSelectedItemCount() || copies.Dat.UnitExists.size() == 0) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(UnitIDs.size(), copies.Dat.UnitExists[0].size()))
		{
			if(GenieVersion >= genie::GV_AoK)
			{
				for(short loop = 0; loop < copies.UnitHeader.size(); ++loop)
				{
					copies.UnitHeader[loop].setGameVersion(GenieVersion);
					dataset->UnitHeaders[UnitIDs[loop]] = copies.UnitHeader[loop];
				}
			}

			PasteUnits();
			for(short civ = 0; civ < dataset->Civs.size(); ++civ)
			{
				for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
				{
					dataset->Civs[civ].UnitPointers[UnitIDs[loop]] = (int32_t)copies.Dat.UnitExists[civ][loop];
					if(EnableIDFix) // ID Fix
					{
						dataset->Civs[civ].Units[UnitIDs[loop]].ID1 = (int16_t)(UnitIDs[loop]);
						dataset->Civs[civ].Units[UnitIDs[loop]].ID2 = (int16_t)(UnitIDs[loop]);
						if(GenieVersion >= genie::GV_AoK)
						dataset->Civs[civ].Units[UnitIDs[loop]].ID3 = (int16_t)(UnitIDs[loop]);
					}
				}
			}
		}
	}
	else
	{
		if(GenieVersion >= genie::GV_AoK)
		{
			if(copies.UnitHeader.size()+UnitIDs[0] > dataset->UnitHeaders.size())
			dataset->UnitHeaders.resize(copies.UnitHeader.size()+UnitIDs[0]);
			for(short loop = 0; loop < copies.UnitHeader.size(); ++loop)
			{
				copies.UnitHeader[loop].setGameVersion(GenieVersion);
				dataset->UnitHeaders[UnitIDs[0]+loop] = copies.UnitHeader[loop];
			}
		}

		if(copies.Dat.UnitCopies[0].size()+UnitIDs[0] > dataset->Civs[0].Units.size())
		for(short civ = 0; civ < dataset->Civs.size(); ++civ) // Resize if not enough room.
		{
			dataset->Civs[civ].Units.resize(copies.Dat.UnitCopies[0].size()+UnitIDs[0]);
			dataset->Civs[civ].UnitPointers.resize(copies.Dat.UnitCopies[0].size()+UnitIDs[0]);
		}
		PasteUnits();
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
			{
				dataset->Civs[civ].UnitPointers[UnitIDs[0]+loop] = (int32_t)copies.Dat.UnitExists[civ][loop];
				if(EnableIDFix) // ID Fix
				{
					dataset->Civs[civ].Units[UnitIDs[0]+loop].ID1 = (int16_t)(UnitIDs[0]+loop);
					dataset->Civs[civ].Units[UnitIDs[0]+loop].ID2 = (int16_t)(UnitIDs[0]+loop);
					if(GenieVersion >= genie::GV_AoK)
					dataset->Civs[civ].Units[UnitIDs[0]+loop].ID3 = (int16_t)(UnitIDs[0]+loop);
				}
			}
		}
	}
	How2List = PASTE;
	ListUnits(UnitCivID);

	SetStatusText("Unit special paste", 2);
	SetStatusText("Edits: "+lexical_cast<string>(AGETextCtrl::unSaved[AGEwindow])+" + "+FormatInt(copies.Dat.UnitCopies[0].size()), 3);
	AGETextCtrl::unSaved[AGEwindow] += copies.Dat.UnitCopies[0].size();
}

void AGE_Frame::OnUnitsPasteInsert(wxCommandEvent &event)
{
	if(!Units_ListV->GetSelectedItemCount() || copies.Dat.UnitExists.size() == 0) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)
	{
		genie::UnitHeader Temp1;
		dataset->UnitHeaders.insert(dataset->UnitHeaders.begin() + UnitIDs[0], copies.UnitHeader.size(), Temp1);
		for(short loop = 0; loop < copies.UnitHeader.size(); ++loop)
		{
			copies.UnitHeader[loop].setGameVersion(GenieVersion);
			dataset->UnitHeaders[UnitIDs[0]+loop] = copies.UnitHeader[loop];
		}
	}

	genie::Unit Temp2;
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		dataset->Civs[civ].Units.insert(dataset->Civs[civ].Units.begin() + UnitIDs[0], copies.Dat.UnitCopies[0].size(), Temp2);
		dataset->Civs[civ].UnitPointers.insert(dataset->Civs[civ].UnitPointers.begin() + UnitIDs[0], copies.Dat.UnitCopies[0].size(), 0);
	}
	PasteUnits();
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
		{
			dataset->Civs[civ].UnitPointers[UnitIDs[0]+loop] = (int32_t)copies.Dat.UnitExists[civ][loop];
		}
		if(EnableIDFix) // ID Fix
		for(short loop = UnitIDs[0];loop < dataset->Civs[0].Units.size(); ++loop)
		{
			dataset->Civs[civ].Units[loop].ID1 = loop;
			dataset->Civs[civ].Units[loop].ID2 = loop;
			if(GenieVersion >= genie::GV_AoK)
			dataset->Civs[civ].Units[loop].ID3 = loop;
		}
	}
	How2List = INSPASTE;
	ListUnits(UnitCivID);
}

short AGE_Frame::CorrectID(bool OneOnOne, short loop)
{
	return OneOnOne ? UnitIDs[loop] : UnitIDs[0] + loop;
}

void AGE_Frame::PasteUnits(bool OneOnOne)
{
	// The civ amount of copy data must be set on copying!
	// Otherwise having more than one window open with different civ count creates problems!
	short CivCount = dataset->Civs.size();
	short FillingCiv = (copies.Dat.UnitExists.size() > 1) ? 1 : 0;
	copies.Dat.UnitExists.resize(CivCount, copies.Dat.UnitExists[FillingCiv]);
	if(copies.Dat.AllCivs & 0x01) // Paste from all civs to all civs.
	{
		copies.Dat.UnitCopies.resize(CivCount, copies.Dat.UnitCopies[FillingCiv]);
		for(short civ = 0; civ < CivCount; ++civ)
		{
			for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop) // selections
			{
				copies.Dat.UnitCopies[civ][loop].setGameVersion(GenieVersion);
				dataset->Civs[civ].Units[CorrectID(OneOnOne, loop)] = copies.Dat.UnitCopies[civ][loop];
			}
		}
	}
	else
	{
		if(AutoCopy) // Paste from one civ to selected civs.
		{
			copies.Dat.UnitGraphics.resize(CivCount, copies.Dat.UnitGraphics[FillingCiv]);
			for(short civ = 0; civ < CivCount; ++civ)
			{
				if(Units_CivBoxes[civ]->IsChecked())
				{
					for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
					{
						copies.Dat.UnitCopies[0][loop].setGameVersion(GenieVersion);
						dataset->Civs[civ].Units[CorrectID(OneOnOne, loop)] = copies.Dat.UnitCopies[0][loop];
						if(!CopyGraphics)
						{// Let's paste graphics separately.
							UnitsGraphicsPaste(copies.Dat.UnitGraphics[civ][loop], civ, CorrectID(OneOnOne, loop));
						}
					}
				}
			}
		}
		else // Paste from one civ to another civ.
		{
			for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
			{
				copies.Dat.UnitCopies[0][loop].setGameVersion(GenieVersion);
				dataset->Civs[UnitCivID].Units[CorrectID(OneOnOne, loop)] = copies.Dat.UnitCopies[0][loop];
			}
		}
	}
	if(copies.Dat.AllCivs & 0x08) // Paste from AoE to AoK+
	{
		// Paste commands properly
		if(GenieVersion >= genie::GV_AoK)
		{
			if(copies.Dat.AllCivs & 0x01)
			{
				for(short loop = 0; loop < copies.Dat.UnitCopies[0].size(); ++loop)
				{
					for(short civ = 0; civ < copies.Dat.UnitCopies.size(); ++civ)
					{
						if(copies.Dat.UnitExists[civ][loop] != 0)
						{
							dataset->UnitHeaders[CorrectID(OneOnOne, loop)].Exists = 1;
							dataset->UnitHeaders[CorrectID(OneOnOne, loop)].Commands = copies.Dat.UnitCopies[civ][loop].Bird.Commands;
							break;
						}
					}
				}
			}
			else
			wxMessageBox("Please select All civs from the bottom!", "Ouch!");
		}
	}
	else if(GenieVersion < genie::GV_AoK) // Paste from AoK+ to AoE
	{
		for(short loop = 0; loop < copies.UnitHeader.size(); ++loop)
		{
			for(short civ = 0; civ < dataset->Civs.size(); ++civ)
			{
				if(dataset->Civs[civ].UnitPointers[CorrectID(OneOnOne, loop)] != 0)
				dataset->Civs[civ].Units[CorrectID(OneOnOne, loop)].Bird.Commands = copies.UnitHeader[loop].Commands;
			}
		}
	}
}

void AGE_Frame::UnitsGraphicsPaste(GraphicCopies &store, short civ, short unit)
{
	dataset->Civs[civ].Units[unit].IconID = store.IconID;
	dataset->Civs[civ].Units[unit].StandingGraphic = store.StandingGraphic;
	dataset->Civs[civ].Units[unit].DyingGraphic = store.DyingGraphic;
	dataset->Civs[civ].Units[unit].DamageGraphics = store.DamageGraphics;
	switch((short)dataset->Civs[civ].Units[unit].Type)
	{
		case 80:
		dataset->Civs[civ].Units[unit].Building.ConstructionGraphicID = store.ConstructionGraphicID;
		dataset->Civs[civ].Units[unit].Building.SnowGraphicID = store.SnowGraphicID;
		case 70:
		dataset->Civs[civ].Units[unit].Creatable.GarrisonGraphic = store.GarrisonGraphic;
		case 60:
		case 50:
		dataset->Civs[civ].Units[unit].Type50.AttackGraphic = store.AttackGraphic;
		case 40:
		case 30:
		dataset->Civs[civ].Units[unit].DeadFish.WalkingGraphic = store.WalkingGraphic;
	}
}

void AGE_Frame::OnUnitsSpecialPaste(wxCommandEvent &event)
{
	short CopyCount = copies.Dat.UnitGraphics[0].size();
	if(!Units_ListV->GetSelectedItemCount() || CopyCount == 0) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(UnitIDs.size(), CopyCount))
		{
			if(copies.Dat.AllCivs & 0x02)
			{
				short CivCount = dataset->Civs.size();
				short FillingCiv = (copies.Dat.UnitGraphics.size() > 1) ? 1 : 0;
				copies.Dat.UnitGraphics.resize(CivCount, copies.Dat.UnitGraphics[FillingCiv]);
				for(short civ = 0; civ < CivCount; ++civ)
				{
					for(short loop = 0; loop < CopyCount; ++loop)
					UnitsGraphicsPaste(copies.Dat.UnitGraphics[civ][loop], civ, UnitIDs[loop]);
				}
			}
			else
			{
				for(short loop = 0; loop < CopyCount; ++loop)
				UnitsGraphicsPaste(copies.Dat.UnitGraphics[0][loop], UnitCivID, UnitIDs[loop]);
			}
		}
	}
	else
	{
		if(copies.Dat.UnitGraphics[0].size()+UnitIDs[0] > dataset->Civs[0].Units.size())
		CopyCount -= copies.Dat.UnitGraphics[0].size()+UnitIDs[0] - dataset->Civs[0].Units.size();
		if(copies.Dat.AllCivs & 0x02)
		{
			short CivCount = dataset->Civs.size();
			short FillingCiv = (copies.Dat.UnitGraphics.size() > 1) ? 1 : 0;
			copies.Dat.UnitGraphics.resize(CivCount, copies.Dat.UnitGraphics[FillingCiv]);
			for(short civ = 0; civ < CivCount; ++civ)
			{
				for(short loop = 0; loop < CopyCount; ++loop)
				UnitsGraphicsPaste(copies.Dat.UnitGraphics[civ][loop], civ, UnitIDs[0]+loop);
			}
		}
		else
		{
			for(short loop = 0; loop < CopyCount; ++loop)
			UnitsGraphicsPaste(copies.Dat.UnitGraphics[0][loop], UnitCivID, UnitIDs[0]+loop);
		}
	}
	wxTimerEvent E;
	OnUnitsTimer(E);
	Units_ListV->SetFocus();
}

void AGE_Frame::OnUnitsEnable(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	for(short sel = 0; sel < selections; ++sel)
	{
		// Find the correct sizes for subvectors.
		short UnitType = 10, DamageGraphics = 0, Attacks = 0, Armors = 0, Commands = 0;
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[sel]] != 0)
			{
				UnitType = dataset->Civs[civ].Units[UnitIDs[sel]].Type;
				DamageGraphics = dataset->Civs[civ].Units[UnitIDs[sel]].DamageGraphics.size();
				Attacks = dataset->Civs[civ].Units[UnitIDs[sel]].Type50.Attacks.size();
				Armors = dataset->Civs[civ].Units[UnitIDs[sel]].Type50.Armours.size();
				if(GenieVersion < genie::GV_AoK)
				Commands = dataset->Civs[civ].Units[UnitIDs[sel]].Bird.Commands.size();
				break;
			}
		}
		// All subvectors need to be resized!
		if(Units_SpecialCopy_Civs->GetValue())
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[sel]] == 0)
			{
				dataset->Civs[civ].UnitPointers[UnitIDs[sel]] = 1;
				dataset->Civs[civ].Units[UnitIDs[sel]].Type = UnitType;
				dataset->Civs[civ].Units[UnitIDs[sel]].DamageGraphics.resize(DamageGraphics);
				dataset->Civs[civ].Units[UnitIDs[sel]].Type50.Attacks.resize(Attacks);
				dataset->Civs[civ].Units[UnitIDs[sel]].Type50.Armours.resize(Armors);
				dataset->Civs[civ].Units[UnitIDs[sel]].Bird.Commands.resize(Commands);
				dataset->Civs[civ].Units[UnitIDs[sel]].ID1 = UnitIDs[sel]; // ID Fix
				dataset->Civs[civ].Units[UnitIDs[sel]].ID2 = UnitIDs[sel];
				if(GenieVersion >= genie::GV_AoKA)
				dataset->Civs[civ].Units[UnitIDs[sel]].ID3 = UnitIDs[sel];
			}
		}
		else
		{
			if(dataset->Civs[UnitCivID].UnitPointers[UnitIDs[sel]] == 0)
			{
				dataset->Civs[UnitCivID].UnitPointers[UnitIDs[sel]] = 1;
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].Type = UnitType;
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].DamageGraphics.resize(DamageGraphics);
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].Type50.Attacks.resize(Attacks);
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].Type50.Armours.resize(Armors);
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].Bird.Commands.resize(Commands);
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].ID1 = UnitIDs[sel]; // ID Fix
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].ID2 = UnitIDs[sel];
				if(GenieVersion >= genie::GV_AoKA)
				dataset->Civs[UnitCivID].Units[UnitIDs[sel]].ID3 = UnitIDs[sel];
			}
		}
	}
	How2List = ENABLE;
	ListUnits(UnitCivID);
}

void AGE_Frame::OnUnitsDisable(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	for(short sel = 0; sel < selections; ++sel)
	{
		if(Units_SpecialCopy_Civs->GetValue())
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		dataset->Civs[civ].UnitPointers[UnitIDs[sel]] = 0;
		else
		dataset->Civs[UnitCivID].UnitPointers[UnitIDs[sel]] = 0;
	}
	How2List = ENABLE;
	ListUnits(UnitCivID);
}

//	SubVectors

string AGE_Frame::GetUnitDamageGraphicName(short Index)
{
	return lexical_cast<string>((short)dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics[Index].DamagePercent)
	+" % - ID: "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics[Index].GraphicID)+" ";
}

void AGE_Frame::OnUnitDamageGraphicsSearch(wxCommandEvent &event)
{
	How2List = SEARCH;
	ListUnitDamageGraphics();
}

void AGE_Frame::ListUnitDamageGraphics()
{
	searchText = Units_DamageGraphics_Search->GetValue().Lower();
	excludeText = Units_DamageGraphics_Search_R->GetValue().Lower();

    Units_DamageGraphics_ListV->names.clear();
    Units_DamageGraphics_ListV->indexes.clear();

	if(Units_ListV->GetSelectedItemCount()
	&& dataset->Civs[UnitCivID].UnitPointers[UnitIDs[0]] != 0)
	{
		Units_DamageGraphics_Add->Enable(true);
		for(short loop = 0; loop < dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics.size(); ++loop)
		{
			wxString Name = " "+FormatInt(loop)+" - "+GetUnitDamageGraphicName(loop);
			if(SearchMatches(Name.Lower()))
			{
                Units_DamageGraphics_ListV->names.Add(Name);
                Units_DamageGraphics_ListV->indexes.push_back(loop);
			}
		}
	}
	else
	{
		Units_DamageGraphics_Add->Enable(false);
	}
	virtualListing(Units_DamageGraphics_ListV);

	wxTimerEvent E;
	OnUnitDamageGraphicsTimer(E);
}

void AGE_Frame::OnUnitDamageGraphicsSelect(wxCommandEvent &event)
{
    if(!dmgGraphicTimer.IsRunning())
        dmgGraphicTimer.Start(150);
}

void AGE_Frame::OnUnitDamageGraphicsTimer(wxTimerEvent &event)
{
    dmgGraphicTimer.Stop();
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount();
    wxBusyCursor WaitCursor;
    for(auto &box: uiGroupUnitDmgGraphic) box->clear();
	if(selections > 0)
	{
        getSelectedItems(selections, Units_DamageGraphics_ListV, DamageGraphicIDs);
		// This and attacks/armors/commands need a lot of thinking.

		bool showWarning = false;
		wxString warning = "Damage graphic count of civs\n";
		genie::unit::DamageGraphic * DamageGraphicPointer;
		for(auto sel = selections; sel--> 0;)
		{
			for(short vecCiv = (CopyGraphics) ? SelectedCivs.size() : 1; vecCiv--> 0;)
			{
				if(sel == 0 && dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].DamageGraphics.size() != dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics.size())
				{
					warning.Append(lexical_cast<string>(SelectedCivs[vecCiv])+" ");
					showWarning = true;
				}
				DamageGraphicPointer = &dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].DamageGraphics[DamageGraphicIDs[sel]];

				DamageGraphics_GraphicID->prepend(&DamageGraphicPointer->GraphicID);
				DamageGraphics_DamagePercent->prepend(&DamageGraphicPointer->DamagePercent);
				DamageGraphics_Unknown1->prepend(&DamageGraphicPointer->ApplyMode);
				DamageGraphics_Unknown2->prepend(&DamageGraphicPointer->Unknown2);
			}
		}
		if(showWarning)
		{
			warning.Append("\ndiffers from civ "+lexical_cast<string>(UnitCivID));
			wxMessageBox(warning);
		}
	}
	for(auto &box: uiGroupUnitDmgGraphic) box->update();
    if(slpdmgunit->GetValue())
    {
        wxCommandEvent E;
        OnChooseGraphic(E);
    }
}

void AGE_Frame::OnUnitDamageGraphicsAdd(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::DamageGraphic Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].DamageGraphics.push_back(Temp);
	}
	How2List = ADD;
	ListUnitDamageGraphics();
}

void AGE_Frame::OnUnitDamageGraphicsInsert(wxCommandEvent &event)
{
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::DamageGraphic Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].DamageGraphics.insert(dataset->Civs[loop].Units[UnitIDs[0]].DamageGraphics.begin() + DamageGraphicIDs[0], Temp);
	}
	How2List = INSNEW;
	ListUnitDamageGraphics();
}

void AGE_Frame::OnUnitDamageGraphicsDelete(wxCommandEvent &event)
{
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount(); // Gives the current list selection.
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] != 0)
		if(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics.size())
		for(auto loop = selections; loop--> 0;)
		dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics.erase(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics.begin() + DamageGraphicIDs[loop]);
	}
	How2List = DEL;
	ListUnitDamageGraphics();
}

void AGE_Frame::OnUnitDamageGraphicsCopy(wxCommandEvent &event)
{
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x10; else copies.Dat.AllCivs &= ~0x10;
	if(copies.Dat.AllCivs & 0x10)
	{
		short CivCount = dataset->Civs.size();
		copies.Dat.UnitDamageGraphicExists.resize(CivCount);
		copies.Dat.UnitDamageGraphics.resize(CivCount);
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Graphic set info not usefull.
				copies.Dat.UnitDamageGraphicExists[civ] = 255;
				CivCount--;
			}
			else
			{
				// Save info of graphic set to intelligently fill possible gaps when pasting.
				copies.Dat.UnitDamageGraphicExists[civ] = 256 + dataset->Civs[civ].IconSet;
				// Only copy damage graphics from civs which have this unit enabled.
				CopyFromList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs, copies.Dat.UnitDamageGraphics[copy]); copy++;
			}
		}
		copies.Dat.UnitDamageGraphics.resize(CivCount);
	}
	else
	{
		CopyFromList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs, copies.Dat.UnitDamageGraphics[0]);
	}
	Units_DamageGraphics_ListV->SetFocus();
}

void AGE_Frame::OnUnitDamageGraphicsPaste(wxCommandEvent &event)
{
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(DamageGraphicIDs.size(), copies.Dat.UnitDamageGraphics[0].size()))
		{
			if(copies.Dat.AllCivs & 0x10)
			{
				for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
				{
					if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
					{
						// Consume copies.
						if(copies.Dat.UnitDamageGraphicExists[civ] > 255) copy++; continue;
					}
					// If the target unit exists then choose from following.
					if(copies.Dat.UnitDamageGraphicExists[civ] > 255 && copy < copies.Dat.UnitDamageGraphics.size())
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs, copies.Dat.UnitDamageGraphics[copy]); copy++;
					}
					else
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs, copies.Dat.UnitDamageGraphics[0]);
					}
				}
			}
			else
			{
				PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs, copies.Dat.UnitDamageGraphics[0]);
			}
		}
	}
	else
	{
		if(copies.Dat.AllCivs & 0x10)
		{
			for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
			{
				if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
				{
					// Consume copies.
					if(copies.Dat.UnitDamageGraphicExists[civ] > 255) copy++; continue;
				}
				// If the target unit exists then choose from following.
				if(copies.Dat.UnitDamageGraphicExists[civ] > 255 && copy < copies.Dat.UnitDamageGraphics.size())
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[copy]); copy++;
				}
				else
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[0]);
				}
			}
		}
		else
		{
			PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[0]);
		}
	}
	ListUnitDamageGraphics();
}

void AGE_Frame::OnUnitDamageGraphicsPasteInsert(wxCommandEvent &event)
{
	auto selections = Units_DamageGraphics_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::DamageGraphic Temp;
	if(copies.Dat.AllCivs & 0x10)
	{
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Consume copies.
				if(copies.Dat.UnitDamageGraphicExists[civ] > 255) copy++; continue;
			}
			// If the target unit exists then choose from following.
			if(copies.Dat.UnitDamageGraphicExists[civ] > 255 && copy < copies.Dat.UnitDamageGraphics.size())
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[copy]); copy++;
			}
			else
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[0]);
			}
		}
	}
	else
	{
		PasteInsertToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].DamageGraphics, DamageGraphicIDs[0], copies.Dat.UnitDamageGraphics[0]);
	}
	ListUnitDamageGraphics();
}

void AGE_Frame::OnUnitDamageGraphicsCopyToUnits(wxCommandEvent &event)
{
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	for(short loop=1; loop < UnitIDs.size(); ++loop)
	{
		dataset->Civs[civ].Units[UnitIDs[loop]].DamageGraphics = dataset->Civs[civ].Units[UnitIDs[0]].DamageGraphics;
	}
}

string AGE_Frame::GetUnitAttackName(short Index)
{
	return "Amount: "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks[Index].Amount)
	+" - Class "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks[Index].Class)+" ";
}

void AGE_Frame::OnUnitAttacksSearch(wxCommandEvent &event)
{
	How2List = SEARCH;
	ListUnitAttacks();
}

void AGE_Frame::ListUnitAttacks()
{
	searchText = Units_Attacks_Search->GetValue().Lower();
	excludeText = Units_Attacks_Search_R->GetValue().Lower();

    Units_Attacks_ListV->names.clear();
    Units_Attacks_ListV->indexes.clear();

	if(Units_ListV->GetSelectedItemCount()
	&& dataset->Civs[UnitCivID].UnitPointers[UnitIDs[0]] != 0
	&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type >= 50
	&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type <= 80)
	{
		Units_Attacks_Add->Enable(true);
		for(short loop = 0; loop < dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks.size(); ++loop)
		{
			wxString Name = " "+FormatInt(loop)+" - "+GetUnitAttackName(loop);
			if(SearchMatches(Name.Lower()))
			{
                Units_Attacks_ListV->names.Add(Name);
                Units_Attacks_ListV->indexes.push_back(loop);
			}
		}
	}
	else
	{
		Units_Attacks_Add->Enable(false);
	}
	virtualListing(Units_Attacks_ListV);

	wxTimerEvent E;
	OnUnitAttacksTimer(E);
}

void AGE_Frame::OnUnitAttacksSelect(wxCommandEvent &event)
{
    if(!attackTimer.IsRunning())
        attackTimer.Start(150);
}

void AGE_Frame::OnUnitAttacksTimer(wxTimerEvent &event)
{
    attackTimer.Stop();
	auto selections = Units_Attacks_ListV->GetSelectedItemCount();
    wxBusyCursor WaitCursor;
    Attacks_Class->clear();
    Attacks_Amount->clear();
	if(selections > 0)
	{
        getSelectedItems(selections, Units_Attacks_ListV, AttackIDs);

		bool showWarning = false;
		wxString warning = "Attack count of civs\n";
		genie::unit::AttackOrArmor * AttackPointer;
		for(auto sel = selections; sel--> 0;)
		{
			for(short vecCiv = SelectedCivs.size(); vecCiv--> 0;)
			{
				if(sel == 0 && dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Type50.Attacks.size() != dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks.size())
				{
					warning.Append(lexical_cast<string>(SelectedCivs[vecCiv])+" ");
					showWarning = true;
				}
				AttackPointer = &dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Type50.Attacks[AttackIDs[sel]];

				Attacks_Class->prepend(&AttackPointer->Class);
				Attacks_Amount->prepend(&AttackPointer->Amount);
			}
		}
		if(showWarning)
		{
			warning.Append("\ndiffers from civ "+lexical_cast<string>(UnitCivID));
			wxMessageBox(warning);
		}
	}
	Attacks_Class->update();
	Attacks_Amount->update();
}

void AGE_Frame::OnUnitAttacksAdd(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::AttackOrArmor Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].Type50.Attacks.push_back(Temp);
	}
	How2List = ADD;
	ListUnitAttacks();
}

void AGE_Frame::OnUnitAttacksInsert(wxCommandEvent &event)
{
	auto selections = Units_Attacks_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::AttackOrArmor Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].Type50.Attacks.insert(dataset->Civs[loop].Units[UnitIDs[0]].Type50.Attacks.begin() + AttackIDs[0], Temp);
	}
	How2List = INSNEW;
	ListUnitAttacks();
}

void AGE_Frame::OnUnitAttacksDelete(wxCommandEvent &event)
{
	auto selections = Units_Attacks_ListV->GetSelectedItemCount(); // Gives the current list selection.
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] != 0)
		if(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks.size())
		for(auto loop = selections; loop--> 0;)
		dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks.erase(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks.begin() + AttackIDs[loop]);
	}
	How2List = DEL;
	ListUnitAttacks();
}

void AGE_Frame::OnUnitAttacksCopy(wxCommandEvent &event)
{
	auto selections = Units_Attacks_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x20; else copies.Dat.AllCivs &= ~0x20;
	if(copies.Dat.AllCivs & 0x20)
	{
		short CivCount = dataset->Civs.size();
		copies.Dat.UnitAttackExists.resize(CivCount);
		copies.Dat.UnitAttacks.resize(CivCount);
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Graphic set info not usefull.
				copies.Dat.UnitAttackExists[civ] = 255;
				CivCount--;
			}
			else
			{
				// Save info of graphic set to intelligently fill possible gaps when pasting.
				copies.Dat.UnitAttackExists[civ] = 256 + dataset->Civs[civ].IconSet;
				// Only copy attacks from civs which have this unit enabled.
				CopyFromList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs, copies.Dat.UnitAttacks[copy]); copy++;
			}
		}
		copies.Dat.UnitAttacks.resize(CivCount);
	}
	else
	{
		CopyFromList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks, AttackIDs, copies.Dat.UnitAttacks[0]);
	}
	Units_Attacks_ListV->SetFocus();
}

void AGE_Frame::OnUnitAttacksPaste(wxCommandEvent &event)
{
	auto selections = Units_Attacks_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(AttackIDs.size(), copies.Dat.UnitAttacks[0].size()))
		{
			if(copies.Dat.AllCivs & 0x20)
			{
				for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
				{
					if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
					{
						// Consume copies.
						if(copies.Dat.UnitAttackExists[civ] > 255) copy++; continue;
					}
					// If the target unit exists then choose from following.
					if(copies.Dat.UnitAttackExists[civ] > 255 && copy < copies.Dat.UnitAttacks.size())
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs, copies.Dat.UnitAttacks[copy]); copy++;
					}
					else
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs, copies.Dat.UnitAttacks[0]);
					}
				}
			}
			else
			{
				PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks, AttackIDs, copies.Dat.UnitAttacks[0]);
			}
		}
	}
	else
	{
		if(copies.Dat.AllCivs & 0x20)
		{
			for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
			{
				if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
				{
					// Consume copies.
					if(copies.Dat.UnitAttackExists[civ] > 255) copy++; continue;
				}
				// If the target unit exists then choose from following.
				if(copies.Dat.UnitAttackExists[civ] > 255 && copy < copies.Dat.UnitAttacks.size())
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[copy]); copy++;
				}
				else
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[0]);
				}
			}
		}
		else
		{
			PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[0]);
		}
	}
	ListUnitAttacks();
}

void AGE_Frame::OnUnitAttacksPasteInsert(wxCommandEvent &event)
{
	auto selections = Units_Attacks_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(copies.Dat.AllCivs & 0x20)
	{
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Consume copies.
				if(copies.Dat.UnitAttackExists[civ] > 255) copy++; continue;
			}
			// If the target unit exists then choose from following.
			if(copies.Dat.UnitAttackExists[civ] > 255 && copy < copies.Dat.UnitAttacks.size())
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[copy]); copy++;
			}
			else
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[0]);
			}
		}
	}
	else
	{
		PasteInsertToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Attacks, AttackIDs[0], copies.Dat.UnitAttacks[0]);
	}
	ListUnitAttacks();
}

void AGE_Frame::OnUnitAttacksCopyToUnits(wxCommandEvent &event)
{
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	for(short loop=1; loop < UnitIDs.size(); ++loop)
	{
		dataset->Civs[civ].Units[UnitIDs[loop]].Type50.Attacks = dataset->Civs[civ].Units[UnitIDs[0]].Type50.Attacks;
	}
}

string AGE_Frame::GetUnitArmorName(short Index)
{
	return "Amount: "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours[Index].Amount)
	+" - Class "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours[Index].Class)+" ";
}

void AGE_Frame::OnUnitArmorsSearch(wxCommandEvent &event)
{
	How2List = SEARCH;
	ListUnitArmors();
}

void AGE_Frame::ListUnitArmors()
{
	searchText = Units_Armors_Search->GetValue().Lower();
	excludeText = Units_Armors_Search_R->GetValue().Lower();

	Units_Armors_ListV->names.clear();
    Units_Armors_ListV->indexes.clear();

	if(Units_ListV->GetSelectedItemCount()
	&& dataset->Civs[UnitCivID].UnitPointers[UnitIDs[0]] != 0
	&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type >= 50
	&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type <= 80)
	{
		Units_Armors_Add->Enable(true);
		for(short loop = 0; loop < dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours.size(); ++loop)
		{
			wxString Name = " "+FormatInt(loop)+" - "+GetUnitArmorName(loop);
			if(SearchMatches(Name.Lower()))
			{
				Units_Armors_ListV->names.Add(Name);
                Units_Armors_ListV->indexes.push_back(loop);
			}
		}
	}
	else
	{
		Units_Armors_Add->Enable(false);
	}
	virtualListing(Units_Armors_ListV);

	wxTimerEvent E;
	OnUnitArmorsTimer(E);
}

void AGE_Frame::OnUnitArmorsSelect(wxCommandEvent &event)
{
    if(!armorTimer.IsRunning())
        armorTimer.Start(150);
}

void AGE_Frame::OnUnitArmorsTimer(wxTimerEvent &event)
{
    armorTimer.Stop();
	auto selections = Units_Armors_ListV->GetSelectedItemCount();
    wxBusyCursor WaitCursor;
    Armors_Class->clear();
    Armors_Amount->clear();
	if(selections > 0)
	{
        getSelectedItems(selections, Units_Armors_ListV, ArmorIDs);

		bool showWarning = false;
		wxString warning = "Armor count of civs\n";
		genie::unit::AttackOrArmor * ArmorPointer;
		for(auto sel = selections; sel--> 0;)
		{
			for(short vecCiv = SelectedCivs.size(); vecCiv--> 0;)
			{
				if(sel == 0 && dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Type50.Armours.size() != dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours.size())
				{
					warning.Append(lexical_cast<string>(SelectedCivs[vecCiv])+" ");
					showWarning = true;
				}
				ArmorPointer = &dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Type50.Armours[ArmorIDs[sel]];

				Armors_Class->prepend(&ArmorPointer->Class);
				Armors_Amount->prepend(&ArmorPointer->Amount);
			}
		}
		if(showWarning)
		{
			warning.Append("\ndiffers from civ "+lexical_cast<string>(UnitCivID));
			wxMessageBox(warning);
		}
	}
	Armors_Class->update();
	Armors_Amount->update();
}

void AGE_Frame::OnUnitArmorsAdd(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::AttackOrArmor Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].Type50.Armours.push_back(Temp);
	}
	How2List = ADD;
	ListUnitArmors();
}

void AGE_Frame::OnUnitArmorsInsert(wxCommandEvent &event)
{
	auto selections = Units_Armors_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::unit::AttackOrArmor Temp;
	Temp.setGameVersion(GenieVersion);
	for(short loop = 0; loop < dataset->Civs.size(); ++loop)
	{
		if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
		dataset->Civs[loop].Units[UnitIDs[0]].Type50.Armours.insert(dataset->Civs[loop].Units[UnitIDs[0]].Type50.Armours.begin() + ArmorIDs[0], Temp);
	}
	How2List = INSNEW;
	ListUnitArmors();
}

void AGE_Frame::OnUnitArmorsDelete(wxCommandEvent &event)
{
	auto selections = Units_Armors_ListV->GetSelectedItemCount(); // Gives the current list selection.
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	{
		if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] != 0)
		if(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours.size())
		for(auto loop = selections; loop--> 0;)
		dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours.erase(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours.begin() + ArmorIDs[loop]);
	}
	How2List = DEL;
	ListUnitArmors();
}

void AGE_Frame::OnUnitArmorsCopy(wxCommandEvent &event)
{
	auto selections = Units_Armors_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x40; else copies.Dat.AllCivs &= ~0x40;
	if(copies.Dat.AllCivs & 0x40)
	{
		short CivCount = dataset->Civs.size();
		copies.Dat.UnitArmorExists.resize(CivCount);
		copies.Dat.UnitArmors.resize(CivCount);
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Graphic set info not usefull.
				copies.Dat.UnitArmorExists[civ] = 255;
				CivCount--;
			}
			else
			{
				// Save info of graphic set to intelligently fill possible gaps when pasting.
				copies.Dat.UnitArmorExists[civ] = 256 + dataset->Civs[civ].IconSet;
				// Only copy armors from civs which have this unit enabled.
				CopyFromList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs, copies.Dat.UnitArmors[copy]); copy++;
			}
		}
		copies.Dat.UnitArmors.resize(CivCount);
	}
	else
	{
		CopyFromList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours, ArmorIDs, copies.Dat.UnitArmors[0]);
	}
	Units_Armors_ListV->SetFocus();
}

void AGE_Frame::OnUnitArmorsPaste(wxCommandEvent &event)
{
	auto selections = Units_Armors_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(ArmorIDs.size(), copies.Dat.UnitArmors[0].size()))
		{
			if(copies.Dat.AllCivs & 0x40)
			{
				for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
				{
					if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
					{
						// Consume copies.
						if(copies.Dat.UnitArmorExists[civ] > 255) copy++; continue;
					}
					// If the target unit exists then choose from following.
					if(copies.Dat.UnitArmorExists[civ] > 255 && copy < copies.Dat.UnitArmors.size())
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs, copies.Dat.UnitArmors[copy]); copy++;
					}
					else
					{
						PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs, copies.Dat.UnitArmors[0]);
					}
				}
			}
			else
			{
				PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours, ArmorIDs, copies.Dat.UnitArmors[0]);
			}
		}
	}
	else
	{
		if(copies.Dat.AllCivs & 0x40)
		{
			for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
			{
				if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
				{
					// Consume copies.
					if(copies.Dat.UnitArmorExists[civ] > 255) copy++; continue;
				}
				// If the target unit exists then choose from following.
				if(copies.Dat.UnitArmorExists[civ] > 255 && copy < copies.Dat.UnitArmors.size())
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[copy]); copy++;
				}
				else
				{
					PasteToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[0]);
				}
			}
		}
		else
		{
			PasteToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[0]);
		}
	}
	ListUnitArmors();
}

void AGE_Frame::OnUnitArmorsPasteInsert(wxCommandEvent &event)
{
	auto selections = Units_Armors_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(copies.Dat.AllCivs & 0x40)
	{
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Consume copies.
				if(copies.Dat.UnitArmorExists[civ] > 255) copy++; continue;
			}
			// If the target unit exists then choose from following.
			if(copies.Dat.UnitArmorExists[civ] > 255 && copy < copies.Dat.UnitArmors.size())
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[copy]); copy++;
			}
			else
			{
				PasteInsertToList(dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[0]);
			}
		}
	}
	else
	{
		PasteInsertToList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type50.Armours, ArmorIDs[0], copies.Dat.UnitArmors[0]);
	}
	ListUnitArmors();
}

void AGE_Frame::OnUnitArmorsCopyToUnits(wxCommandEvent &event)
{
	for(short civ = 0; civ < dataset->Civs.size(); ++civ)
	for(short loop=1; loop < UnitIDs.size(); ++loop)
	{
		dataset->Civs[civ].Units[UnitIDs[loop]].Type50.Armours = dataset->Civs[civ].Units[UnitIDs[0]].Type50.Armours;
	}
}

//	AoE/TC/SWGB/CC Unit Commands

wxString AGE_Frame::GetUnitCommandName(short Index)
{
	short CommandType = -1;
	short CommandSubType = -1;
	if(GenieVersion >= genie::GV_AoK) // AoK, TC, SWGB, CC
	{
		CommandType = dataset->UnitHeaders[UnitIDs[0]].Commands[Index].Type;
		CommandSubType = dataset->UnitHeaders[UnitIDs[0]].Commands[Index].ResourceProductivityMultiplier;
	}
	else // AoE, RoR
	{
		CommandType = dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[Index].Type;
		CommandSubType = dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[Index].ResourceProductivityMultiplier;
	}
	switch(CommandType)
	{
		case 1: return UnitCommands_Type_ComboBox->GetString(1);
		case 2: return UnitCommands_Type_ComboBox->GetString(2);
		case 3: return UnitCommands_Type_ComboBox->GetString(3);
		case 4: return UnitCommands_Type_ComboBox->GetString(4);
		case 5: return UnitCommands_Type_ComboBox->GetString(5);
		case 6: return UnitCommands_Type_ComboBox->GetString(6);
		case 7: return UnitCommands_Type_ComboBox->GetString(7);
		case 8: return UnitCommands_Type_ComboBox->GetString(8);
		case 10: return UnitCommands_Type_ComboBox->GetString(9);
		case 11: return UnitCommands_Type_ComboBox->GetString(10);
		case 12: return UnitCommands_Type_ComboBox->GetString(11);
		case 13: return UnitCommands_Type_ComboBox->GetString(12);
		case 20: return UnitCommands_Type_ComboBox->GetString(13);
		case 21: return UnitCommands_Type_ComboBox->GetString(14);
		case 101: return UnitCommands_Type_ComboBox->GetString(15);
		case 102: return UnitCommands_Type_ComboBox->GetString(16);
		case 103: return UnitCommands_Type_ComboBox->GetString(17);
		case 104: return UnitCommands_Type_ComboBox->GetString(18);
		case 105: return UnitCommands_Type_ComboBox->GetString(19);
		case 106: return UnitCommands_Type_ComboBox->GetString(20);
		case 107: return UnitCommands_Type_ComboBox->GetString(21);
		case 108: return UnitCommands_Type_ComboBox->GetString(22);
		case 109: return UnitCommands_Type_ComboBox->GetString(23);
		case 110: return UnitCommands_Type_ComboBox->GetString(24);
		case 111: return UnitCommands_Type_ComboBox->GetString(25);
		case 120: return UnitCommands_Type_ComboBox->GetString(26);
		case 121: return UnitCommands_Type_ComboBox->GetString(27);
		case 122: return UnitCommands_Type_ComboBox->GetString(28);
		case 123: return UnitCommands_Type_ComboBox->GetString(29);
		case 124: return UnitCommands_Type_ComboBox->GetString(30);
		case 125: return UnitCommands_Type_ComboBox->GetString(31);
		case 130: return UnitCommands_Type_ComboBox->GetString(32);
		case 131: return UnitCommands_Type_ComboBox->GetString(33);
		case 132: return UnitCommands_Type_ComboBox->GetString(34);
		case 133: return UnitCommands_Type_ComboBox->GetString(35);
		case 134: return UnitCommands_Type_ComboBox->GetString(36);
		case 135: return UnitCommands_Type_ComboBox->GetString(37);
		case 136: return UnitCommands_Type_ComboBox->GetString(38);
		case 149: return UnitCommands_Type_ComboBox->GetString(39);
		default: return "Unk. Type "+lexical_cast<string>(CommandType)+", Sub "+lexical_cast<string>(CommandSubType);
	}
}

void AGE_Frame::OnUnitCommandsSearch(wxCommandEvent &event)
{
	How2List = SEARCH;
	ListUnitCommands();
}

void AGE_Frame::ListUnitCommands()
{
	searchText = Units_UnitCommands_Search->GetValue().Lower();
	excludeText = Units_UnitCommands_Search_R->GetValue().Lower();

	Units_UnitCommands_ListV->names.clear();
    Units_UnitCommands_ListV->indexes.clear();

	if(GenieVersion >= genie::GV_AoK)	// AoK, TC, SWGB or CC
	{
        if(Units_ListV->GetSelectedItemCount())
		for(short loop = 0; loop < dataset->UnitHeaders[UnitIDs[0]].Commands.size(); ++loop)
		{
			wxString Name = " "+FormatInt(loop)+" - "+GetUnitCommandName(loop);
			if(dataset->UnitHeaders[UnitIDs[0]].Commands[loop].ClassID != -1)
			Name += " class "+lexical_cast<string>(dataset->UnitHeaders[UnitIDs[0]].Commands[loop].ClassID);
			else if(dataset->UnitHeaders[UnitIDs[0]].Commands[loop].UnitID != -1)
			Name += " unit "+lexical_cast<string>(dataset->UnitHeaders[UnitIDs[0]].Commands[loop].UnitID);
			if(SearchMatches(Name.Lower()))
			{
				Units_UnitCommands_ListV->names.Add(Name);
                Units_UnitCommands_ListV->indexes.push_back(loop);
			}
		}
	}
	else	// AoE or RoR
	{
		if(Units_ListV->GetSelectedItemCount()
		&& dataset->Civs[UnitCivID].UnitPointers[UnitIDs[0]] != 0
		&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type >= 40
		&& dataset->Civs[UnitCivID].Units[UnitIDs[0]].Type <= 80)
		{
			Units_UnitCommands_Add->Enable(true);
			for(short loop = 0; loop < dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands.size(); ++loop)
			{
				wxString Name = " "+FormatInt(loop)+" - "+GetUnitCommandName(loop);
				if(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[loop].ClassID != -1)
				Name += " class "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[loop].ClassID);
				else if(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[loop].UnitID != -1)
				Name += " unit "+lexical_cast<string>(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands[loop].UnitID);
				if(SearchMatches(Name.Lower()))
				{
					Units_UnitCommands_ListV->names.Add(Name);
                    Units_UnitCommands_ListV->indexes.push_back(loop);
				}
			}
		}
		else
		{
			Units_UnitCommands_Add->Enable(false);
		}
	}
	virtualListing(Units_UnitCommands_ListV);

	wxTimerEvent E;
	OnUnitCommandsTimer(E);
}

void AGE_Frame::OnUnitCommandsSelect(wxCommandEvent &event)
{
    if(!actionTimer.IsRunning())
        actionTimer.Start(150);
}

void AGE_Frame::OnUnitCommandsTimer(wxTimerEvent &event)
{
    actionTimer.Stop();
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount();
    wxBusyCursor WaitCursor;
    for(auto &box: uiGroupUnitCommand) box->clear();
	if(selections > 0)
	{
        getSelectedItems(selections, Units_UnitCommands_ListV, CommandIDs);

		bool showWarning = false;
		wxString warning = "Command count of civs\n";
		genie::UnitCommand * CommandPointer = NULL;
		for(auto sel = selections; sel--> 0;)
		{
			for(short vecCiv = (GenieVersion < genie::GV_AoK) ? SelectedCivs.size() : 1; vecCiv--> 0;)
			{
				if(GenieVersion < genie::GV_AoK)
				{
					if(sel == 0 && dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Bird.Commands.size() != dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands.size())
					{
						warning.Append(lexical_cast<string>(SelectedCivs[vecCiv])+" ");
						showWarning = true;
					}
					CommandPointer = &dataset->Civs[SelectedCivs[vecCiv]].Units[UnitIDs[0]].Bird.Commands[CommandIDs[sel]];
				}
				else
				{
					CommandPointer = &dataset->UnitHeaders[UnitIDs[0]].Commands[CommandIDs[sel]];
				}

				UnitCommands_One->prepend(&CommandPointer->One);
				UnitCommands_ID->prepend(&CommandPointer->ID);
				UnitCommands_Unknown1->prepend(&CommandPointer->Unknown1);
				UnitCommands_Type->prepend(&CommandPointer->Type);
				UnitCommands_ClassID->prepend(&CommandPointer->ClassID);
				UnitCommands_UnitID->prepend(&CommandPointer->UnitID);
				UnitCommands_TerrainID->prepend(&CommandPointer->TerrainID);
				UnitCommands_ResourceIn->prepend(&CommandPointer->ResourceIn);
				UnitCommands_ProductivityResource->prepend(&CommandPointer->ResourceProductivityMultiplier);
				UnitCommands_ResourceOut->prepend(&CommandPointer->ResourceOut);
				UnitCommands_Resource->prepend(&CommandPointer->Resource);
				UnitCommands_WorkRateMultiplier->prepend(&CommandPointer->WorkRateMultiplier);
				UnitCommands_ExecutionRadius->prepend(&CommandPointer->ExecutionRadius);
				UnitCommands_ExtraRange->prepend(&CommandPointer->ExtraRange);
				UnitCommands_Unknown4->prepend(&CommandPointer->Unknown4);
				UnitCommands_Unknown5->prepend(&CommandPointer->Unknown5);
				UnitCommands_SelectionEnabler->prepend(&CommandPointer->SelectionEnabler);
				UnitCommands_Unknown7->prepend(&CommandPointer->Unknown7);
				UnitCommands_Unknown8->prepend(&CommandPointer->Unknown8);
				UnitCommands_Unknown9->prepend(&CommandPointer->Unknown9);
				UnitCommands_SelectionMode->prepend(&CommandPointer->SelectionMode);
				UnitCommands_Unknown11->prepend(&CommandPointer->Unknown11);
				UnitCommands_Unknown12->prepend(&CommandPointer->Unknown12);
				for(short loop = 0; loop < UnitCommands_Graphics.size(); ++loop)
				UnitCommands_Graphics[loop]->prepend(&CommandPointer->Graphics[loop]);
			}
			if(showWarning)
			{
				warning.Append("\ndiffers from civ "+lexical_cast<string>(UnitCivID));
				wxMessageBox(warning);
			}
		}
        if(NULL != CommandPointer)
		switch(CommandPointer->Type)
		{
			case 1: UnitCommands_Type_ComboBox->SetSelection(1); break;
			case 2: UnitCommands_Type_ComboBox->SetSelection(2); break;
			case 3: UnitCommands_Type_ComboBox->SetSelection(3); break;
			case 4: UnitCommands_Type_ComboBox->SetSelection(4); break;
			case 5: UnitCommands_Type_ComboBox->SetSelection(5); break;
			case 6: UnitCommands_Type_ComboBox->SetSelection(6); break;
			case 7: UnitCommands_Type_ComboBox->SetSelection(7); break;
			case 8: UnitCommands_Type_ComboBox->SetSelection(8); break;
			case 10: UnitCommands_Type_ComboBox->SetSelection(9); break;
			case 11: UnitCommands_Type_ComboBox->SetSelection(10); break;
			case 12: UnitCommands_Type_ComboBox->SetSelection(11); break;
			case 13: UnitCommands_Type_ComboBox->SetSelection(12); break;
			case 20: UnitCommands_Type_ComboBox->SetSelection(13); break;
			case 21: UnitCommands_Type_ComboBox->SetSelection(14); break;
			case 101: UnitCommands_Type_ComboBox->SetSelection(15); break;
			case 102: UnitCommands_Type_ComboBox->SetSelection(16); break;
			case 103: UnitCommands_Type_ComboBox->SetSelection(17); break;
			case 104: UnitCommands_Type_ComboBox->SetSelection(18); break;
			case 105: UnitCommands_Type_ComboBox->SetSelection(19); break;
			case 106: UnitCommands_Type_ComboBox->SetSelection(20); break;
			case 107: UnitCommands_Type_ComboBox->SetSelection(21); break;
			case 108: UnitCommands_Type_ComboBox->SetSelection(22); break;
			case 109: UnitCommands_Type_ComboBox->SetSelection(23); break;
			case 110: UnitCommands_Type_ComboBox->SetSelection(24); break;
			case 111: UnitCommands_Type_ComboBox->SetSelection(25); break;
			case 120: UnitCommands_Type_ComboBox->SetSelection(26); break;
			case 121: UnitCommands_Type_ComboBox->SetSelection(27); break;
			case 122: UnitCommands_Type_ComboBox->SetSelection(28); break;
			case 123: UnitCommands_Type_ComboBox->SetSelection(29); break;
			case 124: UnitCommands_Type_ComboBox->SetSelection(30); break;
			case 125: UnitCommands_Type_ComboBox->SetSelection(31); break;
			case 130: UnitCommands_Type_ComboBox->SetSelection(32); break;
			case 131: UnitCommands_Type_ComboBox->SetSelection(33); break;
			case 132: UnitCommands_Type_ComboBox->SetSelection(34); break;
			case 133: UnitCommands_Type_ComboBox->SetSelection(35); break;
			case 134: UnitCommands_Type_ComboBox->SetSelection(36); break;
			case 135: UnitCommands_Type_ComboBox->SetSelection(37); break;
			case 136: UnitCommands_Type_ComboBox->SetSelection(38); break;
			case 149: UnitCommands_Type_ComboBox->SetSelection(39); break;
			default: UnitCommands_Type_ComboBox->SetSelection(0);
		}
	}
    for(auto &box: uiGroupUnitCommand) box->update();
    UnitCommands_ID->Enable(false);
}

void AGE_Frame::OnUnitCommandsAdd(wxCommandEvent &event)
{
	auto selections = Units_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::UnitCommand Temp;
	Temp.setGameVersion(GenieVersion);
	if(GenieVersion >= genie::GV_AoK)
	{
		dataset->UnitHeaders[UnitIDs[0]].Commands.push_back(Temp);
		if(EnableIDFix)
		dataset->UnitHeaders[UnitIDs[0]].Commands[dataset->UnitHeaders[UnitIDs[0]].Commands.size()-1].ID = (int16_t)(dataset->UnitHeaders[UnitIDs[0]].Commands.size()-1); // ID Fix
	}
	else
	{
		for(short loop = 0; loop < dataset->Civs.size(); ++loop)
		{
			if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
			{
				dataset->Civs[loop].Units[UnitIDs[0]].Bird.Commands.push_back(Temp);
				if(EnableIDFix)
				dataset->Civs[loop].Units[UnitIDs[0]].Bird.Commands[dataset->Civs[0].Units[UnitIDs[0]].Bird.Commands.size()-1].ID = (int16_t)(dataset->Civs[0].Units[UnitIDs[0]].Bird.Commands.size()-1); // ID Fix
			}
		}
	}
	How2List = ADD;
	ListUnitCommands();
}

void AGE_Frame::OnUnitCommandsInsert(wxCommandEvent &event)
{
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	genie::UnitCommand Temp;
	Temp.setGameVersion(GenieVersion);
	if(GenieVersion >= genie::GV_AoK)
	{
		dataset->UnitHeaders[UnitIDs[0]].Commands.insert(dataset->UnitHeaders[UnitIDs[0]].Commands.begin() + CommandIDs[0], Temp);
		if(EnableIDFix)
		for(short loop2 = CommandIDs[0];loop2 < dataset->UnitHeaders[UnitIDs[0]].Commands.size(); ++loop2) // ID Fix
		dataset->UnitHeaders[UnitIDs[0]].Commands[loop2].ID = loop2;
	}
	else
	{
		for(short loop = 0; loop < dataset->Civs.size(); ++loop)
		{
			if(dataset->Civs[loop].UnitPointers[UnitIDs[0]] != 0)
			{
				dataset->Civs[loop].Units[UnitIDs[0]].Bird.Commands.insert(dataset->Civs[loop].Units[UnitIDs[0]].Bird.Commands.begin() + CommandIDs[0], Temp);
				if(EnableIDFix)
				for(short loop2 = CommandIDs[0];loop2 < dataset->Civs[0].Units[UnitIDs[0]].Bird.Commands.size(); ++loop2) // ID Fix
				dataset->Civs[loop].Units[UnitIDs[0]].Bird.Commands[loop2].ID = loop2;
			}
		}
	}
	How2List = INSNEW;
	ListUnitCommands();
}

void AGE_Frame::OnUnitCommandsDelete(wxCommandEvent &event)
{
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount(); // Gives the current list selection.
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)
	{
		for(auto loop = selections; loop--> 0;)
		dataset->UnitHeaders[UnitIDs[0]].Commands.erase(dataset->UnitHeaders[UnitIDs[0]].Commands.begin() + CommandIDs[loop]);
		if(EnableIDFix)
		for(short loop2 = CommandIDs[0];loop2 < dataset->UnitHeaders[UnitIDs[0]].Commands.size(); ++loop2) // ID Fix
		dataset->UnitHeaders[UnitIDs[0]].Commands[loop2].ID = loop2;
	}
	else
	{
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] != 0)
			if(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands.size())
			{
				for(auto loop = selections; loop--> 0;)
				dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands.erase(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands.begin() + CommandIDs[loop]);
				if(EnableIDFix)
				for(short loop2 = CommandIDs[0];loop2 < dataset->Civs[0].Units[UnitIDs[0]].Bird.Commands.size(); ++loop2) // ID Fix
				dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands[loop2].ID = loop2;
			}
		}
	}
	How2List = DEL;
	ListUnitCommands();
}

void AGE_Frame::OnUnitCommandsCopy(wxCommandEvent &event)
{
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)
	{
		copies.Dat.AllCivs |= 0x80;
		copies.Dat.UnitCommandExists.resize(0);
		copies.Dat.UnitCommands.resize(1);
		CopyFromList(dataset->UnitHeaders[UnitIDs[0]].Commands, CommandIDs, copies.Dat.UnitCommands[0]);
		return;
	}
	if(Units_SpecialCopy_Civs->GetValue()) copies.Dat.AllCivs |= 0x80; else copies.Dat.AllCivs &= ~0x80;
	if(copies.Dat.AllCivs & 0x80)
	{
		short CivCount = dataset->Civs.size();
		copies.Dat.UnitCommandExists.resize(CivCount);
		copies.Dat.UnitCommands.resize(CivCount);
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Graphic set info not usefull.
				copies.Dat.UnitCommandExists[civ] = 255;
				CivCount--;
			}
			else
			{
				// Save info of graphic set to intelligently fill possible gaps when pasting.
				copies.Dat.UnitCommandExists[civ] = 256 + dataset->Civs[civ].IconSet;
				// Only copy commands from civs which have this unit enabled.
				CopyFromList(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs, copies.Dat.UnitCommands[copy]); copy++;
			}
		}
		copies.Dat.UnitCommands.resize(CivCount);
	}
	else
	{
		CopyFromList(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands, CommandIDs, copies.Dat.UnitCommands[0]);
	}
	Units_UnitCommands_ListV->SetFocus();
}

void AGE_Frame::OnUnitCommandsPaste(wxCommandEvent &event)
{
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(Paste11)
	{
		if(Paste11Check(CommandIDs.size(), copies.Dat.UnitCommands[0].size()))
		{
			if(GenieVersion >= genie::GV_AoK)
			{
				PasteToListIDFix(dataset->UnitHeaders[UnitIDs[0]].Commands, CommandIDs, copies.Dat.UnitCommands[0]);
			}
			else if(copies.Dat.AllCivs & 0x80)
			{
				for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
				{
					if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
					{
						// Consume copies.
						if(copies.Dat.UnitCommandExists[civ] > 255) copy++; continue;
					}
					// If the target unit exists then choose from following.
					if(copies.Dat.UnitCommandExists.size() > 0 && copies.Dat.UnitCommandExists[civ] > 255 && copy < copies.Dat.UnitCommands.size())
					{
						PasteToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs, copies.Dat.UnitCommands[copy]); copy++;
					}
					else
					{
						PasteToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs, copies.Dat.UnitCommands[0]);
					}
				}
			}
			else
			{
				PasteToListIDFix(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands, CommandIDs, copies.Dat.UnitCommands[0]);
			}
		}
	}
	else
	{
		if(GenieVersion >= genie::GV_AoK)
		{
			PasteToListIDFix(dataset->UnitHeaders[UnitIDs[0]].Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
		}
		else if(copies.Dat.AllCivs & 0x80)
		{
			for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
			{
				if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
				{
					// Consume copies.
					if(copies.Dat.UnitCommandExists[civ] > 255) copy++; continue;
				}
				// If the target unit exists then choose from following.
				if(copies.Dat.UnitCommandExists.size() > 0 && copies.Dat.UnitCommandExists[civ] > 255 && copy < copies.Dat.UnitCommands.size())
				{
					PasteToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[copy]); copy++;
				}
				else
				{
					PasteToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
				}
			}
		}
		else
		{
			PasteToListIDFix(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
		}
	}
	ListUnitCommands();
}

void AGE_Frame::OnUnitCommandsPasteInsert(wxCommandEvent &event)
{
	auto selections = Units_UnitCommands_ListV->GetSelectedItemCount();
	if(selections < 1) return;

	wxBusyCursor WaitCursor;
	if(GenieVersion >= genie::GV_AoK)
	{
		PasteInsertToListIDFix(dataset->UnitHeaders[UnitIDs[0]].Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
	}
	else if(copies.Dat.AllCivs & 0x80)
	{
		for(short civ = 0, copy = 0; civ < dataset->Civs.size(); ++civ)
		{
			if(dataset->Civs[civ].UnitPointers[UnitIDs[0]] == 0)
			{
				// Consume copies.
				if(copies.Dat.UnitCommandExists[civ] > 255) copy++; continue;
			}
			// If the target unit exists then choose from following.
			if(copies.Dat.UnitCommandExists.size() > 0 && copies.Dat.UnitCommandExists[civ] > 255 && copy < copies.Dat.UnitCommands.size())
			{
				PasteInsertToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[copy]); copy++;
			}
			else
			{
				PasteInsertToListIDFix(dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
			}
		}
	}
	else
	{
		PasteInsertToListIDFix(dataset->Civs[UnitCivID].Units[UnitIDs[0]].Bird.Commands, CommandIDs[0], copies.Dat.UnitCommands[0]);
	}
	ListUnitCommands();
}

void AGE_Frame::OnUnitCommandsCopyToUnits(wxCommandEvent &event)
{
	if(GenieVersion < genie::GV_AoK)
	{
		for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		for(short loop=1; loop < UnitIDs.size(); ++loop)
		{
			dataset->Civs[civ].Units[UnitIDs[loop]].Bird.Commands = dataset->Civs[civ].Units[UnitIDs[0]].Bird.Commands;
		}
	}
	else
	{
		for(short loop=1; loop < UnitIDs.size(); ++loop)
		{
			dataset->UnitHeaders[UnitIDs[loop]].Commands = dataset->UnitHeaders[UnitIDs[0]].Commands;
		}
	}
}

void AGE_Frame::UnitLangDLLConverter(wxCommandEvent &event)
{
	int32_t DLLValue;
	try
	{
		DLLValue = lexical_cast<int32_t>(((wxTextCtrl*)event.GetEventObject())->GetValue());
	}
	catch(bad_lexical_cast e)
	{
		wxMessageBox("Incorrect input!");
		return;
	}
	if(event.GetId() == Units_LanguageDLLConverter[0]->GetId())
	{
		if(GenieVersion < genie::GV_AoKA) DLLValue += 0x10000;
		else DLLValue += 79000;
		if(!AutoCopy)
		{
			dataset->Civs[UnitCivID].Units[UnitIDs[0]].LanguageDLLHelp = DLLValue;
		}
		else for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			dataset->Civs[civ].Units[UnitIDs[0]].LanguageDLLHelp = DLLValue;
		}
	}
	else
	{
		if(GenieVersion < genie::GV_AoKA) DLLValue += 0x20000;
		else DLLValue += 140000;
		if(!AutoCopy)
		{
			dataset->Civs[UnitCivID].Units[UnitIDs[0]].LanguageDLLHotKeyText = DLLValue;
		}
		else for(short civ = 0; civ < dataset->Civs.size(); ++civ)
		{
			dataset->Civs[civ].Units[UnitIDs[0]].LanguageDLLHotKeyText = DLLValue;
		}
	}
	wxTimerEvent E;
	OnUnitsTimer(E);
}

void AGE_Frame::CreateUnitControls()
{
//	UnitControls new things

	Tab_Units = new wxPanel(TabBar_Main, wxID_ANY, wxDefaultPosition, wxSize(0, 20));

	Units_Main = new wxBoxSizer(wxHORIZONTAL);
	Units_ListArea = new wxBoxSizer(wxVERTICAL);
	Units_Units = new wxStaticBoxSizer(wxVERTICAL, Tab_Units, "Units");
	//Units_Line = new wxStaticLine(Tab_Units, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, "");
	Units_Special = new wxBoxSizer(wxHORIZONTAL);
	Units_Civs_List = new wxComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
	Units_Search = new wxTextCtrl(Tab_Units, wxID_ANY);
	Units_UseAnd[0] = new wxCheckBox(Tab_Units, wxID_ANY, "And", wxDefaultPosition, wxSize(40, 20));
	Units_Search_R = new wxTextCtrl(Tab_Units, wxID_ANY);
	Units_UseAnd[1] = new wxCheckBox(Tab_Units, wxID_ANY, "And", wxDefaultPosition, wxSize(40, 20));
	Units_FilterSelector = new wxOwnerDrawnComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_Searches[loop] = new wxBoxSizer(wxHORIZONTAL);
		Units_SearchFilters[loop] = new wxOwnerDrawnComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY | wxCB_SORT);
	}
	Units_ListV = new AGEListView(Tab_Units, wxSize(200, 100));
	Units_Buttons[0] = new wxGridSizer(3, 0, 0);
	Units_Buttons[1] = new wxGridSizer(4, 0, 0);
	Units_Add = new wxButton(Tab_Units, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
	Units_Insert = new wxButton(Tab_Units, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(5, 20));
	Units_Delete = new wxButton(Tab_Units, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
	Units_Copy = new wxButton(Tab_Units, wxID_ANY, "Copy *", wxDefaultPosition, wxSize(5, 20));
	Units_Copy->SetToolTip("When \"All civs\" is not selected,\nthis and pasting works just like automatic copy,\n(from current civilization to selected ones)\ntaking \"Including graphics\" option into account");
	Units_Paste = new wxButton(Tab_Units, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
	Units_PasteInsert = new wxButton(Tab_Units, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(5, 20));
	Units_Info = new wxStaticText(Tab_Units, wxID_ANY, " Info *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Info->SetToolTip("Add/Insert/Delete works for all civilizations\n...");
	//Units_Extract = new wxButton(Tab_Units, wxID_ANY, "Extract", wxDefaultPosition, wxSize(5, 20));
	//Units_Extract->Enable(false);
	//Units_Import = new wxButton(Tab_Units, wxID_ANY, "Import", wxDefaultPosition, wxSize(5, 20));
	//Units_Import->Enable(false);
	Units_SpecialCopy = new wxButton(Tab_Units, wxID_ANY, "S copy", wxDefaultPosition, wxSize(5, 20));
	Units_SpecialPaste = new wxButton(Tab_Units, wxID_ANY, "S paste", wxDefaultPosition, wxSize(5, 20));
	Units_Enable = new wxButton(Tab_Units, wxID_ANY, "Enable", wxDefaultPosition, wxSize(5, 20));
	Units_Disable = new wxButton(Tab_Units, wxID_ANY, "Disable", wxDefaultPosition, wxSize(5, 20));
	Units_SpecialCopy_Options = new wxOwnerDrawnComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
	Units_SpecialCopy_Civs = new wxCheckBox(Tab_Units, wxID_ANY, "All civs *", wxDefaultPosition, wxSize(-1, 20));
	Units_SpecialCopy_Civs->SetToolTip("Whether buttons of units operate on all civilizations or just on the selected one\nNote that adding, inserting and deleting units always affect all civilizations!");

	Units_FilterSelector->Append("Types 10, 15, 90, 20+");
	Units_FilterSelector->Append("Types 30+");
	Units_FilterSelector->Append("Types 40+");
	Units_FilterSelector->Append("Types 50+");
	Units_FilterSelector->Append("Type 60");
	Units_FilterSelector->Append("Types 70+");
	Units_FilterSelector->Append("Type 80");
	Units_FilterSelector->SetSelection(0);

	Units_DataArea = new wxBoxSizer(wxVERTICAL);
	Units_Top_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_TopGrid_Holder = new wxGridSizer(20, 1, 1);
	Units_AutoCopy = new wxCheckBox(Tab_Units, wxID_ANY, "Automatically", wxDefaultPosition, wxSize(-1, 20));
	Units_AutoCopy->SetToolTip("It is safer to copy automatically than manually.");
	Units_CopyTo = new wxButton(Tab_Units, wxID_ANY, "Copy", wxDefaultPosition, wxSize(40, 20));
	Units_CopyGraphics = new wxCheckBox(Tab_Units, wxID_ANY, "Including graphics", wxDefaultPosition, wxSize(-1, 20));
	Units_CopyToText = new wxStaticText(Tab_Units, wxID_ANY, " to selected civilizations: ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_SelectAll = new wxButton(Tab_Units, wxID_ANY, "All", wxDefaultPosition, wxSize(40, 20));
	Units_SelectClear = new wxButton(Tab_Units, wxID_ANY, "None", wxDefaultPosition, wxSize(40, 20));
	Units_GraphicSetText = new wxStaticText(Tab_Units, wxID_ANY, " Graphic set: ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_GraphicSet = new wxOwnerDrawnComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(120, 20), 0, NULL, wxCB_READONLY);
    visibleUnitCiv = new wxStaticText(Tab_Units, wxID_ANY, "Civ ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Identity_Holder = new wxStaticBoxSizer(wxVERTICAL, Tab_Units, "");
	Units_Type_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Type_Text = new wxStaticText(Tab_Units, wxID_ANY, "Type ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Type = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Tab_Units);
	Units_Type_ComboBox = new wxOwnerDrawnComboBox(Tab_Units, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
	Units_Class = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Tab_Units);
	Units_Class->SetToolTip("Determines many things and works in conjunction with other variables");
	Units_Class_ComboBox[0] = new ComboBox_Plus1(Tab_Units, Units_Class);
	Units_Scroller = new wxScrolledWindow(Tab_Units, wxID_ANY, wxDefaultPosition, wxSize(600, 20), wxVSCROLL | wxTAB_TRAVERSAL);
	Units_ScrollArea = new wxBoxSizer(wxHORIZONTAL);
	Units_ScrollSpace = new wxBoxSizer(wxVERTICAL);
	Units_TypeArea_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_LangDLLArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Language DLLs");
	Units_GraphicsArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Graphics");
	Units_GraphicsArea1_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_GraphicsArea4_Holder = new wxGridSizer(1, 5, 5);
	Units_GraphicsArea5_Holder = new wxGridSizer(4, 0, 5);
	Units_StatsArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Statistics");
	Units_StatsArea1_Grid = new wxGridSizer(5, 5, 5);
	Units_StatsAreaGarrison_Grid = new wxGridSizer(4, 5, 5);
	Units_StatsArea2_Grid = new wxGridSizer(4, 5, 5);
	Units_ProjectilesArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Projectiles");
	Units_ProjectilesArea1_Grid = new wxGridSizer(5, 5, 5);
	Units_ProjectilesArea2_Grid = new wxGridSizer(4, 5, 5);
	Units_ProjectilesArea3_Grid = new wxGridSizer(4, 5, 5);
	Units_Attributes_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Attributes");
	Units_AttributesBoxes1_Grid = new wxGridSizer(4, 5, 5);
	Units_Attributes1_Grid = new wxGridSizer(4, 0, 5);
	Units_Attributes2_Grid = new wxGridSizer(4, 0, 5);
	Units_AttributesTerrain_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_AttributesTerrain_Grid = new wxGridSizer(4, 5, 5);
	Units_AttributesModes1_Grid = new wxGridSizer(5, 5, 5);
	Units_AttributesDropSite_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttributesSizes_Holder = new wxGridSizer(3, 0, 5);
	Units_AttributesSelection1_Grid = new wxGridSizer(5, 5, 5);
	Units_LangRegular_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_LangHotKey_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_AttributesTracking_Grid = new wxGridSizer(4, 5, 5);
	Units_AttributesTrain1_Grid = new wxGridSizer(4, 5, 5);
	Units_Attributes3_Grid = new wxGridSizer(4, 5, 5);
	Units_SoundsArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Sounds (that only you hear)");
	Units_SoundsArea1_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_SoundsArea2_Grid = new wxGridSizer(4, 5, 5);
	Units_MiscArea_Holder = new wxStaticBoxSizer(wxHORIZONTAL, Units_Scroller, "Miscellaneous");
	Units_HPBars_Grid = new wxGridSizer(4, 5, 5);
	Units_UnknownArea_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Type10plusUnknownArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Type 10+ Unknowns (All Units)");
	Units_Type10plusUnknowns_Grid = new wxGridSizer(4, 5, 5);
	Units_Type30plusUnknownArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Type 30+ Unknowns (Dead Fish)");
	Units_Type30plusUnknownArea_Grid = new wxGridSizer(4, 5, 5);
	Units_Type70plusUnknownArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Type 70+ Unknowns (Creatable)");
	Units_Type70plusUnknownArea_Grid = new wxGridSizer(4, 5, 5);
	Units_Type80plusUnknownArea_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Type 80+ Unknowns (Building)");
	Units_Type80plusUnknownArea_Grid = new wxGridSizer(4, 5, 5);
	Units_CommandsArea_Holder = new wxStaticBoxSizer(wxHORIZONTAL, Units_Scroller, "Actions");

//	Invisible Holder Windows
//	Type 10+

	Units_ID1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLName_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLCreation_Holder = new wxBoxSizer(wxVERTICAL);
	Units_StandingGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_StandingGraphic_Grid = new wxGridSizer(2, 0, 5);
	Units_DyingGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DyingGraphic_Grid = new wxGridSizer(2, 0, 5);
	Units_DeathMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_HitPoints_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LineOfSight_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GarrisonCapacity_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SizeRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SizeRadius_Grid = new wxGridSizer(2, 0, 0);
	Units_HPBarHeight1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrainSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrainSound1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrainSound2_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrainSound3_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_DeadUnitID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_PlacementMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AirMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_IconID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_IconID_Grid = new wxGridSizer(3, 0, 5);
	Units_HideInEditor_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Unknown1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Enabled_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Disabled_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_PlacementBypassTerrain_Holder = new wxBoxSizer(wxVERTICAL);
	Units_PlacementBypassTerrainGrid_Holder = new wxGridSizer(2, 0, 5);
	Units_PlacementTerrain_Holder = new wxBoxSizer(wxVERTICAL);
	Units_PlacementTerrainGrid_Holder = new wxGridSizer(2, 0, 5);
	Units_EditorRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_EditorRadius_Grid = new wxGridSizer(2, 0, 0);
	Units_HillMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_VisibleInFog_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TerrainRestriction_Holder = new wxBoxSizer(wxVERTICAL);
	Units_FlyMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_ResourceCapacity_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ResourceDecay_Holder = new wxBoxSizer(wxVERTICAL);
	Units_BlastArmorLevel_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TriggerType_Holder = new wxBoxSizer(wxVERTICAL);
	Units_InteractionMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MinimapMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_CommandID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown3A_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MinimapColor_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLHelp_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLConverter_Holder[0] = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLConverter_Holder[1] = new wxBoxSizer(wxVERTICAL);
	Units_LanguageDLLHotKeyText_Holder = new wxBoxSizer(wxVERTICAL);
	Units_HotKey_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unselectable_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown6_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown7_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown8_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SelectionMask_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SelectionShapeType_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SelectionShape_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Attribute_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Civ_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown9_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SelectionEffect_Holder = new wxBoxSizer(wxVERTICAL);
	Units_EditorSelectionColour_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SelectionRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_HPBarHeight2_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ResourceStorageHeader_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Resource Storages");
	Units_ResourceStorage_Grid = new wxGridSizer(3, 0, 5);
	for(short loop = 0; loop < 3; ++loop)
	Units_ResourceStorage_Holder[loop] = new wxBoxSizer(wxHORIZONTAL);
	Units_SelectionSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DyingSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttackMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_EdibleMeat_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Name_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Name2_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unitline_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MinTechLevel_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ID2_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ID3_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 20+

	Units_Speed_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 30+

	Units_WalkingGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_WalkingGraphic_Grid = new wxGridSizer(2, 0, 5);
	Units_RotationSpeed_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown11_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrackingUnit_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrackingUnitUsed_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrackingUnitUsedBox_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_TrackingUnitDensity_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown16_Holder = new wxBoxSizer(wxVERTICAL);
	Units_RotationAngles_Holder = new wxBoxSizer(wxVERTICAL);
	Units_RotationAngles_Grid = new wxGridSizer(5, 5, 5);

//	Type 40+

	Units_SheepConversion_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_SearchRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_WorkRate_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DropSite_Grid = new wxGridSizer(4, 0, 5);
	Units_VillagerMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttackSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MoveSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AnimalMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Exists_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 50+

	Units_DefaultArmor_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TerRestrictionForDmgMultiply_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MaxRange_Holder = new wxBoxSizer(wxVERTICAL);
	Units_BlastRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ReloadTime1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ProjectileUnitID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AccuracyPercent_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TowerMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Delay_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GraphicDisplacement_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GraphicDisplacement_Grid = new wxGridSizer(4, 5, 5);
	Units_BlastAttackLevel_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MinRange_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AccuracyErrorRadius_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttackGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DisplayedMeleeArmour_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DisplayedAttack_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DisplayedRange_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ReloadTime2_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 60 only

	Units_StretchMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_CompensationMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DropAnimationMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_PenetrationMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown24_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ProjectileArc_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 70+

	Units_CostHeader_Holder = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Costs");
	Units_CostType_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_CostType_Grid = new wxGridSizer(3, 0, 5);
	Units_CostAmount_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_CostUsed_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_TrainTime_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TrainLocationID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ButtonID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown26_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown27_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown28_Holder = new wxBoxSizer(wxVERTICAL);
	Units_HeroMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_GarrisonGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GarrisonGraphic_Grid = new wxGridSizer(2, 0, 5);
	Units_MissileCount_Holder = new wxBoxSizer(wxVERTICAL);
	Units_MissileDuplicationCount_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttackMissileDuplicationSpawning_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AttackMissileDuplicationSpawning_Grid = new wxGridSizer(4, 5, 5);
	Units_AttackMissileDuplicationUnit_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ChargingGraphic_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ChargingMode_Holder = new wxBoxSizer(wxVERTICAL);
	Units_DisplayedPierceArmour_Holder = new wxBoxSizer(wxVERTICAL);

//	Type 80

	Units_ConstructionGraphicID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_SnowGraphicID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AdjacentMode_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_IconAngle_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown31b_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_StackUnitID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TerrainID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_OldTerrainLikeID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ResearchID_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown33_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AnnexUnit1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AnnexUnit_Grid = new wxGridSizer(4, 0, 5);
	Units_AnnexUnitMisplacement1_Holder = new wxBoxSizer(wxVERTICAL);
	Units_AnnexUnitMisplacement_Grid = new wxGridSizer(4, 0, 5);
	Units_HeadUnit_Holder = new wxBoxSizer(wxVERTICAL);
	Units_TransformUnit_Holder = new wxBoxSizer(wxVERTICAL);
	Units_UnknownSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_ConstructionSound_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GarrisonType_Holder = new wxBoxSizer(wxVERTICAL);
	Units_GarrisonHealRate_Holder = new wxBoxSizer(wxVERTICAL);
	Units_Unknown35_Holder = new wxBoxSizer(wxVERTICAL);
	Units_PileUnit_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LootSwitch_Holder = new wxBoxSizer(wxVERTICAL);
	Units_LootSwitch_Grid = new wxGridSizer(6, 0, 5);

//	Data Container Names
//	Type 10+

	Units_ID1_Text = new wxStaticText(Tab_Units, wxID_ANY, "ID 1 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLName_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Language DLL Name *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLCreation_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Language DLL Creation", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Class_Text = new wxStaticText(Tab_Units, wxID_ANY, "  Class * ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_StandingGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Standing Graphics *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DyingGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Dying Graphics", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HitPoints_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Hit Points *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LineOfSight_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Line Of Sight *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_GarrisonCapacity_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Garrison Capacity *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SizeRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Size Radius", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HPBarHeight1_Text = new wxStaticText(Units_Scroller, wxID_ANY, " HP Bar Height 1 *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TrainSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Train Sound ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DeadUnitID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Dead Unit", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_PlacementMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Placement Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_IconID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Icon *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown1_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 1 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_PlacementBypassTerrain_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Placement Side Terrain *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_PlacementTerrain_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Placement Terrain", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_EditorRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Editor Radius", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HillMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Hill Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TerrainRestriction_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Terrain Restriction ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ResourceCapacity_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Resource Capacity ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ResourceDecay_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Resource Decay *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_BlastArmorLevel_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Blast Defense Level *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TriggerType_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Sub Type *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_InteractionMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Interaction Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MinimapMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Minimap Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_CommandID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Command ID *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown3A_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 3A *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MinimapColor_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Minimap Color *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLHelp_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Language DLL Help *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLConverter_Text[0] = new wxStaticText(Units_Scroller, wxID_ANY, " Help Converter *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLConverter_Text[1] = new wxStaticText(Units_Scroller, wxID_ANY, " Hotkey Text Converter *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LanguageDLLHotKeyText_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Language DLL Hotkey Text *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HotKey_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Hotkey *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown6_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Is a resource? *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown7_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 7 *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown8_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 8 *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SelectionMask_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Mask *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SelectionShapeType_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Shape Type *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SelectionShape_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Shape *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Attribute_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unit Attribute *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Civ_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Civilization", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown9_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Attribute Piece *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SelectionEffect_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Effect *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_EditorSelectionColour_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Editor Selection Color *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SelectionRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Radius ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HPBarHeight2_Text = new wxStaticText(Units_Scroller, wxID_ANY, " HP Bar Height 2 *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	ResourceStorage_Type_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Type ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	ResourceStorage_Amount_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Amount ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	ResourceStorage_Enabled_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Enable Mode * ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_SelectionSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Sound ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DyingSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Dying Sound ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AttackMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Attack Mode? *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_EdibleMeat_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Edible Meat? *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Name_Text = new wxStaticText(Tab_Units, wxID_ANY, " Name ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Name2_Text = new wxStaticText(Tab_Units, wxID_ANY, " Name 2 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unitline_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unitline", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MinTechLevel_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Min Tech Level", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ID2_Text = new wxStaticText(Tab_Units, wxID_ANY, "ID 2 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ID3_Text = new wxStaticText(Tab_Units, wxID_ANY, "ID 3 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 20+

	Units_Speed_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Speed ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 30+

	Units_WalkingGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Walking and Running Graphics", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_RotationSpeed_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Rotation Speed *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown11_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 11", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TrackingUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Tracking Unit ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TrackingUnitUsed_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Tracking Unit Used *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TrackingUnitDensity_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Tracking Unit Density *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown16_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 16", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_RotationAngles_Label = " Rotations in Radians *";
	Units_RotationAngles_Text = new wxStaticText(Units_Scroller, wxID_ANY, Units_RotationAngles_Label, wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 40+

	Units_SearchRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Search Radius ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_WorkRate_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Work Rate ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DropSite_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Drop Site *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_VillagerMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Villager Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AttackSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Attack Sound", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MoveSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Move Sound", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Exists_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Exists", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 50+

	Units_DefaultArmor_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Default Armor *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TerRestrictionForDmgMultiply_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Terrain Restriction *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MaxRange_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Max Range", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_BlastRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Blast Radius *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ReloadTime1_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Reload Time", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ProjectileUnitID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Projectile Unit", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AccuracyPercent_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Accuracy Percent", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Delay_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Frame Delay *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_GraphicDisplacement_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Graphic Displacement XYZ *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_BlastAttackLevel_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Blast Attack Level *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MinRange_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Min Range", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AccuracyErrorRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Accuracy Error Radius *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AttackGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Attack Graphic", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DisplayedMeleeArmour_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Displayed Melee Armor", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DisplayedAttack_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Displayed Attack", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DisplayedRange_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Displayed Range", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ReloadTime2_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Displayed Reload Time", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 60 only

	Units_StretchMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Stretch Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_CompensationMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Compensation Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DropAnimationMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Drop Animation Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_PenetrationMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Penetration Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown24_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 24 *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ProjectileArc_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Projectile Arc ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 70+

	Units_CostType_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Cost Type ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_CostAmount_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Cost Amount ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_CostUsed_Text = new wxStaticText(Units_Scroller, wxID_ANY, "Cost Used ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
	Units_TrainTime_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Train Time", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TrainLocationID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Train Location", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ButtonID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Train Button *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown26_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 26 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown27_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 27 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown28_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown Type *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_GarrisonGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Garrison Graphic ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MissileCount_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Total Missiles *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_MissileDuplicationCount_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Max Total Missiles *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AttackMissileDuplicationSpawning_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Missile Spawning Area *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AttackMissileDuplicationUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Missile Dupl. Unit *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ChargingGraphic_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Charging Graphic *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ChargingMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Charging Mode? *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_DisplayedPierceArmour_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Displayed Pierce Armor ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Type 80

	Units_ConstructionGraphicID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Construction Graphic ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_SnowGraphicID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Snow Graphic ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_IconAngle_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Angle *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_StackUnitID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Stack Unit *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TerrainID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Foundation Terrain *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_OldTerrainLikeID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Old Terrain *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ResearchID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Initiates Research *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown33_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 33", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AnnexUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Annex Units", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_AnnexUnitMisplacement_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Annex Units Misplacement", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_HeadUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Head Unit *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_TransformUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Transform Unit *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_UnknownSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown Sound", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_ConstructionSound_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Construction Sound ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_GarrisonType_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Garrison Type *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_GarrisonHealRate_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Garrison Heal Rate *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_Unknown35_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Wonder Timer? *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_PileUnit_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Pile Unit *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_LootSwitch_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Looting Table *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);

//	Data Containers

	Units_ID1 = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Tab_Units, true);
	Units_ID2 = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Tab_Units, true);
	Units_ID3 = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Tab_Units, true);
	Units_Name = AGETextCtrl::init(CString, &uiGroupUnit, this, AGEwindow, Tab_Units, 30);
	Units_Name2 = AGETextCtrl::init(CString, &uiGroupUnit, this, AGEwindow, Tab_Units, 30);
	Units_LanguageDLLName = AGETextCtrl::init(CUShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_LanguageDLLName->SetToolTip("Usual Unit DLL Pattern for The Conquerors\nName: 5000-5999\nCreation: Name +1000\nHotkey: Name +11000\nHelp: Name +100000, in DLL Name +21000\nHotkey Text: Name +150000, in DLL Name +10000\nTech tree: Name +9000");
	Units_DLL_LanguageName = new TextCtrl_DLL(Units_Scroller, wxSize(0, 25));
	Units_LanguageDLLCreation = AGETextCtrl::init(CUShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DLL_LanguageCreation = new TextCtrl_DLL(Units_Scroller, wxSize(0, 25));
	Units_HotKey = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HotKey->SetToolTip("10000 + Language DLL Creation (usually)");
	Units_DLL_HotKey4 = new TextCtrl_DLL(Units_Scroller, wxSize(0, 25));
	Units_LanguageDLLHelp = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_LanguageDLLHelp->SetToolTip("100000 + Language DLL Name\nThis is probably linked to the help text below");
	Units_LanguageDLLConverter[0] = new wxTextCtrl(Units_Scroller, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	Units_LanguageDLLConverter[0]->SetToolTip("Language help text in DLL\nHit enter to get the correction into dat file");
	Units_DLL_LanguageHelp = new TextCtrl_DLL(Units_Scroller, wxSize(0, 55));
	Units_LanguageDLLHotKeyText = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_LanguageDLLHotKeyText->SetToolTip("150000 + Language DLL Name\nThis seems to be used only in AoE (not RoR)\nThis language line has other purposes in SWGB and CC");
	Units_LanguageDLLConverter[1] = new wxTextCtrl(Units_Scroller, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	Units_LanguageDLLConverter[1]->SetToolTip("Language hotkey text in DLL\nHit enter to get the correction into dat file");
	Units_DLL_LanguageHKText = new TextCtrl_DLL(Units_Scroller, wxSize(0, 25));

    wxArrayString choices;
    choices.Add("Stand 1");
    choices.Add("Stand 2");
    choices.Add("Dying 1");
    choices.Add("Dying 2");
    choices.Add("Walk");
    choices.Add("Run");
    choices.Add("Snow");
    choices.Add("Build");
    choices.Add("Attack");
    choices.Add("Housed");
    slpradio = new wxRadioBox(Units_Scroller, wxID_ANY, "SLP view", wxDefaultPosition, wxDefaultSize, choices);
	Units_DamageGraphics = new wxStaticBoxSizer(wxHORIZONTAL, Units_Scroller, "Damage Graphics");
	Units_DamageGraphics_ListArea = new wxBoxSizer(wxVERTICAL);
	Units_DamageGraphics_Search = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_DamageGraphics_Search_R = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_DamageGraphics_ListV = new AGEListView(Units_Scroller, wxSize(140, 100));
	Units_DamageGraphics_Buttons = new wxGridSizer(3, 0, 0);
	Units_DamageGraphics_Add = new wxButton(Units_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_Insert = new wxButton(Units_Scroller, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_Delete = new wxButton(Units_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_Copy = new wxButton(Units_Scroller, wxID_ANY, "Copy *", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_Copy->SetToolTip("When \"All civs\" is not selected,\nthis and pasting works only for current civilization");
	Units_DamageGraphics_Paste = new wxButton(Units_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_PasteInsert = new wxButton(Units_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_CopyToUnits = new wxButton(Units_Scroller, wxID_ANY, "Copy all to selected units", wxDefaultPosition, wxSize(5, 20));
	Units_DamageGraphics_Holder_Data = new wxBoxSizer(wxVERTICAL);
    slpdmgunit = new wxCheckBox(Units_Scroller, wxID_ANY, "View damage graphics");
	DamageGraphics_GraphicID_Holder = new wxBoxSizer(wxVERTICAL);
	DamageGraphics_GraphicID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Graphic ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	DamageGraphics_GraphicID = AGETextCtrl::init(CShort, &uiGroupUnitDmgGraphic, this, AGEwindow, Units_Scroller);
	DamageGraphics_GraphicID_ComboBox = new ComboBox_Plus1(Units_Scroller, DamageGraphics_GraphicID);
	GraphicComboBoxList.push_front(DamageGraphics_GraphicID_ComboBox);
	DamageGraphics_DamagePercent_Holder = new wxBoxSizer(wxVERTICAL);
	DamageGraphics_DamagePercent_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Damage Percent ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	DamageGraphics_DamagePercent = AGETextCtrl::init(CByte, &uiGroupUnitDmgGraphic, this, AGEwindow, Units_Scroller);
	DamageGraphics_Unknown1_Holder = new wxBoxSizer(wxVERTICAL);
	DamageGraphics_Unknown1_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Apply Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	DamageGraphics_Unknown1 = AGETextCtrl::init(CByte, &uiGroupUnitDmgGraphic, this, AGEwindow, Units_Scroller);
	DamageGraphics_Unknown1->SetToolTip("0 (& 1?) Adds graphics on top (flames on buildings)\n2 Replaces original graphics (damaged walls)");
	DamageGraphics_Unknown2_Holder = new wxBoxSizer(wxVERTICAL);
	DamageGraphics_Unknown2_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 2 ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	DamageGraphics_Unknown2 = AGETextCtrl::init(CByte, &uiGroupUnitDmgGraphic, this, AGEwindow, Units_Scroller);

	Units_IconID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_IconID->SetToolTip("Download Turtle Pack from AoKH to add more than 127 icons.");
    Units_IconID_SLP = new wxPanel(Units_Scroller, wxID_ANY, wxDefaultPosition, wxSize(55, 50));
	Units_IconAngle = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_IconAngle->SetToolTip("Tech attribute 17 changes this\n0 Default\n1+ Use icon from 2nd age etc\nIn AoE 1 can be used to set the unit\nhave icon graphics of later ages straight in stone age");
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_StandingGraphic[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_StandingGraphic[loop]->SetToolTip("Half of units in group use 1st,\nthe rest use 2nd");
		Units_StandingGraphic_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_StandingGraphic[loop]);
		GraphicComboBoxList.push_front(Units_StandingGraphic_ComboBox[loop]);
	}
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_DyingGraphic[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_DyingGraphic_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_DyingGraphic[loop]);
		GraphicComboBoxList.push_front(Units_DyingGraphic_ComboBox[loop]);
	}
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_WalkingGraphic[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_WalkingGraphic_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_WalkingGraphic[loop]);
		GraphicComboBoxList.push_front(Units_WalkingGraphic_ComboBox[loop]);
	}
	Units_SnowGraphicID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SnowGraphicID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_SnowGraphicID);
	GraphicComboBoxList.push_front(Units_SnowGraphicID_ComboBox);
	Units_ConstructionGraphicID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ConstructionGraphicID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_ConstructionGraphicID);
	GraphicComboBoxList.push_front(Units_ConstructionGraphicID_ComboBox);
	Units_AttackGraphic = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AttackGraphic_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_AttackGraphic);
	GraphicComboBoxList.push_front(Units_AttackGraphic_ComboBox);
	Units_GarrisonGraphic = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GarrisonGraphic_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_GarrisonGraphic);
	GraphicComboBoxList.push_front(Units_GarrisonGraphic_ComboBox);

	Units_HitPoints = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HitPoints->SetToolTip("-1 Instantly dying unit");
	Units_Speed = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_RotationSpeed = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_RotationSpeed->SetToolTip("Makes it slower");
	Units_LineOfSight = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_LineOfSight->SetToolTip("Maximum (effective) value is 20");
	Units_SearchRadius = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MaxRange = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MinRange = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DisplayedRange = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);

	Units_Attacks = new wxStaticBoxSizer(wxHORIZONTAL, Units_Scroller, "Attacks");
	Units_Attacks_ListArea = new wxBoxSizer(wxVERTICAL);
	Units_Attacks_DataArea = new wxBoxSizer(wxVERTICAL);
	Units_Attacks_Search = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_Attacks_Search_R = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_Attacks_ListV = new AGEListView(Units_Scroller, wxSize(140, 100));
	Units_Attacks_Buttons = new wxGridSizer(3, 0, 0);
	Units_Attacks_Add = new wxButton(Units_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_Insert = new wxButton(Units_Scroller, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_Delete = new wxButton(Units_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_Copy = new wxButton(Units_Scroller, wxID_ANY, "Copy *", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_Copy->SetToolTip("When \"All civs\" is not selected,\nthis and pasting works only for current civilization");
	Units_Attacks_Paste = new wxButton(Units_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_PasteInsert = new wxButton(Units_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_CopyToUnits = new wxButton(Units_Scroller, wxID_ANY, "Copy all to selected units", wxDefaultPosition, wxSize(5, 20));
	Units_Attacks_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Attacks_Holder_Data = new wxBoxSizer(wxVERTICAL);
	Units_Attacks_Grid_Data2 = new wxGridSizer(2, 5, 5);
	Attacks_Amount_Holder = new wxBoxSizer(wxVERTICAL);
	Attacks_Amount_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Amount", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Attacks_Amount = AGETextCtrl::init(CShort, NULL, this, AGEwindow, Units_Scroller);
	Attacks_Class_Holder = new wxBoxSizer(wxVERTICAL);
	Attacks_Class_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Class *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Attacks_Class = AGETextCtrl::init(CShort, NULL, this, AGEwindow, Units_Scroller);
	Attacks_Class->SetToolTip("Armor class that this unit can damage\nYou can make your own classes");
	Attacks_Class_ComboBox[0] = new ComboBox_Plus1(Units_Scroller, Attacks_Class);

	Units_DisplayedAttack = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Delay = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Delay->SetToolTip("Graphical delay in frames before projectile is shot");
	Units_AccuracyPercent = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AccuracyErrorRadius = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AccuracyErrorRadius->SetToolTip("Higher values will make the unit less accurate");
	Units_ReloadTime1 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ReloadTime2 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_BlastRadius = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_BlastRadius->SetToolTip("If object has 0 blast radius\nand does not hit the unit it had targeted\nalways does half damage");
	Units_BlastAttackLevel = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_BlastAttackLevel->SetToolTip("Blasts damage units that have higher or same blast armor level\n0 Damages resources also\n1 Damages trees also\n2 Damages nearby units\n3 Damages only targeted unit");

	Units_Armors = new wxStaticBoxSizer(wxHORIZONTAL, Units_Scroller, "Armors");
	Units_Armors_ListArea = new wxBoxSizer(wxVERTICAL);
	Units_Armors_DataArea = new wxBoxSizer(wxVERTICAL);
	Units_Armors_Search = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_Armors_Search_R = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_Armors_ListV = new AGEListView(Units_Scroller, wxSize(140, 100));
	Units_Armors_Buttons = new wxGridSizer(3, 0, 0);
	Units_Armors_Add = new wxButton(Units_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_Insert = new wxButton(Units_Scroller, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_Delete = new wxButton(Units_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_Copy = new wxButton(Units_Scroller, wxID_ANY, "Copy *", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_Copy->SetToolTip("When \"All civs\" is not selected,\nthis and pasting works only for current civilization");
	Units_Armors_Paste = new wxButton(Units_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_PasteInsert = new wxButton(Units_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_CopyToUnits = new wxButton(Units_Scroller, wxID_ANY, "Copy all to selected units", wxDefaultPosition, wxSize(5, 20));
	Units_Armors_Holder = new wxBoxSizer(wxHORIZONTAL);
	Units_Armors_Holder_Data3 = new wxBoxSizer(wxVERTICAL);
	Armors_Amount_Holder = new wxBoxSizer(wxVERTICAL);
	Armors_Amount_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Amount", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Armors_Amount = AGETextCtrl::init(CShort, NULL, this, AGEwindow, Units_Scroller);
	Armors_Class_Holder = new wxBoxSizer(wxVERTICAL);
	Armors_Class_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Class *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Armors_Class = AGETextCtrl::init(CShort, NULL, this, AGEwindow, Units_Scroller);
	Armors_Class->SetToolTip("Attack class from which this unit can take damage\nYou can make your own classes");
	Attacks_Class_ComboBox[1] = new ComboBox_Plus1(Units_Scroller, Armors_Class);

	Units_DefaultArmor = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DefaultArmor->SetToolTip("This armor is used for all attack types that do not have corresponding armor type\nCan be negative only in The Conquerors and later games");
	Units_TerRestrictionForDmgMultiply = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TerRestrictionForDmgMultiply->SetToolTip("Receive damage based on which terrain this unit stands on\nTech attribute 18 changes this\nThe damage received by this unit is\nmultiplied by the accessible values on\nthe specified terrain restriction");
	Units_TerRestrictionForDmgMultiply_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TerRestrictionForDmgMultiply);
	TerrainRestrictionComboBoxList.push_front(Units_TerRestrictionForDmgMultiply_ComboBox);
	Units_DisplayedMeleeArmour = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DisplayedPierceArmour = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_BlastArmorLevel = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_BlastArmorLevel->SetToolTip("Receive blast damage from units that have lower or same blast attack level");

	Units_ResourceCapacity = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ResourceDecay = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ResourceDecay->SetToolTip("Can alter corpses' decay time\nSet to -1 for never decaying");
	Units_WorkRate = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GarrisonCapacity = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GarrisonCapacity->SetToolTip("If the unit has garrisoned units inside,\ngraphics tab \"New Speed?\" determines its new speed?");
	Units_GarrisonType = AGETextCtrl::init(CUByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GarrisonType_Grid = new wxGridSizer(8, 0, 0);
	for(short loop = 0; loop < 8; ++loop)
	Units_GarrisonType_CheckBox[loop] = new wxCheckBox(Units_Scroller, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 20));
	Units_GarrisonType_CheckBox[0]->SetToolTip("Villager/Worker");
	Units_GarrisonType_CheckBox[1]->SetToolTip("Infantry");
	Units_GarrisonType_CheckBox[2]->SetToolTip("Cavalry/Mounted");
	Units_GarrisonType_CheckBox[3]->SetToolTip("Monk/Jedi");
	Units_GarrisonType_CheckBox[4]->SetToolTip("SW: Livestock");
	Units_GarrisonHealRate = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GarrisonHealRate->SetToolTip("Building's garrisoned units' healing speed factor");

	Units_ProjectileUnitID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ProjectileUnitID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_ProjectileUnitID);
	UnitComboBoxList.push_front(Units_ProjectileUnitID_ComboBox);
	Units_AttackMissileDuplicationUnit = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AttackMissileDuplicationUnit->SetToolTip("Uses its own attack values!");
	Units_AttackMissileDuplicationUnit_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_AttackMissileDuplicationUnit);
	UnitComboBoxList.push_front(Units_AttackMissileDuplicationUnit_ComboBox);
	Units_ChargingGraphic = AGETextCtrl::init(CLong, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ChargingGraphic->SetToolTip("Used just before the unit reaches its target enemy");
	Units_ChargingGraphic_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_ChargingGraphic);
	GraphicComboBoxList.push_front(Units_ChargingGraphic_ComboBox);
	Units_ChargingMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ChargingMode->SetToolTip("0 Default\n3 Unit must walk to enemy when ordered to attack it\nAttack duplication graphics activate too");
	Units_MissileCount = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MissileCount->SetToolTip("Total missiles including both normal and duplicated projectiles");
	Units_MissileDuplicationCount = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MissileDuplicationCount->SetToolTip("Total missiles when garrison capacity is full");
	for(short loop = 0; loop < 3; ++loop)
	Units_AttackMissileDuplicationSpawning[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AttackMissileDuplicationSpawning[0]->SetToolTip("Spawning area's width");
	Units_AttackMissileDuplicationSpawning[1]->SetToolTip("Spawning area's length");
	Units_AttackMissileDuplicationSpawning[2]->SetToolTip("Spawning point's randomness inside the spawning area\n0 from a single spot\n1 Totally randomly inside the spawning area\n1+ Less randomly");
	for(short loop = 0; loop < 3; ++loop)
	Units_GraphicDisplacement[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_GraphicDisplacement[0]->SetToolTip("Left/Right distance");
	Units_GraphicDisplacement[1]->SetToolTip("Spawning distance from the unit");
	Units_GraphicDisplacement[2]->SetToolTip("Height");

	Units_StretchMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_StretchMode->SetToolTip("0 Default\n1 Projectile falls vertically to the bottom of the map\n3 Teleporting projectiles");
	Units_CompensationMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_CompensationMode->SetToolTip("Tech attribute 19 changes this\n0 Shoot where the target is now\n1 Shoot where the target is going to be");
	Units_DropAnimationMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DropAnimationMode->SetToolTip("0 Doesn't disappear after hitting the target\n1 Disappears\n2 SWGB artillery fire has this");
	Units_PenetrationMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_PenetrationMode->SetToolTip("0 Stops the graphics\n1 Graphics pass through the target instead of stopping\nOnly affects the graphics of the projectile");
	Units_Unknown24 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown24->SetToolTip("Bullets have this as 1");
	Units_ProjectileArc = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);

	Units_Enabled = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Enabled->SetToolTip("0 Requires a research to be available\n1 Available without a research");
	Units_Enabled_CheckBox = new CheckBox_2State(Units_Scroller, "No Research *", Units_Enabled);
	Units_Disabled = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Disabled->SetToolTip("0 Default\n1 Prevents enabling/disabling with a tech");
	Units_Disabled_CheckBox = new CheckBox_2State(Units_Scroller, "Disabled *", Units_Disabled);
	Units_DeathMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DeathMode->SetToolTip("Reviving does not make it usable");
	Units_DeathMode_CheckBox = new CheckBox_2State(Units_Scroller, "Death: Revives *", Units_DeathMode);
	Units_HideInEditor = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HideInEditor_CheckBox = new CheckBox_2State(Units_Scroller, "Hide in Editor", Units_HideInEditor);
	Units_AirMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AirMode->SetToolTip("1 for no footprints");
	Units_AirMode_CheckBox = new CheckBox_2State(Units_Scroller, "Air Mode *", Units_AirMode);
	Units_FlyMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_FlyMode->SetToolTip("Requires class 22 and air mode 1?\n0 Normal\n1 Graphics appear higher than the shadow");
	Units_FlyMode_CheckBox = new CheckBox_2State(Units_Scroller, "Fly Mode *", Units_FlyMode);
	Units_SheepConversion = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller, true);
	Units_SheepConversion->SetToolTip("To get the unit auto-converted to enemy,\nuse unit command 107, which sheep and monument have\nAll somehow auto-convertible units have this set to 0\nMost other units have -1");
	Units_SheepConversion_CheckBox = new CheckBox_ZeroIsYes(Units_Scroller, "Convert Herd *", Units_SheepConversion);
	Units_AnimalMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AnimalMode_CheckBox = new CheckBox_2State(Units_Scroller, "Animal Mode", Units_AnimalMode);
	Units_AdjacentMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AdjacentMode->SetToolTip("0 Default\n1 Adjacent buildings can change this unit's graphics");
	Units_AdjacentMode_CheckBox = new CheckBox_2State(Units_Scroller, "Adjacent Mode *", Units_AdjacentMode);
	Units_DisappearsWhenBuilt = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DisappearsWhenBuilt->SetToolTip("Useful for stack unit placement\n0 Default\n1 Makes the building disappear when built");
	Units_Unknown31b_CheckBox = new CheckBox_2State(Units_Scroller, "Built: Vanishes *", Units_DisappearsWhenBuilt);
	Units_TowerMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TowerMode_CheckBox = new CheckBox_2State(Units_Scroller, "Tower Mode", Units_TowerMode);
	Units_HeroMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HeroMode_CheckBox = new CheckBox_2State(Units_Scroller, "Hero Mode", Units_HeroMode);

	Units_PlacementMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_PlacementMode->SetToolTip("0 Can be placed on top of other units in scenario editor\n5 Cannot be placed on top of other units in scenario editor");
	Units_HillMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HillMode->SetToolTip("0 No restriction\n2 Restricts placement to flat land\n3 Allows placement on hills for the most part");
	Units_VisibleInFog_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Fog Visibility *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_VisibleInFog = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_VisibleInFog->SetToolTip("0 Not visible\n1 Visible\n3 Inverted visibility");
	Units_TriggerType = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TriggerType->SetToolTip("Mainly used in trigger conditions\n0 Projectile/Dead/Resource\n1 Boar\n2 Building\n3 Civilian\n4 Military\n5 Priest\n");
	Units_InteractionMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_InteractionMode->SetToolTip("0 & 1 Unable to select, move or attack\n2 Can select, unable to move or attack\n3 Can select and attack, unable to move\n4 Can select, move and attack\n5+ Select and move?");
	Units_MinimapMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MinimapMode->SetToolTip("0 & 6-10 No dot on minimap\n1 Square dot turning white when selected\n2 Diamond dot turning white when selected\n3 Diamond dot keeping color\n4 & 5 Larger spot, not following the unit, no blinking when attacked, everyone can see it\n");
	Units_MinimapColor = AGETextCtrl::init(CUByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MinimapColor->SetToolTip("Minimap modes 3 and 4 allow this to work");
	Units_AttackMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AttackMode->SetToolTip("This may be attack mode\n0 No attacck\n1 Attack by following\n2 Run when attacked\n3 ?\n4 Attack\n");
	Units_EdibleMeat = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_EdibleMeat->SetToolTip("0 Default\n1 Rotting meat that can be gathered");
	Units_VillagerMode = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_VillagerMode->SetToolTip("Changes according to task\n1 Male\n2 Female");

	Units_Attribute = AGETextCtrl::init(CUByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Attribute->SetToolTip("This is a byte of eight booleans\nYou can combine these attributes");
	Units_Attribute_Grid = new wxGridSizer(8, 0, 0);
	for(short loop = 0; loop < 8; ++loop)
	Units_Attribute_CheckBox[loop] = new wxCheckBox(Units_Scroller, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 20));
	Units_Attribute_CheckBox[0]->SetToolTip("Garrison unit");
	Units_Attribute_CheckBox[1]->SetToolTip("Ship unit");
	Units_Attribute_CheckBox[2]->SetToolTip("SW: Stealth unit");
	Units_Attribute_CheckBox[3]->SetToolTip("SW: Detector unit");
	Units_Attribute_CheckBox[4]->SetToolTip("SW: Mechanical unit");
	Units_Attribute_CheckBox[5]->SetToolTip("SW: Biological unit");
	Units_Attribute_CheckBox[6]->SetToolTip("SW: Self-shielding unit");
	Units_Attribute_CheckBox[7]->SetToolTip("SW: Invisible unit");
	Units_Civ = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Civ_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_Civ);
	CivComboBoxList.push_front(Units_Civ_ComboBox);
	Units_Unknown9 = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown9->SetToolTip("This is actually leftover from attribute+civ variable\nProbably useless");
	Units_DeadUnitID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DeadUnitID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_DeadUnitID);
	UnitComboBoxList.push_front(Units_DeadUnitID_ComboBox);
	Units_Unitline = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unitline_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_Unitline);
	Units_MinTechLevel = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MinTechLevel_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_MinTechLevel);
	ResearchComboBoxList.push_front(Units_MinTechLevel_ComboBox);
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_PlacementTerrain[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_PlacementTerrain_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_PlacementTerrain[loop]);
		TerrainComboBoxList.push_front(Units_PlacementTerrain_ComboBox[loop]);
	}
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_PlacementBypassTerrain[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_PlacementBypassTerrain[loop]->SetToolTip("Required terrain on some side");
		Units_PlacementBypassTerrain_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_PlacementBypassTerrain[loop]);
		TerrainComboBoxList.push_front(Units_PlacementBypassTerrain_ComboBox[loop]);
	}
	Units_TerrainRestriction = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TerrainRestriction_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TerrainRestriction);
	TerrainRestrictionComboBoxList.push_front(Units_TerrainRestriction_ComboBox);
	Units_TerrainID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TerrainID->SetToolTip("Terrain produced under a building when completed");
	Units_TerrainID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TerrainID);
	TerrainComboBoxList.push_front(Units_TerrainID_ComboBox);
	Units_OldTerrainLikeID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_OldTerrainLikeID->SetToolTip("ES forgot to remove this before AoE was released.\nThis points to removed data block\nthat was like terrain borders.\nYou could build roads back in 1996.");
	Units_ResearchID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ResearchID->SetToolTip("Causes that research to be researched when the building is created");
	Units_ResearchID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_ResearchID);
	ResearchComboBoxList.push_front(Units_ResearchID_ComboBox);
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_DropSite[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_DropSite[loop]->SetToolTip("Giving a villager's drop site to a cart-like unit\ncan allow you to have mobile resource-gatherers,\nsimilar to those in Age of Mythology.");
		Units_DropSite_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_DropSite[loop]);
		UnitComboBoxList.push_front(Units_DropSite_ComboBox[loop]);
	}
	for(short loop = 0; loop < 2; ++loop)
	Units_SizeRadius[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller, true);
	for(short loop = 0; loop < 2; ++loop)
	Units_EditorRadius[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller, true);
	Units_SelectionRadiusBox = new wxBoxSizer(wxHORIZONTAL);
	for(short loop = 0; loop < 2; ++loop)
	Units_SelectionRadius[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller, true);
	Units_Unselectable = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unselectable_CheckBox = new CheckBox_2State(Units_Scroller, "Unselectable", Units_Unselectable);
	Units_Unknown6 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown6->SetToolTip("Seems to be 1 on all resource deposits");
	Units_Unknown7 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown7->SetToolTip("0 Default\n1 Resource/Eye Candy\n2 Tree");
	Units_Unknown8 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown8->SetToolTip("Depends on unknowns 6 and 7:\nis a resource? and unknown selection mode\n0 wood?\n1 berry\n2 fish\n3 stone/ore deposit\n4 gold/nova deposit\n5 ore (not SW) deposit?");
	Units_SelectionMask = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SelectionMask->SetToolTip("Any odd value except 7 - Mask displayed behind buildings\nAny even value except 6, 10 - Mask not displayed\n-1, 7 - Mask partially displayed when in the open\n6, 10 - Building, causes mask to appear on units behind it\n");
	Units_SelectionShapeType = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SelectionShapeType->SetToolTip("Seems to control 3 things\nIf square or round, value 5\nIf real size or selection size is used, value 2\nIf walkable or not, value 0");
	Units_SelectionShape = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SelectionShape->SetToolTip("0 Square\n1+ Round");
	Units_SelectionEffect = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SelectionEffect->SetToolTip("0\n1 HP Bar on, permanent darker outline in editor only\n4 HP Bar off, normal outline\n5, 8-9 HP Bar on\n2 HP Bar on, normal outline\n3 HP Bar off, selection shadow\n6-7 HP Bar off\nNote: this doesn't work with all units");
	Units_EditorSelectionColour = AGETextCtrl::init(CUByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_EditorSelectionColour->SetToolTip("0 most\n-16 fish trap farm\n52 dead farm, OLD-(___)\n116 flare, WHAL1, WHAL2, DOLP, Great-fish\n-123 all fish");
	Units_TrackingUnit = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TrackingUnit_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TrackingUnit);
	UnitComboBoxList.push_front(Units_TrackingUnit_ComboBox);
	Units_TrackingUnitUsed = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TrackingUnitUsed->SetToolTip("-1 unless a tracking unit value is present\n2 all projectiles with a tracking unit");
	Units_TrackingUnitDensity = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TrackingUnitDensity->SetToolTip("0 unless tracking unit value is present\n0.5 trade carts\n0.12 MFFFG(projectile)\n0.4 other projectiles");
	for(short loop = 0; loop < Units_RotationAngles.size(); ++loop)
	Units_RotationAngles[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	wxString rot360 = "360 degrees when multiplying with 4th box radian value";
	Units_RotationAngles[2]->SetToolTip(rot360);
	Units_RotationAngles[3]->SetToolTip("Used to get 3rd and 5th box to 360 degrees");
	Units_RotationAngles[4]->SetToolTip(rot360);
	Units_CommandID = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_CommandID->SetToolTip("Class and this sets the interface for this unit\n0 Flag\n1 Livestock\n2 Civilian Building (build page 1)\n3 Villager\n4 Military Unit\n5 Trade Unit\n6 Monk\n7 Transport Ship\n8 Relic / Monk with Relic\n9 Fishing Ship\n10 Military Building (build page 2)\n11 Shield Building (build page 3)");
	Units_TrainTime = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TrainLocationID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TrainLocationID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TrainLocationID);
	UnitComboBoxList.push_front(Units_TrainLocationID_ComboBox);
	Units_ButtonID = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ButtonID->SetToolTip("First page (also second in TC) 1-15\nSecond (dock) page 21-35\nThird page same as first (Star Wars)\nFirst page in AoE/RoR 1-10\nSecond page in AoE/RoR 11-20");
	for(short loop = 0; loop < 3; ++loop)
	{
		ResourceStorage_Type[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		ResourceStorage_Type_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, ResourceStorage_Type[loop]);
		ResourceComboBoxList.push_front(ResourceStorage_Type_ComboBox[loop]);
		ResourceStorage_Amount[loop] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		ResourceStorage_Enabled[loop] = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		ResourceStorage_Enabled[loop]->SetToolTip("0 Decayable resource\n1 Stored after death also\n2 Resets on dying, enables instantly\n4 Resets on dying, enables on completion");
	}
	for(short loop = 0; loop < 3; ++loop)
	{
		Units_CostType[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_CostType_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_CostType[loop]);
		ResourceComboBoxList.push_front(Units_CostType_ComboBox[loop]);
		Units_CostAmount[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_CostUsed[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_CostUsed[loop]->SetToolTip("If set to 0 and there is an amount, the amount is required but not paid");
		Units_CostUsed_CheckBox[loop] = new CheckBox_2State(Units_Scroller, "Used", Units_CostUsed[loop]);
	}
	Units_StackUnitID = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_StackUnitID->SetToolTip("Second building to be placed directly on top of this building\nAdditional building gets added every time you load the scenario");
	Units_StackUnitID_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_StackUnitID);
	UnitComboBoxList.push_front(Units_StackUnitID_ComboBox);
	Units_HeadUnit = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HeadUnit->SetToolTip("The building that an annex building is attached to");
	Units_HeadUnit_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_HeadUnit);
	UnitComboBoxList.push_front(Units_HeadUnit_ComboBox);
	Units_TransformUnit = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_TransformUnit->SetToolTip("Determines what the unit changes into when given the order to unpack");
	Units_TransformUnit_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_TransformUnit);
	UnitComboBoxList.push_front(Units_TransformUnit_ComboBox);
	Units_PileUnit = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_PileUnit->SetToolTip("Appears when the building dies\nDoes not appear with delete command");
	Units_PileUnit_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_PileUnit);
	UnitComboBoxList.push_front(Units_PileUnit_ComboBox);
	for(short loop = 0; loop < 4; ++loop)
	{
		Units_AnnexUnit[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_AnnexUnit_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_AnnexUnit[loop]);
		UnitComboBoxList.push_front(Units_AnnexUnit_ComboBox[loop]);
	}
	for(short loop = 0; loop < 4; ++loop)
	{
		for(short loop2 = 0; loop2 < 2; ++loop2)
		Units_AnnexUnitMisplacement[loop][loop2] = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	}
	for(short loop = 0; loop < Units_LootSwitch.size(); ++loop)
	Units_LootSwitch[loop] = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_LootSwitch[0]->SetToolTip("Stone Loot Switch");
	Units_LootSwitch[1]->SetToolTip("Wood Loot Switch");
	Units_LootSwitch[2]->SetToolTip("Ore Loot Switch");
	Units_LootSwitch[3]->SetToolTip("Gold Loot Switch");
	Units_LootSwitch[4]->SetToolTip("Food Loot Switch");
	Units_LootSwitch[5]->SetToolTip("Goods Loot Switch");

	Units_SelectionSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_SelectionSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_SelectionSound);
	SoundComboBoxList.push_front(Units_SelectionSound_ComboBox);
	Units_DyingSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_DyingSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_DyingSound);
	SoundComboBoxList.push_front(Units_DyingSound_ComboBox);
	for(short loop = 0; loop < 2; ++loop)
	{
		Units_TrainSound[loop] = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
		Units_TrainSound_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, Units_TrainSound[loop]);
		SoundComboBoxList.push_front(Units_TrainSound_ComboBox[loop]);
	}
	Units_AttackSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_AttackSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_AttackSound);
	SoundComboBoxList.push_front(Units_AttackSound_ComboBox);
	Units_MoveSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_MoveSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_MoveSound);
	SoundComboBoxList.push_front(Units_MoveSound_ComboBox);
	Units_ConstructionSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_ConstructionSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_ConstructionSound);
	SoundComboBoxList.push_front(Units_ConstructionSound_ComboBox);
	Units_UnknownSound = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_UnknownSound_ComboBox = new ComboBox_Plus1(Units_Scroller, Units_UnknownSound);
	SoundComboBoxList.push_front(Units_UnknownSound_ComboBox);

	Units_HPBarHeight1 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HPBarHeight1->SetToolTip("Setting \"Air Mode\" to 1 and this to 0 causes farms to be walkable in AoE/RoR");
	Units_HPBarHeight2 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_HPBarHeight2->SetToolTip("Vertical distance from ground");

	Units_Unknown1 = AGETextCtrl::init(CShort, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown3A = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown3A->SetToolTip("Seems to be 1 on more or less living things");

	Units_Unknown11 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown16 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);

	Units_Unknown26 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown27 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown28 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown28->SetToolTip("0 Building, animal\n1 Villager\n2 Melee\n3 Mounted unit\n4 Relic\n5 Archer\n6 Monk");

	Units_Unknown33 = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	//Units_Unknown33->SetToolTip("0 Default\n1 Counts as player being alive?");
	Units_Unknown35 = AGETextCtrl::init(CFloat, &uiGroupUnit, this, AGEwindow, Units_Scroller);
	Units_Unknown35->SetToolTip("Probably related to garrison heal");

	Units_CommandHolder_Lists = new wxBoxSizer(wxVERTICAL);
	Units_UnitHeads_Name = new wxStaticText(Units_Scroller, wxID_ANY, "Unit Header", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	Units_UnitCommands = new wxStaticBoxSizer(wxVERTICAL, Units_Scroller, "Actions");
	Units_UnitCommands_Search = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_UnitCommands_Search_R = new wxTextCtrl(Units_Scroller, wxID_ANY);
	Units_UnitCommands_ListV = new AGEListView(Units_Scroller, wxSize(140, 190));
	Units_UnitCommands_Buttons = new wxGridSizer(3, 0, 0);
	Units_UnitCommands_Add = new wxButton(Units_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_Insert = new wxButton(Units_Scroller, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_Delete = new wxButton(Units_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_Copy = new wxButton(Units_Scroller, wxID_ANY, "Copy *", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_Copy->SetToolTip("When \"All civs\" is not selected,\nthis and pasting works only for current civilization");
	Units_UnitCommands_Paste = new wxButton(Units_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_PasteInsert = new wxButton(Units_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(5, 20));
	Units_UnitCommands_CopyToUnits = new wxButton(Units_Scroller, wxID_ANY, "Copy all to selected units", wxDefaultPosition, wxSize(5, 20));
	Units_CommandHolder_Data = new wxBoxSizer(wxVERTICAL);
	Units_CommandHolder_Data1 = new wxBoxSizer(wxHORIZONTAL);
	Units_CommandHolder_Data2 = new wxBoxSizer(wxVERTICAL);
	Units_CommandHolder_Grid1 = new wxGridSizer(2, 5, 5);
	Units_CommandHolder_Grid2 = new wxGridSizer(2, 5, 5);
	Units_CommandHolder_Grid3 = new wxGridSizer(1, 5, 5);
	Units_Exists = AGETextCtrl::init(CByte, &uiGroupUnit, this, AGEwindow, Units_Scroller);

	UnitCommands_1_Holder = new wxBoxSizer(wxHORIZONTAL);
	UnitCommands_One_Holder = new wxBoxSizer(wxHORIZONTAL);
	UnitCommands_One_Text = new wxStaticText(Units_Scroller, wxID_ANY, "One ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_One = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ID_Holder = new wxBoxSizer(wxHORIZONTAL);
	UnitCommands_ID_Text = new wxStaticText(Units_Scroller, wxID_ANY, "ID ", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ID = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Type_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Type_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Action Type", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Type = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Type_ComboBox = new wxOwnerDrawnComboBox(Units_Scroller, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
	UnitCommands_ClassID_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ClassID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Class", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ClassID = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	Units_Class_ComboBox[1] = new ComboBox_Plus1(Units_Scroller, UnitCommands_ClassID);
	UnitCommands_UnitID_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_UnitID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unit", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_UnitID = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_UnitID_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_UnitID);
	UnitComboBoxList.push_front(UnitCommands_UnitID_ComboBox);
	UnitCommands_TerrainID_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_TerrainID_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Terrain", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_TerrainID = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
    UnitCommands_TerrainID_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_TerrainID);
	TerrainComboBoxList.push_front(UnitCommands_TerrainID_ComboBox);
	UnitCommands_ResourceIn_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ResourceIn_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Resource In *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ResourceIn = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ResourceIn->SetToolTip("Carry resource");
	UnitCommands_ResourceIn_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_ResourceIn);
	ResourceComboBoxList.push_front(UnitCommands_ResourceIn_ComboBox);
	UnitCommands_ProductivityResource_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ProductivityResource_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Productivity Resource *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ProductivityResource = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ProductivityResource->SetToolTip("Resource that multiplies the amount you can gather");
	UnitCommands_ProductivityResource_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_ProductivityResource);
	ResourceComboBoxList.push_front(UnitCommands_ProductivityResource_ComboBox);
	UnitCommands_ResourceOut_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ResourceOut_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Resource Out *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ResourceOut = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ResourceOut->SetToolTip("Drop resource");
	UnitCommands_ResourceOut_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_ResourceOut);
	ResourceComboBoxList.push_front(UnitCommands_ResourceOut_ComboBox);
	UnitCommands_Resource_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Resource_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Resource", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Resource = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Resource_ComboBox = new ComboBox_Plus1(Units_Scroller, UnitCommands_Resource);
	ResourceComboBoxList.push_front(UnitCommands_Resource_ComboBox);
	UnitCommands_WorkRateMultiplier_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_WorkRateMultiplier_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Work Rate Multiplier", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_WorkRateMultiplier = AGETextCtrl::init(CFloat, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ExecutionRadius_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ExecutionRadius_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Execution Radius", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ExecutionRadius = AGETextCtrl::init(CFloat, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_ExtraRange_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_ExtraRange_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Extra Range", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_ExtraRange = AGETextCtrl::init(CFloat, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Graphics_Grid = new wxGridSizer(3, 5, 5);
	for(short loop = 0; loop < UnitCommands_Graphics.size(); ++loop)
	{
		UnitCommands_Graphics_Holder[loop] = new wxBoxSizer(wxVERTICAL);
		UnitCommands_Graphics[loop] = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
		UnitCommands_Graphics_ComboBox[loop] = new ComboBox_Plus1(Units_Scroller, UnitCommands_Graphics[loop]);
	}
	for(short loop = 0; loop < 4; ++loop)
	GraphicComboBoxList.push_front(UnitCommands_Graphics_ComboBox[loop]);
	for(short loop = 4; loop < 6; ++loop)
	SoundComboBoxList.push_front(UnitCommands_Graphics_ComboBox[loop]);
	UnitCommands_Graphics_Text[0] = new wxStaticText(Units_Scroller, wxID_ANY, " Tool Graphic *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[0]->SetToolTip("Used when walking with a tool, but carrying no resources");
	UnitCommands_Graphics_Text[1] = new wxStaticText(Units_Scroller, wxID_ANY, " Proceeding Graphic *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[1]->SetToolTip("Used when proceeding to gather a resource or attack");
	UnitCommands_Graphics_Text[2] = new wxStaticText(Units_Scroller, wxID_ANY, " Action Graphic *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[2]->SetToolTip("Used when actually gathering a resource or attacking/converting");
	UnitCommands_Graphics_Text[3] = new wxStaticText(Units_Scroller, wxID_ANY, " Carrying Graphic *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[3]->SetToolTip("Used when carrying a resource");
	UnitCommands_Graphics_Text[4] = new wxStaticText(Units_Scroller, wxID_ANY, " Execution Sound *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[4]->SetToolTip("Example: Plays when lumberjack starts chopping wood");
	UnitCommands_Graphics_Text[5] = new wxStaticText(Units_Scroller, wxID_ANY, " Resource Deposit Sound *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Graphics[5]->SetToolTip("Example: Plays when lumberjack drops his wood into TC");
	UnitCommands_Unknown1_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown1_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 1", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown1 = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Unknown4_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown4_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 4", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown4 = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Unknown5_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown5_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 5", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown5 = AGETextCtrl::init(CFloat, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_SelectionEnabler_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_SelectionEnabler_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Enabler *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_SelectionEnabler = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_SelectionEnabler->SetToolTip("1 Allows units to select their targets\n2 ?");
	UnitCommands_Unknown7_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown7_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 7", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown7 = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Unknown8_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown8_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Plunder Source *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown8 = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Unknown8->SetToolTip("0 Plunder from resource\n1 Plunder from players\n2 Raider thing?");
	UnitCommands_Unknown9_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown9_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 9", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown9 = AGETextCtrl::init(CShort, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_SelectionMode_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_SelectionMode_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Selection Mode *", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_SelectionMode = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_SelectionMode->SetToolTip("Determines what you can select as targets\n0, 7+ All objects\n1 Your objects only\n2 Neutral and enemy objects only\n3 Gaia only\n4 Gaia, your and ally objects only\n5 Gaia, neutral and enemy objects only\n6 All but your objects");
	UnitCommands_Unknown11_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown11_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 11", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown11 = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);
	UnitCommands_Unknown12_Holder = new wxBoxSizer(wxVERTICAL);
	UnitCommands_Unknown12_Text = new wxStaticText(Units_Scroller, wxID_ANY, " Unknown 12", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT | wxST_NO_AUTORESIZE);
	UnitCommands_Unknown12 = AGETextCtrl::init(CByte, &uiGroupUnitCommand, this, AGEwindow, Units_Scroller);

//	UnitControls actual interface

	Units_Type_ComboBox->Append("No Type/Invalid Type");
	Units_Type_ComboBox->Append("10 - Eye Candy");
	Units_Type_ComboBox->Append("15 - Tree (AoK)");
	Units_Type_ComboBox->Append("20 - Flag");
	Units_Type_ComboBox->Append("25 - Doppleganger");
	Units_Type_ComboBox->Append("30 - Dead/Fish");
	Units_Type_ComboBox->Append("40 - Bird");
	Units_Type_ComboBox->Append("50 - Unknown");
	Units_Type_ComboBox->Append("60 - Projectile");
	Units_Type_ComboBox->Append("70 - Living");
	Units_Type_ComboBox->Append("80 - Building");
	Units_Type_ComboBox->Append("90 - Tree (AoE)");
	Units_Type_ComboBox->SetSelection(0);

	Type20.Add("Type");
	Type20.Add("NameLength");
	Type20.Add("ID1");
	Type20.Add("LanguageDLLName");
	Type20.Add("LanguageDLLCreation");
	Type20.Add("Class");
	Type20.Add("StandingGraphic x2");
	Type20.Add("DyingGraphic x2");
	Type20.Add("DeathMode");
	Type20.Add("HitPoints");
	Type20.Add("LineOfSight");
	Type20.Add("GarrisonCapacity");
	Type20.Add("SizeRadius x2");
	Type20.Add("HPBarHeight1");
	Type20.Add("TrainSound x2");
	Type20.Add("DeadUnitID");
	Type20.Add("PlacementMode");
	Type20.Add("AirMode");
	Type20.Add("IconID");
	Type20.Add("HideInEditor");
	Type20.Add("Unknown1");
	Type20.Add("Enabled");
	Type20.Add("Disabled");
	Type20.Add("PlacementBypassTerrain x2");
	Type20.Add("PlacementTerrain x2");
	Type20.Add("EditorRadius x2");
	Type20.Add("HillMode");
	Type20.Add("VisibleInFog");
	Type20.Add("TerrainRestriction");
	Type20.Add("FlyMode");
	Type20.Add("ResourceCapacity");
	Type20.Add("ResourceDecay");
	Type20.Add("BlastArmorLevel");
	Type20.Add("TriggerType");
	Type20.Add("InteractionMode");
	Type20.Add("MinimapMode");
	Type20.Add("CommandAttribute");
	Type20.Add("Unknown3A");
	Type20.Add("MinimapColor");
	Type20.Add("LanguageDLLHelp");
	Type20.Add("LanguageDLLHotKeyText");
	Type20.Add("HotKey");
	Type20.Add("Unselectable");
	Type20.Add("Unknown6");
	Type20.Add("Unknown7");
	Type20.Add("Unknown8");
	Type20.Add("SelectionMask");
	Type20.Add("SelectionShapeType");
	Type20.Add("SelectionShape");
	Type20.Add("Attribute");
	Type20.Add("Civilization");
	Type20.Add("Nothing");
	Type20.Add("SelectionEffect");
	Type20.Add("EditorSelectionColour");
	Type20.Add("SelectionRadius x2");
	Type20.Add("HPBarHeight2");
	Type20.Add("ResourceStorages 21 bytes");
	Type20.Add("DamageGraphicCount");
	Type20.Add("DamageGraphics");
	Type20.Add("SelectionSound");
	Type20.Add("DyingSound");
	Type20.Add("AttackMode");
	Type20.Add("EdibleMeat");
	Type20.Add("Name");
	Type20.Add("NameLength2");
	Type20.Add("Name2");
	Type20.Add("Unitline");
	Type20.Add("MinTechLevel");
	Type20.Add("ID2");
	Type20.Add("ID3");

	Type20.Add("Speed");

	Type30.Add("WalkingGraphic x2");
	Type30.Add("RotationSpeed");
	Type30.Add("Unknown11");
	Type30.Add("TrackingUnit");
	Type30.Add("TrackingUnitUsed");
	Type30.Add("TrackingUnitDensity");
	Type30.Add("Unknown16");
	Type30.Add("RotationAngles 5 floats");

	Type40.Add("SheepConversion");
	Type40.Add("SearchRadius");
	Type40.Add("WorkRate");
	Type40.Add("DropSite x2");
	Type40.Add("VillagerMode");
	Type40.Add("AttackSound");
	Type40.Add("MoveSound");
	Type40.Add("AnimalMode");
	Type40.Add("CommandCount");
	Type40.Add("Commands");

	Type50.Add("DefaultArmor");
	Type50.Add("AttackCount");
	Type50.Add("Attacks");
	Type50.Add("ArmourCount");
	Type50.Add("Armours");
	Type50.Add("TerRestrictionForDmgMultiplying");
	Type50.Add("MaxRange");
	Type50.Add("BlastRadius");
	Type50.Add("ReloadTime");
	Type50.Add("ProjectileUnitID");
	Type50.Add("AccuracyPercent");
	Type50.Add("TowerMode");
	Type50.Add("FrameDelay");
	Type50.Add("GraphicDisplacement 3 floats");
	Type50.Add("BlastAttackLevel");
	Type50.Add("MinRange");
	Type50.Add("AccuracyErrorRadius");
	Type50.Add("AttackGraphic");
	Type50.Add("DisplayedMeleeArmour");
	Type50.Add("DisplayedAttack");
	Type50.Add("DisplayedRange");
	Type50.Add("DisplayedReloadTime");

	Type60.Add("StretchMode");
	Type60.Add("CompensationMode");
	Type60.Add("DropAnimationMode");
	Type60.Add("PenetrationMode");
	Type60.Add("Unknown24");
	Type60.Add("ProjectileArc");

	Type70.Add("ResourceCosts 18 bytes");
	Type70.Add("TrainTime");
	Type70.Add("TrainLocationID");
	Type70.Add("ButtonID");
	Type70.Add("Unknown26");
	Type70.Add("Unknown27");
	Type70.Add("Unknown28");
	Type70.Add("HeroMode");
	Type70.Add("GarrisonGraphic");
	Type70.Add("TotalMissiles");
	Type70.Add("TotalMissilesMax");
	Type70.Add("MissileSpawningArea 3 floats");
	Type70.Add("AlternativeProjectileUnit");
	Type70.Add("ChargingGraphic");
	Type70.Add("ChargingMode");
	Type70.Add("DisplayedPierceArmour");

	Type80.Add("ConstructionGraphicID");
	Type80.Add("SnowGraphicID");
	Type80.Add("AdjacentMode");
	Type80.Add("GraphicsAngle");
	Type80.Add("DisappearsWhenBuilt");
	Type80.Add("StackUnitID");
	Type80.Add("FoundationTerrainID");
	Type80.Add("OldTerrainLikeID");
	Type80.Add("ResearchID");
	Type80.Add("Unknown33");
	Type80.Add("Annexes 40 bytes");
	Type80.Add("HeadUnit");
	Type80.Add("TransformUnit");
	Type80.Add("UnknownSound");
	Type80.Add("ConstructionSound");
	Type80.Add("GarrisonType");
	Type80.Add("GarrisonHealRate");
	Type80.Add("Unknown35");
	Type80.Add("PileUnit");
	Type80.Add("LootingTable 6 bytes");

	Units_SpecialCopy_Options->Append("Special: graphics only");
	Units_SpecialCopy_Options->SetSelection(0);

	Units_Buttons[0]->Add(Units_Add, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_Delete, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_Insert, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_Copy, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_Paste, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_PasteInsert, 1, wxEXPAND);
	//Units_Buttons[0]->Add(Units_Extract, 1, wxEXPAND);
	//Units_Buttons[0]->Add(Units_Import, 1, wxEXPAND);
	Units_Buttons[0]->Add(Units_Info, 1, wxEXPAND);
	Units_Buttons[1]->Add(Units_SpecialCopy, 1, wxEXPAND);
	Units_Buttons[1]->Add(Units_SpecialPaste, 1, wxEXPAND);
	Units_Buttons[1]->Add(Units_Enable, 1, wxEXPAND);
	Units_Buttons[1]->Add(Units_Disable, 1, wxEXPAND);
	Units_Special->Add(Units_SpecialCopy_Options, 1, wxEXPAND);
	Units_Special->AddSpacer(2);
	Units_Special->Add(Units_SpecialCopy_Civs, 0, wxEXPAND);

	Units_Searches[0]->Add(Units_Search, 1, wxEXPAND);
	Units_Searches[0]->AddSpacer(2);
	Units_Searches[0]->Add(Units_UseAnd[0], 0, wxEXPAND);
	Units_Searches[1]->Add(Units_Search_R, 1, wxEXPAND);
	Units_Searches[1]->AddSpacer(2);
	Units_Searches[1]->Add(Units_UseAnd[1], 0, wxEXPAND);

	Units_Units->Add(Units_Civs_List, 0, wxEXPAND);
	Units_Units->AddSpacer(2);
	for(short loop = 0; loop < 2; ++loop)
	Units_Units->Add(Units_Searches[loop], 0, wxEXPAND);
	Units_Units->Add(Units_FilterSelector, 0, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_Units->Add(Units_SearchFilters[loop], 0, wxEXPAND);
	Units_Units->AddSpacer(2);
	Units_Units->Add(Units_ListV, 1, wxEXPAND);
	Units_Units->AddSpacer(2);
	Units_Units->Add(Units_Buttons[0], 0, wxEXPAND);
	//Units_Units->Add(Units_Line, 0, wxEXPAND);
	Units_Units->Add(Units_Buttons[1], 0, wxEXPAND);
	Units_Units->AddSpacer(2);
	Units_Units->Add(Units_Special, 0, wxEXPAND);

	Units_ListArea->AddSpacer(5);
	Units_ListArea->Add(Units_Units, 1, wxEXPAND);
	Units_ListArea->AddSpacer(5);

	Units_Type_Holder->Add(visibleUnitCiv, 1, wxEXPAND);
	Units_Type_Holder->Add(Units_Type_Text, 0, wxEXPAND);
	Units_Type_Holder->Add(Units_Type, 1, wxEXPAND);
	Units_Type_Holder->Add(Units_Type_ComboBox, 2, wxEXPAND);
	Units_Type_Holder->Add(Units_Class_Text, 0, wxEXPAND);
	Units_Type_Holder->Add(Units_Class, 1, wxEXPAND);
	Units_Type_Holder->Add(Units_Class_ComboBox[0], 2, wxEXPAND);

//	Type 10+

	Units_ID1_Holder->Add(Units_ID1_Text, 0, wxEXPAND);
	Units_HitPoints_Holder->Add(Units_HitPoints_Text, 0, wxEXPAND);
	Units_LineOfSight_Holder->Add(Units_LineOfSight_Text, 0, wxEXPAND);
	Units_GarrisonCapacity_Holder->Add(Units_GarrisonCapacity_Text, 0, wxEXPAND);
	Units_SizeRadius_Holder->Add(Units_SizeRadius_Text, 0, wxEXPAND);
	Units_HPBarHeight1_Holder->Add(Units_HPBarHeight1_Text, 0, wxEXPAND);
	Units_DeadUnitID_Holder->Add(Units_DeadUnitID_Text, 0, wxEXPAND);
	Units_PlacementMode_Holder->Add(Units_PlacementMode_Text, 0, wxEXPAND);
	Units_IconID_Holder->Add(Units_IconID_Text, 0, wxEXPAND);
	Units_Unknown1_Holder->Add(Units_Unknown1_Text, 0, wxEXPAND);
	Units_PlacementBypassTerrain_Holder->Add(Units_PlacementBypassTerrain_Text, 0, wxEXPAND);
	Units_PlacementTerrain_Holder->Add(Units_PlacementTerrain_Text, 0, wxEXPAND);
	Units_EditorRadius_Holder->Add(Units_EditorRadius_Text, 0, wxEXPAND);
	Units_HillMode_Holder->Add(Units_HillMode_Text, 0, wxEXPAND);
	Units_TerrainRestriction_Holder->Add(Units_TerrainRestriction_Text, 0, wxEXPAND);
	Units_ResourceCapacity_Holder->Add(Units_ResourceCapacity_Text, 0, wxEXPAND);
	Units_ResourceDecay_Holder->Add(Units_ResourceDecay_Text, 0, wxEXPAND);
	Units_BlastArmorLevel_Holder->Add(Units_BlastArmorLevel_Text, 0, wxEXPAND);
	Units_TriggerType_Holder->Add(Units_TriggerType_Text, 0, wxEXPAND);
	Units_InteractionMode_Holder->Add(Units_InteractionMode_Text, 0, wxEXPAND);
	Units_MinimapMode_Holder->Add(Units_MinimapMode_Text, 0, wxEXPAND);
	Units_CommandID_Holder->Add(Units_CommandID_Text, 0, wxEXPAND);
	Units_Unknown3A_Holder->Add(Units_Unknown3A_Text, 0, wxEXPAND);
	Units_MinimapColor_Holder->Add(Units_MinimapColor_Text, 0, wxEXPAND);
	Units_Unknown6_Holder->Add(Units_Unknown6_Text, 0, wxEXPAND);
	Units_Unknown7_Holder->Add(Units_Unknown7_Text, 0, wxEXPAND);
	Units_Unknown8_Holder->Add(Units_Unknown8_Text, 0, wxEXPAND);
	Units_SelectionMask_Holder->Add(Units_SelectionMask_Text, 0, wxEXPAND);
	Units_SelectionShapeType_Holder->Add(Units_SelectionShapeType_Text, 0, wxEXPAND);
	Units_SelectionShape_Holder->Add(Units_SelectionShape_Text, 0, wxEXPAND);
	Units_Civ_Holder->Add(Units_Civ_Text, 0, wxEXPAND);
	Units_Unknown9_Holder->Add(Units_Unknown9_Text, 0, wxEXPAND);
	Units_Attribute_Holder->Add(Units_Attribute_Text, 0, wxEXPAND);
	Units_SelectionEffect_Holder->Add(Units_SelectionEffect_Text, 0, wxEXPAND);
	Units_EditorSelectionColour_Holder->Add(Units_EditorSelectionColour_Text, 0, wxEXPAND);
	Units_SelectionRadius_Holder->Add(Units_SelectionRadius_Text, 0, wxEXPAND);
	Units_HPBarHeight2_Holder->Add(Units_HPBarHeight2_Text, 0, wxEXPAND);
	Units_SelectionSound_Holder->Add(Units_SelectionSound_Text, 0, wxEXPAND);
	Units_DyingSound_Holder->Add(Units_DyingSound_Text, 0, wxEXPAND);
	Units_AttackMode_Holder->Add(Units_AttackMode_Text, 0, wxEXPAND);
	Units_EdibleMeat_Holder->Add(Units_EdibleMeat_Text, 0, wxEXPAND);
	Units_Name_Holder->Add(Units_Name_Text, 0, wxEXPAND);
	Units_Name2_Holder->Add(Units_Name2_Text, 0, wxEXPAND);
	Units_Unitline_Holder->Add(Units_Unitline_Text, 0, wxEXPAND);
	Units_MinTechLevel_Holder->Add(Units_MinTechLevel_Text, 0, wxEXPAND);
	Units_ID2_Holder->Add(Units_ID2_Text, 0, wxEXPAND);
	Units_ID3_Holder->Add(Units_ID3_Text, 0, wxEXPAND);

//	Type 20+

	Units_Speed_Holder->Add(Units_Speed_Text, 0, wxEXPAND);

//	Type 30+

	Units_RotationSpeed_Holder->Add(Units_RotationSpeed_Text, 0, wxEXPAND);
	Units_Unknown11_Holder->Add(Units_Unknown11_Text, 0, wxEXPAND);
	Units_TrackingUnit_Holder->Add(Units_TrackingUnit_Text, 0, wxEXPAND);
	Units_TrackingUnitUsed_Holder->Add(Units_TrackingUnitUsed_Text, 0, wxEXPAND);
	Units_TrackingUnitDensity_Holder->Add(Units_TrackingUnitDensity_Text, 0, wxEXPAND);
	Units_Unknown16_Holder->Add(Units_Unknown16_Text, 0, wxEXPAND);
	Units_RotationAngles_Holder->Add(Units_RotationAngles_Text, 0, wxEXPAND);

//	Type 40+

	Units_SearchRadius_Holder->Add(Units_SearchRadius_Text, 0, wxEXPAND);
	Units_WorkRate_Holder->Add(Units_WorkRate_Text, 0, wxEXPAND);
	Units_AttributesDropSite_Holder->Add(Units_DropSite_Text, 0, wxEXPAND);
	Units_VillagerMode_Holder->Add(Units_VillagerMode_Text, 0, wxEXPAND);
	Units_AttackSound_Holder->Add(Units_AttackSound_Text, 0, wxEXPAND);
	Units_MoveSound_Holder->Add(Units_MoveSound_Text, 0, wxEXPAND);
	Units_Exists_Holder->Add(Units_Exists_Text, 0, wxEXPAND);

//	Type 50+

	Units_DefaultArmor_Holder->Add(Units_DefaultArmor_Text, 0, wxEXPAND);
	Units_TerRestrictionForDmgMultiply_Holder->Add(Units_TerRestrictionForDmgMultiply_Text, 0, wxEXPAND);
	Units_MaxRange_Holder->Add(Units_MaxRange_Text, 0, wxEXPAND);
	Units_BlastRadius_Holder->Add(Units_BlastRadius_Text, 0, wxEXPAND);
	Units_ReloadTime1_Holder->Add(Units_ReloadTime1_Text, 0, wxEXPAND);
	Units_AccuracyPercent_Holder->Add(Units_AccuracyPercent_Text, 0, wxEXPAND);
	Units_Delay_Holder->Add(Units_Delay_Text, 0, wxEXPAND);
	Units_GraphicDisplacement_Holder->Add(Units_GraphicDisplacement_Text, 0, wxEXPAND);
	Units_BlastAttackLevel_Holder->Add(Units_BlastAttackLevel_Text, 0, wxEXPAND);
	Units_MinRange_Holder->Add(Units_MinRange_Text, 0, wxEXPAND);
	Units_AccuracyErrorRadius_Holder->Add(Units_AccuracyErrorRadius_Text, 0, wxEXPAND);
	Units_AttackGraphic_Holder->Add(Units_AttackGraphic_Text, 0, wxEXPAND);
	Units_DisplayedMeleeArmour_Holder->Add(Units_DisplayedMeleeArmour_Text, 0, wxEXPAND);
	Units_DisplayedAttack_Holder->Add(Units_DisplayedAttack_Text, 0, wxEXPAND);
	Units_DisplayedRange_Holder->Add(Units_DisplayedRange_Text, 0, wxEXPAND);
	Units_ReloadTime2_Holder->Add(Units_ReloadTime2_Text, 0, wxEXPAND);

//	Type 60 only

	Units_StretchMode_Holder->Add(Units_StretchMode_Text, 0, wxEXPAND);
	Units_CompensationMode_Holder->Add(Units_CompensationMode_Text, 0, wxEXPAND);
	Units_DropAnimationMode_Holder->Add(Units_DropAnimationMode_Text, 0, wxEXPAND);
	Units_PenetrationMode_Holder->Add(Units_PenetrationMode_Text, 0, wxEXPAND);
	Units_Unknown24_Holder->Add(Units_Unknown24_Text, 0, wxEXPAND);
	Units_ProjectileArc_Holder->Add(Units_ProjectileArc_Text, 0, wxEXPAND);

//	Type 70+

	Units_CostType_Holder->Add(Units_CostType_Text, 2, wxEXPAND);
	Units_CostAmount_Holder->Add(Units_CostAmount_Text, 2, wxEXPAND);
	Units_CostUsed_Holder->Add(Units_CostUsed_Text, 2, wxEXPAND);
	Units_TrainTime_Holder->Add(Units_TrainTime_Text, 0, wxEXPAND);
	Units_TrainLocationID_Holder->Add(Units_TrainLocationID_Text, 0, wxEXPAND);
	Units_ButtonID_Holder->Add(Units_ButtonID_Text, 0, wxEXPAND);
	Units_Unknown26_Holder->Add(Units_Unknown26_Text, 0, wxEXPAND);
	Units_Unknown27_Holder->Add(Units_Unknown27_Text, 0, wxEXPAND);
	Units_Unknown28_Holder->Add(Units_Unknown28_Text, 0, wxEXPAND);
	Units_MissileCount_Holder->Add(Units_MissileCount_Text, 0, wxEXPAND);
	Units_MissileDuplicationCount_Holder->Add(Units_MissileDuplicationCount_Text, 0, wxEXPAND);
	Units_AttackMissileDuplicationSpawning_Holder->Add(Units_AttackMissileDuplicationSpawning_Text, 0, wxEXPAND);
	Units_ChargingMode_Holder->Add(Units_ChargingMode_Text, 0, wxEXPAND);
	Units_DisplayedPierceArmour_Holder->Add(Units_DisplayedPierceArmour_Text, 0, wxEXPAND);

//	Type 80

	Units_ConstructionGraphicID_Holder->Add(Units_ConstructionGraphicID_Text, 0, wxEXPAND);
	Units_SnowGraphicID_Holder->Add(Units_SnowGraphicID_Text, 0, wxEXPAND);
	Units_IconAngle_Holder->Add(Units_IconAngle_Text, 0, wxEXPAND);
	Units_StackUnitID_Holder->Add(Units_StackUnitID_Text, 0, wxEXPAND);
	Units_TerrainID_Holder->Add(Units_TerrainID_Text, 0, wxEXPAND);
	Units_OldTerrainLikeID_Holder->Add(Units_OldTerrainLikeID_Text, 0, wxEXPAND);
	Units_ResearchID_Holder->Add(Units_ResearchID_Text, 0, wxEXPAND);
	Units_Unknown33_Holder->Add(Units_Unknown33_Text, 0, wxEXPAND);
	Units_AnnexUnit1_Holder->Add(Units_AnnexUnit_Text, 0, wxEXPAND);
	Units_AnnexUnitMisplacement1_Holder->Add(Units_AnnexUnitMisplacement_Text, 0, wxEXPAND);
	Units_HeadUnit_Holder->Add(Units_HeadUnit_Text, 0, wxEXPAND);
	Units_TransformUnit_Holder->Add(Units_TransformUnit_Text, 0, wxEXPAND);
	Units_UnknownSound_Holder->Add(Units_UnknownSound_Text, 0, wxEXPAND);
	Units_ConstructionSound_Holder->Add(Units_ConstructionSound_Text, 0, wxEXPAND);
	Units_GarrisonHealRate_Holder->Add(Units_GarrisonHealRate_Text, 0, wxEXPAND);
	Units_Unknown35_Holder->Add(Units_Unknown35_Text, 0, wxEXPAND);
	Units_PileUnit_Holder->Add(Units_PileUnit_Text, 0, wxEXPAND);
	Units_LootSwitch_Holder->Add(Units_LootSwitch_Text, 0, wxEXPAND);

//	Type 10+

	Units_ID1_Holder->Add(Units_ID1, 1, wxEXPAND);
	Units_DeathMode_Holder->Add(Units_DeathMode, 0, wxEXPAND);
	Units_DeathMode_Holder->AddSpacer(2);
	Units_DeathMode_Holder->Add(Units_DeathMode_CheckBox, 2, wxEXPAND);
	Units_HitPoints_Holder->Add(Units_HitPoints, 1, wxEXPAND);
	Units_LineOfSight_Holder->Add(Units_LineOfSight, 1, wxEXPAND);
	Units_GarrisonCapacity_Holder->Add(Units_GarrisonCapacity, 0, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_SizeRadius_Grid->Add(Units_SizeRadius[loop], 1, wxEXPAND);
	Units_SizeRadius_Holder->Add(Units_SizeRadius_Grid, 1, wxEXPAND);
	Units_HPBarHeight1_Holder->Add(Units_HPBarHeight1, 1, wxEXPAND);
	Units_DeadUnitID_Holder->Add(Units_DeadUnitID, 1, wxEXPAND);
	Units_DeadUnitID_Holder->Add(Units_DeadUnitID_ComboBox, 1, wxEXPAND);
	Units_PlacementMode_Holder->Add(Units_PlacementMode, 0, wxEXPAND);
	Units_AirMode_Holder->Add(Units_AirMode, 0, wxEXPAND);
	Units_AirMode_Holder->AddSpacer(2);
	Units_AirMode_Holder->Add(Units_AirMode_CheckBox, 2, wxEXPAND);
	Units_IconID_Holder->Add(Units_IconID, 0, wxEXPAND);
	Units_HideInEditor_Holder->Add(Units_HideInEditor, 0, wxEXPAND);
	Units_HideInEditor_Holder->AddSpacer(2);
	Units_HideInEditor_Holder->Add(Units_HideInEditor_CheckBox, 2, wxEXPAND);
	Units_Unknown1_Holder->Add(Units_Unknown1, 1, wxEXPAND);
	Units_Enabled_Holder->Add(Units_Enabled, 0, wxEXPAND);
	Units_Enabled_Holder->AddSpacer(2);
	Units_Enabled_Holder->Add(Units_Enabled_CheckBox, 2, wxEXPAND);
	Units_Disabled_Holder->Add(Units_Disabled, 0, wxEXPAND);
	Units_Disabled_Holder->AddSpacer(2);
	Units_Disabled_Holder->Add(Units_Disabled_CheckBox, 2, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_PlacementBypassTerrainGrid_Holder->Add(Units_PlacementBypassTerrain[loop], 1, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_PlacementBypassTerrainGrid_Holder->Add(Units_PlacementBypassTerrain_ComboBox[loop], 1, wxEXPAND);
	Units_PlacementBypassTerrain_Holder->Add(Units_PlacementBypassTerrainGrid_Holder, 0, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_PlacementTerrainGrid_Holder->Add(Units_PlacementTerrain[loop], 1, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_PlacementTerrainGrid_Holder->Add(Units_PlacementTerrain_ComboBox[loop], 1, wxEXPAND);
	Units_PlacementTerrain_Holder->Add(Units_PlacementTerrainGrid_Holder, 0, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_EditorRadius_Grid->Add(Units_EditorRadius[loop], 1, wxEXPAND);
	Units_EditorRadius_Holder->Add(Units_EditorRadius_Grid, 1, wxEXPAND);
	Units_HillMode_Holder->Add(Units_HillMode, 0, wxEXPAND);
	Units_VisibleInFog_Holder->Add(Units_VisibleInFog_Text, 0, wxEXPAND);
	Units_VisibleInFog_Holder->Add(Units_VisibleInFog, 0, wxEXPAND);
	Units_TerrainRestriction_Holder->Add(Units_TerrainRestriction, 1, wxEXPAND);
	Units_TerrainRestriction_Holder->Add(Units_TerrainRestriction_ComboBox, 1, wxEXPAND);
	Units_FlyMode_Holder->Add(Units_FlyMode, 0, wxEXPAND);
	Units_FlyMode_Holder->AddSpacer(2);
	Units_FlyMode_Holder->Add(Units_FlyMode_CheckBox, 2, wxEXPAND);
	Units_ResourceCapacity_Holder->Add(Units_ResourceCapacity, 1, wxEXPAND);
	Units_ResourceDecay_Holder->Add(Units_ResourceDecay, 1, wxEXPAND);
	Units_BlastArmorLevel_Holder->Add(Units_BlastArmorLevel, 1, wxEXPAND);
	Units_TriggerType_Holder->Add(Units_TriggerType, 1, wxEXPAND);
	Units_InteractionMode_Holder->Add(Units_InteractionMode, 1, wxEXPAND);
	Units_MinimapMode_Holder->Add(Units_MinimapMode, 1, wxEXPAND);
	Units_CommandID_Holder->Add(Units_CommandID, 0, wxEXPAND);
	Units_Unknown3A_Holder->Add(Units_Unknown3A, 0, wxEXPAND);
	Units_MinimapColor_Holder->Add(Units_MinimapColor, 0, wxEXPAND);
	Units_Unselectable_Holder->Add(Units_Unselectable_CheckBox, 0, wxEXPAND);
	Units_Unselectable_Holder->Add(Units_Unselectable, 0, wxEXPAND);
	Units_Unknown6_Holder->Add(Units_Unknown6, 0, wxEXPAND);
	Units_Unknown7_Holder->Add(Units_Unknown7, 0, wxEXPAND);
	Units_Unknown8_Holder->Add(Units_Unknown8, 0, wxEXPAND);
	Units_SelectionMask_Holder->Add(Units_SelectionMask, 0, wxEXPAND);
	Units_SelectionShapeType_Holder->Add(Units_SelectionShapeType, 0, wxEXPAND);
	Units_SelectionShape_Holder->Add(Units_SelectionShape, 0, wxEXPAND);
	for(short loop = 0; loop < 8; ++loop)
	Units_Attribute_Grid->Add(Units_Attribute_CheckBox[loop], 1, wxEXPAND);
	Units_Attribute_Holder->Add(Units_Attribute, 1, wxEXPAND);
	Units_Attribute_Holder->Add(Units_Attribute_Grid, 1, wxEXPAND);
	Units_Civ_Holder->Add(Units_Civ, 1, wxEXPAND);
	Units_Civ_Holder->Add(Units_Civ_ComboBox, 1, wxEXPAND);
	Units_Unknown9_Holder->Add(Units_Unknown9, 0, wxEXPAND);
	Units_SelectionEffect_Holder->Add(Units_SelectionEffect, 0, wxEXPAND);
	Units_EditorSelectionColour_Holder->Add(Units_EditorSelectionColour, 0, wxEXPAND);
	for(short loop = 0; loop < 2; ++loop)
	Units_SelectionRadiusBox->Add(Units_SelectionRadius[loop], 1, wxEXPAND);
	Units_SelectionRadius_Holder->Add(Units_SelectionRadiusBox, 1, wxEXPAND);
	Units_HPBarHeight2_Holder->Add(Units_HPBarHeight2, 1, wxEXPAND);
	Units_SelectionSound_Holder->Add(Units_SelectionSound, 1, wxEXPAND);
	Units_SelectionSound_Holder->Add(Units_SelectionSound_ComboBox, 1, wxEXPAND);
	Units_DyingSound_Holder->Add(Units_DyingSound, 1, wxEXPAND);
	Units_DyingSound_Holder->Add(Units_DyingSound_ComboBox, 1, wxEXPAND);
	Units_AttackMode_Holder->Add(Units_AttackMode, 0, wxEXPAND);
	Units_EdibleMeat_Holder->Add(Units_EdibleMeat, 0, wxEXPAND);
	Units_Name_Holder->Add(Units_Name, 1, wxEXPAND);
	Units_Name2_Holder->Add(Units_Name2, 1, wxEXPAND);
	Units_Unitline_Holder->Add(Units_Unitline, 1, wxEXPAND);
	Units_Unitline_Holder->Add(Units_Unitline_ComboBox, 1, wxEXPAND);
	Units_MinTechLevel_Holder->Add(Units_MinTechLevel, 0, wxEXPAND);
	Units_MinTechLevel_Holder->Add(Units_MinTechLevel_ComboBox, 0, wxEXPAND);
	Units_ID2_Holder->Add(Units_ID2, 1, wxEXPAND);
	Units_ID3_Holder->Add(Units_ID3, 1, wxEXPAND);

//	Type 20+

	Units_Speed_Holder->Add(Units_Speed, 1, wxEXPAND);

//	Type 30+

	Units_RotationSpeed_Holder->Add(Units_RotationSpeed, 1, wxEXPAND);
	Units_Unknown11_Holder->Add(Units_Unknown11, 1, wxEXPAND);
	Units_TrackingUnit_Holder->Add(Units_TrackingUnit, 1, wxEXPAND);
	Units_TrackingUnit_Holder->Add(Units_TrackingUnit_ComboBox, 1, wxEXPAND);
	Units_TrackingUnitUsedBox_Holder->Add(Units_TrackingUnitUsed, 2, wxEXPAND);
	Units_TrackingUnitUsed_Holder->Add(Units_TrackingUnitUsedBox_Holder, 0, wxEXPAND);
	Units_TrackingUnitDensity_Holder->Add(Units_TrackingUnitDensity, 0, wxEXPAND);
	Units_Unknown16_Holder->Add(Units_Unknown16, 0, wxEXPAND);
	for(short loop = 0; loop < Units_RotationAngles.size(); ++loop)
	Units_RotationAngles_Grid->Add(Units_RotationAngles[loop], 1, wxEXPAND);
	Units_RotationAngles_Holder->Add(Units_RotationAngles_Grid, 0, wxEXPAND);

//	Type 40+

	Units_SheepConversion_Holder->Add(Units_SheepConversion, 0, wxEXPAND);
	Units_SheepConversion_Holder->AddSpacer(2);
	Units_SheepConversion_Holder->Add(Units_SheepConversion_CheckBox, 2, wxEXPAND);
	Units_SearchRadius_Holder->Add(Units_SearchRadius, 1, wxEXPAND);
	Units_WorkRate_Holder->Add(Units_WorkRate, 1, wxEXPAND);
	Units_DropSite_Grid->Add(Units_DropSite[0], 1, wxEXPAND);
	Units_DropSite_Grid->Add(Units_DropSite[1], 1, wxEXPAND);
	Units_DropSite_Grid->AddStretchSpacer(1);
	Units_DropSite_Grid->AddStretchSpacer(1);
	Units_DropSite_Grid->Add(Units_DropSite_ComboBox[0], 2, wxEXPAND);
	Units_DropSite_Grid->Add(Units_DropSite_ComboBox[1], 2, wxEXPAND);
	Units_VillagerMode_Holder->Add(Units_VillagerMode, 1, wxEXPAND);
	Units_AttackSound_Holder->Add(Units_AttackSound, 1, wxEXPAND);
	Units_AttackSound_Holder->Add(Units_AttackSound_ComboBox, 1, wxEXPAND);
	Units_MoveSound_Holder->Add(Units_MoveSound, 1, wxEXPAND);
	Units_MoveSound_Holder->Add(Units_MoveSound_ComboBox, 1, wxEXPAND);
	Units_AnimalMode_Holder->Add(Units_AnimalMode, 0, wxEXPAND);
	Units_AnimalMode_Holder->AddSpacer(2);
	Units_AnimalMode_Holder->Add(Units_AnimalMode_CheckBox, 2, wxEXPAND);
	Units_Exists_Holder->Add(Units_Exists, 1, wxEXPAND);

//	Type 50+

	Units_DefaultArmor_Holder->Add(Units_DefaultArmor, 1, wxEXPAND);
	Units_TerRestrictionForDmgMultiply_Holder->Add(Units_TerRestrictionForDmgMultiply, 1, wxEXPAND);
	Units_TerRestrictionForDmgMultiply_Holder->Add(Units_TerRestrictionForDmgMultiply_ComboBox, 1, wxEXPAND);
	Units_MaxRange_Holder->Add(Units_MaxRange, 1, wxEXPAND);
	Units_BlastRadius_Holder->Add(Units_BlastRadius, 1, wxEXPAND);
	Units_ReloadTime1_Holder->Add(Units_ReloadTime1, 1, wxEXPAND);
	Units_AccuracyPercent_Holder->Add(Units_AccuracyPercent, 1, wxEXPAND);
	Units_TowerMode_Holder->Add(Units_TowerMode, 0, wxEXPAND);
	Units_TowerMode_Holder->AddSpacer(2);
	Units_TowerMode_Holder->Add(Units_TowerMode_CheckBox, 2, wxEXPAND);
	Units_Delay_Holder->Add(Units_Delay, 1, wxEXPAND);
	for(short loop = 0; loop < 3; ++loop)
	Units_GraphicDisplacement_Grid->Add(Units_GraphicDisplacement[loop], 1, wxEXPAND);
	Units_GraphicDisplacement_Holder->Add(Units_GraphicDisplacement_Grid, 1, wxEXPAND);
	Units_BlastAttackLevel_Holder->Add(Units_BlastAttackLevel, 1, wxEXPAND);
	Units_MinRange_Holder->Add(Units_MinRange, 1, wxEXPAND);
	Units_AccuracyErrorRadius_Holder->Add(Units_AccuracyErrorRadius, 0, wxEXPAND);
	Units_AttackGraphic_Holder->Add(Units_AttackGraphic, 1, wxEXPAND);
	Units_AttackGraphic_Holder->Add(Units_AttackGraphic_ComboBox, 1, wxEXPAND);
	Units_DisplayedMeleeArmour_Holder->Add(Units_DisplayedMeleeArmour, 1, wxEXPAND);
	Units_DisplayedAttack_Holder->Add(Units_DisplayedAttack, 1, wxEXPAND);
	Units_DisplayedRange_Holder->Add(Units_DisplayedRange, 1, wxEXPAND);
	Units_ReloadTime2_Holder->Add(Units_ReloadTime2, 1, wxEXPAND);

//	Type 60 only

	Units_StretchMode_Holder->Add(Units_StretchMode, 1, wxEXPAND);
	Units_CompensationMode_Holder->Add(Units_CompensationMode, 1, wxEXPAND);
	Units_DropAnimationMode_Holder->Add(Units_DropAnimationMode, 1, wxEXPAND);
	Units_PenetrationMode_Holder->Add(Units_PenetrationMode, 1, wxEXPAND);
	Units_Unknown24_Holder->Add(Units_Unknown24, 1, wxEXPAND);
	Units_ProjectileArc_Holder->Add(Units_ProjectileArc, 1, wxEXPAND);

//	Type 70+

	for(short loop = 0; loop < 3; ++loop)
	Units_CostType_Grid->Add(Units_CostType[loop], 1, wxEXPAND);
	for(short loop = 0; loop < 3; ++loop)
	Units_CostType_Grid->Add(Units_CostType_ComboBox[loop], 1, wxEXPAND);
	Units_CostType_Holder->Add(Units_CostType_Grid, 12, wxEXPAND);
	Units_CostAmount_Holder->Add(Units_CostAmount[0], 4, wxEXPAND);
	Units_CostAmount_Holder->AddSpacer(5);
	Units_CostAmount_Holder->Add(Units_CostAmount[1], 4, wxEXPAND);
	Units_CostAmount_Holder->AddSpacer(5);
	Units_CostAmount_Holder->Add(Units_CostAmount[2], 4, wxEXPAND);
	Units_CostUsed_Holder->Add(Units_CostUsed[0], 3, wxEXPAND);
	Units_CostUsed_Holder->AddSpacer(2);
	Units_CostUsed_Holder->Add(Units_CostUsed_CheckBox[0], 1, wxEXPAND);
	Units_CostUsed_Holder->AddSpacer(5);
	Units_CostUsed_Holder->Add(Units_CostUsed[1], 3, wxEXPAND);
	Units_CostUsed_Holder->AddSpacer(2);
	Units_CostUsed_Holder->Add(Units_CostUsed_CheckBox[1], 1, wxEXPAND);
	Units_CostUsed_Holder->AddSpacer(5);
	Units_CostUsed_Holder->Add(Units_CostUsed[2], 3, wxEXPAND);
	Units_CostUsed_Holder->AddSpacer(2);
	Units_CostUsed_Holder->Add(Units_CostUsed_CheckBox[2], 1, wxEXPAND);
	Units_TrainTime_Holder->Add(Units_TrainTime, 0, wxEXPAND);
	Units_TrainLocationID_Holder->Add(Units_TrainLocationID, 1, wxEXPAND);
	Units_TrainLocationID_Holder->Add(Units_TrainLocationID_ComboBox, 1, wxEXPAND);
	Units_ButtonID_Holder->Add(Units_ButtonID, 0, wxEXPAND);
	Units_Unknown26_Holder->Add(Units_Unknown26, 1, wxEXPAND);
	Units_Unknown27_Holder->Add(Units_Unknown27, 1, wxEXPAND);
	Units_Unknown28_Holder->Add(Units_Unknown28, 1, wxEXPAND);
	Units_HeroMode_Holder->Add(Units_HeroMode, 0, wxEXPAND);
	Units_HeroMode_Holder->AddSpacer(2);
	Units_HeroMode_Holder->Add(Units_HeroMode_CheckBox, 2, wxEXPAND);
	Units_MissileCount_Holder->Add(Units_MissileCount, 1, wxEXPAND);
	Units_MissileDuplicationCount_Holder->Add(Units_MissileDuplicationCount, 1, wxEXPAND);
	for(short loop = 0; loop < 3; ++loop)
	Units_AttackMissileDuplicationSpawning_Grid->Add(Units_AttackMissileDuplicationSpawning[loop], 1, wxEXPAND);
	Units_AttackMissileDuplicationSpawning_Holder->Add(Units_AttackMissileDuplicationSpawning_Grid, 1, wxEXPAND);
	Units_ChargingMode_Holder->Add(Units_ChargingMode, 0, wxEXPAND);
	Units_DisplayedPierceArmour_Holder->Add(Units_DisplayedPierceArmour, 1, wxEXPAND);

//	Type 80

	Units_ConstructionGraphicID_Holder->Add(Units_ConstructionGraphicID, 1, wxEXPAND);
	Units_ConstructionGraphicID_Holder->Add(Units_ConstructionGraphicID_ComboBox, 1, wxEXPAND);
	Units_SnowGraphicID_Holder->Add(Units_SnowGraphicID, 1, wxEXPAND);
	Units_SnowGraphicID_Holder->Add(Units_SnowGraphicID_ComboBox, 1, wxEXPAND);
	Units_AdjacentMode_Holder->Add(Units_AdjacentMode, 0, wxEXPAND);
	Units_AdjacentMode_Holder->AddSpacer(2);
	Units_AdjacentMode_Holder->Add(Units_AdjacentMode_CheckBox, 2, wxEXPAND);
	Units_Unknown31b_Holder->Add(Units_DisappearsWhenBuilt, 0, wxEXPAND);
	Units_Unknown31b_Holder->AddSpacer(2);
	Units_Unknown31b_Holder->Add(Units_Unknown31b_CheckBox, 2, wxEXPAND);
	Units_IconAngle_Holder->Add(Units_IconAngle, 0, wxEXPAND);
	Units_StackUnitID_Holder->Add(Units_StackUnitID, 1, wxEXPAND);
	Units_StackUnitID_Holder->Add(Units_StackUnitID_ComboBox, 1, wxEXPAND);
	Units_TerrainID_Holder->Add(Units_TerrainID, 1, wxEXPAND);
	Units_TerrainID_Holder->Add(Units_TerrainID_ComboBox, 1, wxEXPAND);
	Units_OldTerrainLikeID_Holder->Add(Units_OldTerrainLikeID, 0, wxEXPAND);
	Units_ResearchID_Holder->Add(Units_ResearchID, 1, wxEXPAND);
	Units_ResearchID_Holder->Add(Units_ResearchID_ComboBox, 1, wxEXPAND);
	Units_Unknown33_Holder->Add(Units_Unknown33, 1, wxEXPAND);
	for(short loop = 0; loop < 4; ++loop)
	Units_AnnexUnit_Grid->Add(Units_AnnexUnit[loop], 1, wxEXPAND);
	for(short loop = 0; loop < 4; ++loop)
	Units_AnnexUnit_Grid->Add(Units_AnnexUnit_ComboBox[loop], 1, wxEXPAND);
	Units_AnnexUnit1_Holder->Add(Units_AnnexUnit_Grid, 0, wxEXPAND);
	for(short loop = 0; loop < 4; ++loop)
	Units_AnnexUnitMisplacement_Grid->Add(Units_AnnexUnitMisplacement[loop][0], 1, wxEXPAND);
	for(short loop = 0; loop < 4; ++loop)
	Units_AnnexUnitMisplacement_Grid->Add(Units_AnnexUnitMisplacement[loop][1], 1, wxEXPAND);
	Units_AnnexUnitMisplacement1_Holder->Add(Units_AnnexUnitMisplacement_Grid, 0, wxEXPAND);
	Units_HeadUnit_Holder->Add(Units_HeadUnit, 1, wxEXPAND);
	Units_HeadUnit_Holder->Add(Units_HeadUnit_ComboBox, 1, wxEXPAND);
	Units_TransformUnit_Holder->Add(Units_TransformUnit, 1, wxEXPAND);
	Units_TransformUnit_Holder->Add(Units_TransformUnit_ComboBox, 1, wxEXPAND);
	Units_UnknownSound_Holder->Add(Units_UnknownSound, 1, wxEXPAND);
	Units_UnknownSound_Holder->Add(Units_UnknownSound_ComboBox, 1, wxEXPAND);
	Units_ConstructionSound_Holder->Add(Units_ConstructionSound, 1, wxEXPAND);
	Units_ConstructionSound_Holder->Add(Units_ConstructionSound_ComboBox, 1, wxEXPAND);
	Units_GarrisonHealRate_Holder->Add(Units_GarrisonHealRate, 0, wxEXPAND);
	Units_Unknown35_Holder->Add(Units_Unknown35, 1, wxEXPAND);
	Units_PileUnit_Holder->Add(Units_PileUnit, 1, wxEXPAND);
	Units_PileUnit_Holder->Add(Units_PileUnit_ComboBox, 1, wxEXPAND);
	for(short loop = 0; loop < Units_LootSwitch.size(); ++loop)
	Units_LootSwitch_Grid->Add(Units_LootSwitch[loop], 1, wxEXPAND);
	Units_LootSwitch_Holder->Add(Units_LootSwitch_Grid, 0, wxEXPAND);

	for(short loop = 0; loop < 3; ++loop)
	Units_ResourceStorage_Grid->Add(ResourceStorage_Type[loop], 1, wxEXPAND);
	for(short loop = 0; loop < 3; ++loop)
	Units_ResourceStorage_Grid->Add(ResourceStorage_Type_ComboBox[loop], 1, wxEXPAND);
	Units_ResourceStorage_Holder[0]->Add(ResourceStorage_Type_Text, 2, wxEXPAND);
	Units_ResourceStorage_Holder[0]->Add(Units_ResourceStorage_Grid, 12, wxEXPAND);
	Units_ResourceStorage_Holder[1]->Add(ResourceStorage_Amount_Text, 2, wxEXPAND);
	Units_ResourceStorage_Holder[1]->Add(ResourceStorage_Amount[0], 4, wxEXPAND);
	Units_ResourceStorage_Holder[1]->AddSpacer(5);
	Units_ResourceStorage_Holder[1]->Add(ResourceStorage_Amount[1], 4, wxEXPAND);
	Units_ResourceStorage_Holder[1]->AddSpacer(5);
	Units_ResourceStorage_Holder[1]->Add(ResourceStorage_Amount[2], 4, wxEXPAND);
	Units_ResourceStorage_Holder[2]->Add(ResourceStorage_Enabled_Text, 2, wxEXPAND);
	Units_ResourceStorage_Holder[2]->Add(ResourceStorage_Enabled[0], 4, wxEXPAND);
	Units_ResourceStorage_Holder[2]->AddSpacer(5);
	Units_ResourceStorage_Holder[2]->Add(ResourceStorage_Enabled[1], 4, wxEXPAND);
	Units_ResourceStorage_Holder[2]->AddSpacer(5);
	Units_ResourceStorage_Holder[2]->Add(ResourceStorage_Enabled[2], 4, wxEXPAND);

	Attacks_Class_Holder->Add(Attacks_Class_Text, 0, wxEXPAND);
	Attacks_Class_Holder->Add(Attacks_Class, 1, wxEXPAND);
	Attacks_Class_Holder->Add(Attacks_Class_ComboBox[0], 1, wxEXPAND);
	Attacks_Amount_Holder->Add(Attacks_Amount_Text, 0, wxEXPAND);
	Attacks_Amount_Holder->Add(Attacks_Amount, 1, wxEXPAND);

	Units_Attacks_Buttons->Add(Units_Attacks_Add, 1, wxEXPAND);
	Units_Attacks_Buttons->Add(Units_Attacks_Delete, 1, wxEXPAND);
	Units_Attacks_Buttons->Add(Units_Attacks_Insert, 1, wxEXPAND);
	Units_Attacks_Buttons->Add(Units_Attacks_Copy, 1, wxEXPAND);
	Units_Attacks_Buttons->Add(Units_Attacks_Paste, 1, wxEXPAND);
	Units_Attacks_Buttons->Add(Units_Attacks_PasteInsert, 1, wxEXPAND);

	Units_Attacks_ListArea->Add(Units_Attacks_Search, 0, wxEXPAND);
	Units_Attacks_ListArea->Add(Units_Attacks_Search_R, 0, wxEXPAND);
	Units_Attacks_ListArea->AddSpacer(2);
	Units_Attacks_ListArea->Add(Units_Attacks_ListV, 1, wxEXPAND);
	Units_Attacks_ListArea->AddSpacer(2);
	Units_Attacks_ListArea->Add(Units_Attacks_Buttons, 0, wxEXPAND);
	Units_Attacks_ListArea->AddSpacer(2);
	Units_Attacks_ListArea->Add(Units_Attacks_CopyToUnits, 0, wxEXPAND);

	Armors_Class_Holder->Add(Armors_Class_Text, 0, wxEXPAND);
	Armors_Class_Holder->Add(Armors_Class, 1, wxEXPAND);
	Armors_Class_Holder->Add(Attacks_Class_ComboBox[1], 1, wxEXPAND);
	Armors_Amount_Holder->Add(Armors_Amount_Text, 0, wxEXPAND);
	Armors_Amount_Holder->Add(Armors_Amount, 1, wxEXPAND);

	Units_Armors_Buttons->Add(Units_Armors_Add, 1, wxEXPAND);
	Units_Armors_Buttons->Add(Units_Armors_Delete, 1, wxEXPAND);
	Units_Armors_Buttons->Add(Units_Armors_Insert, 1, wxEXPAND);
	Units_Armors_Buttons->Add(Units_Armors_Copy, 1, wxEXPAND);
	Units_Armors_Buttons->Add(Units_Armors_Paste, 1, wxEXPAND);
	Units_Armors_Buttons->Add(Units_Armors_PasteInsert, 1, wxEXPAND);

	Units_Armors_ListArea->Add(Units_Armors_Search, 0, wxEXPAND);
	Units_Armors_ListArea->Add(Units_Armors_Search_R, 0, wxEXPAND);
	Units_Armors_ListArea->AddSpacer(2);
	Units_Armors_ListArea->Add(Units_Armors_ListV, 1, wxEXPAND);
	Units_Armors_ListArea->AddSpacer(2);
	Units_Armors_ListArea->Add(Units_Armors_Buttons, 0, wxEXPAND);
	Units_Armors_ListArea->AddSpacer(2);
	Units_Armors_ListArea->Add(Units_Armors_CopyToUnits, 0, wxEXPAND);

	UnitCommands_One_Holder->Add(UnitCommands_One_Text, 0, wxEXPAND);
	UnitCommands_One_Holder->Add(UnitCommands_One, 1, wxEXPAND);
	UnitCommands_ID_Holder->Add(UnitCommands_ID_Text, 0, wxEXPAND);
	UnitCommands_ID_Holder->Add(UnitCommands_ID, 1, wxEXPAND);
	UnitCommands_Unknown1_Holder->Add(UnitCommands_Unknown1_Text, 0, wxEXPAND);
	UnitCommands_Unknown1_Holder->Add(UnitCommands_Unknown1, 0, wxEXPAND);
	UnitCommands_Type_Holder->Add(UnitCommands_Type_Text, 0, wxEXPAND);
	UnitCommands_Type_Holder->Add(UnitCommands_Type, 0, wxEXPAND);
	UnitCommands_Type_Holder->Add(UnitCommands_Type_ComboBox, 0, wxEXPAND);
	UnitCommands_ProductivityResource_Holder->Add(UnitCommands_ProductivityResource_Text, 0, wxEXPAND);
	UnitCommands_ProductivityResource_Holder->Add(UnitCommands_ProductivityResource, 0, wxEXPAND);
	UnitCommands_ProductivityResource_Holder->Add(UnitCommands_ProductivityResource_ComboBox, 0, wxEXPAND);
	UnitCommands_ClassID_Holder->Add(UnitCommands_ClassID_Text, 0, wxEXPAND);
	UnitCommands_ClassID_Holder->Add(UnitCommands_ClassID, 0, wxEXPAND);
	UnitCommands_ClassID_Holder->Add(Units_Class_ComboBox[1], 0, wxEXPAND);
	UnitCommands_UnitID_Holder->Add(UnitCommands_UnitID_Text, 0, wxEXPAND);
	UnitCommands_UnitID_Holder->Add(UnitCommands_UnitID, 0, wxEXPAND);
	UnitCommands_UnitID_Holder->Add(UnitCommands_UnitID_ComboBox, 0, wxEXPAND);
	UnitCommands_TerrainID_Holder->Add(UnitCommands_TerrainID_Text, 0, wxEXPAND);
	UnitCommands_TerrainID_Holder->Add(UnitCommands_TerrainID, 0, wxEXPAND);
	UnitCommands_TerrainID_Holder->Add(UnitCommands_TerrainID_ComboBox, 0, wxEXPAND);
	UnitCommands_ResourceIn_Holder->Add(UnitCommands_ResourceIn_Text, 0, wxEXPAND);
	UnitCommands_ResourceIn_Holder->Add(UnitCommands_ResourceIn, 0, wxEXPAND);
	UnitCommands_ResourceIn_Holder->Add(UnitCommands_ResourceIn_ComboBox, 0, wxEXPAND);
	UnitCommands_ResourceOut_Holder->Add(UnitCommands_ResourceOut_Text, 0, wxEXPAND);
	UnitCommands_ResourceOut_Holder->Add(UnitCommands_ResourceOut, 0, wxEXPAND);
	UnitCommands_ResourceOut_Holder->Add(UnitCommands_ResourceOut_ComboBox, 0, wxEXPAND);
	UnitCommands_Resource_Holder->Add(UnitCommands_Resource_Text, 0, wxEXPAND);
	UnitCommands_Resource_Holder->Add(UnitCommands_Resource, 0, wxEXPAND);
	UnitCommands_Resource_Holder->Add(UnitCommands_Resource_ComboBox, 0, wxEXPAND);
	UnitCommands_WorkRateMultiplier_Holder->Add(UnitCommands_WorkRateMultiplier_Text, 0, wxEXPAND);
	UnitCommands_WorkRateMultiplier_Holder->Add(UnitCommands_WorkRateMultiplier, 0, wxEXPAND);
	UnitCommands_ExecutionRadius_Holder->Add(UnitCommands_ExecutionRadius_Text, 0, wxEXPAND);
	UnitCommands_ExecutionRadius_Holder->Add(UnitCommands_ExecutionRadius, 0, wxEXPAND);
	UnitCommands_ExtraRange_Holder->Add(UnitCommands_ExtraRange_Text, 0, wxEXPAND);
	UnitCommands_ExtraRange_Holder->Add(UnitCommands_ExtraRange, 0, wxEXPAND);
	UnitCommands_Unknown4_Holder->Add(UnitCommands_Unknown4_Text, 0, wxEXPAND);
	UnitCommands_Unknown4_Holder->Add(UnitCommands_Unknown4, 0, wxEXPAND);
	UnitCommands_Unknown5_Holder->Add(UnitCommands_Unknown5_Text, 0, wxEXPAND);
	UnitCommands_Unknown5_Holder->Add(UnitCommands_Unknown5, 0, wxEXPAND);
	UnitCommands_SelectionEnabler_Holder->Add(UnitCommands_SelectionEnabler_Text, 0, wxEXPAND);
	UnitCommands_SelectionEnabler_Holder->Add(UnitCommands_SelectionEnabler, 0, wxEXPAND);
	UnitCommands_Unknown7_Holder->Add(UnitCommands_Unknown7_Text, 0, wxEXPAND);
	UnitCommands_Unknown7_Holder->Add(UnitCommands_Unknown7, 0, wxEXPAND);
	UnitCommands_Unknown8_Holder->Add(UnitCommands_Unknown8_Text, 0, wxEXPAND);
	UnitCommands_Unknown8_Holder->Add(UnitCommands_Unknown8, 0, wxEXPAND);
	UnitCommands_Unknown9_Holder->Add(UnitCommands_Unknown9_Text, 0, wxEXPAND);
	UnitCommands_Unknown9_Holder->Add(UnitCommands_Unknown9, 0, wxEXPAND);
	UnitCommands_SelectionMode_Holder->Add(UnitCommands_SelectionMode_Text, 0, wxEXPAND);
	UnitCommands_SelectionMode_Holder->Add(UnitCommands_SelectionMode, 0, wxEXPAND);
	UnitCommands_Unknown11_Holder->Add(UnitCommands_Unknown11_Text, 0, wxEXPAND);
	UnitCommands_Unknown11_Holder->Add(UnitCommands_Unknown11, 0, wxEXPAND);
	UnitCommands_Unknown12_Holder->Add(UnitCommands_Unknown12_Text, 0, wxEXPAND);
	UnitCommands_Unknown12_Holder->Add(UnitCommands_Unknown12, 0, wxEXPAND);

	for(short loop = 0; loop < UnitCommands_Graphics.size(); ++loop)
	{
		UnitCommands_Graphics_Holder[loop]->Add(UnitCommands_Graphics_Text[loop], 0, wxEXPAND);
		UnitCommands_Graphics_Holder[loop]->Add(UnitCommands_Graphics[loop], 0, wxEXPAND);
		UnitCommands_Graphics_Holder[loop]->Add(UnitCommands_Graphics_ComboBox[loop], 0, wxEXPAND);
		UnitCommands_Graphics_Grid->Add(UnitCommands_Graphics_Holder[loop], 1, wxEXPAND);
	}

	Units_TypeArea_Holder->Add(Units_Name_Holder, 3, wxEXPAND);
	Units_TypeArea_Holder->AddSpacer(5);
	Units_TypeArea_Holder->Add(Units_Name2_Holder, 3, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_TypeArea_Holder->AddSpacer(5);
	Units_TypeArea_Holder->Add(Units_ID1_Holder, 1, wxEXPAND);
	Units_TypeArea_Holder->AddSpacer(5);
	Units_TypeArea_Holder->Add(Units_ID2_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_TypeArea_Holder->AddSpacer(5);
	Units_TypeArea_Holder->Add(Units_ID3_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);

	Units_LanguageDLLName_Holder->Add(Units_LanguageDLLName_Text, 0, wxEXPAND);
	Units_LanguageDLLName_Holder->Add(Units_LanguageDLLName, 0, wxEXPAND);
	Units_LanguageDLLName_Holder->Add(Units_DLL_LanguageName, 1, wxEXPAND);
	Units_LanguageDLLCreation_Holder->Add(Units_LanguageDLLCreation_Text, 0, wxEXPAND);
	Units_LanguageDLLCreation_Holder->Add(Units_LanguageDLLCreation, 0, wxEXPAND);
	Units_LanguageDLLCreation_Holder->Add(Units_DLL_LanguageCreation, 1, wxEXPAND);
	Units_LanguageDLLHelp_Holder->Add(Units_LanguageDLLHelp_Text, 0, wxEXPAND);
	Units_LanguageDLLHelp_Holder->Add(Units_LanguageDLLHelp, 0, wxEXPAND);
	Units_LanguageDLLConverter_Holder[0]->Add(Units_LanguageDLLConverter_Text[0], 0, wxEXPAND);
	Units_LanguageDLLConverter_Holder[0]->Add(Units_LanguageDLLConverter[0], 0, wxEXPAND);
	Units_LanguageDLLHotKeyText_Holder->Add(Units_LanguageDLLHotKeyText_Text, 0, wxEXPAND);
	Units_LanguageDLLHotKeyText_Holder->Add(Units_LanguageDLLHotKeyText, 0, wxEXPAND);
	Units_LanguageDLLConverter_Holder[1]->Add(Units_LanguageDLLConverter_Text[1], 0, wxEXPAND);
	Units_LanguageDLLConverter_Holder[1]->Add(Units_LanguageDLLConverter[1], 0, wxEXPAND);
	Units_HotKey_Holder->Add(Units_HotKey_Text, 0, wxEXPAND);
	Units_HotKey_Holder->Add(Units_HotKey, 0, wxEXPAND);
	Units_HotKey_Holder->Add(Units_DLL_HotKey4, 1, wxEXPAND);

	Units_LangRegular_Holder->Add(Units_LanguageDLLName_Holder, 1, wxEXPAND);
	Units_LangRegular_Holder->AddSpacer(5);
	Units_LangRegular_Holder->Add(Units_LanguageDLLCreation_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_LangRegular_Holder->AddSpacer(5);
	Units_LangRegular_Holder->Add(Units_HotKey_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_LangHotKey_Holder->Add(Units_LanguageDLLHelp_Holder, 1, wxEXPAND);
	Units_LangHotKey_Holder->AddSpacer(5);
	Units_LangHotKey_Holder->Add(Units_LanguageDLLConverter_Holder[0], 1, wxEXPAND);
	Units_LangHotKey_Holder->AddSpacer(5);
	Units_LangHotKey_Holder->Add(Units_LanguageDLLHotKeyText_Holder, 1, wxEXPAND);
	Units_LangHotKey_Holder->AddSpacer(5);
	Units_LangHotKey_Holder->Add(Units_LanguageDLLConverter_Holder[1], 1, wxEXPAND);

	Units_LangDLLArea_Holder->Add(Units_LangRegular_Holder, 0, wxEXPAND);
	Units_LangDLLArea_Holder->AddSpacer(5);
	Units_LangDLLArea_Holder->Add(Units_LangHotKey_Holder, 0, wxEXPAND);
	Units_LangDLLArea_Holder->AddSpacer(5);
	Units_LangDLLArea_Holder->Add(Units_DLL_LanguageHelp, 0, wxEXPAND);
	Units_LangDLLArea_Holder->Add(Units_DLL_LanguageHKText, 0, wxEXPAND);

	Units_StandingGraphic_Grid->Add(Units_StandingGraphic[0], 1, wxEXPAND);
	Units_StandingGraphic_Grid->Add(Units_StandingGraphic[1], 1, wxEXPAND);
	Units_StandingGraphic_Grid->Add(Units_StandingGraphic_ComboBox[0], 1, wxEXPAND);
	Units_StandingGraphic_Grid->Add(Units_StandingGraphic_ComboBox[1], 1, wxEXPAND);
	Units_StandingGraphic_Holder->Add(Units_StandingGraphic_Text, 0, wxEXPAND);
	Units_StandingGraphic_Holder->Add(Units_StandingGraphic_Grid, 0, wxEXPAND);
	Units_GarrisonGraphic_Holder->Add(Units_GarrisonGraphic_Text, 0, wxEXPAND);
	Units_GarrisonGraphic_Holder->Add(Units_GarrisonGraphic, 0, wxEXPAND);
	Units_GarrisonGraphic_Holder->Add(Units_GarrisonGraphic_ComboBox, 0, wxEXPAND);
	Units_WalkingGraphic_Grid->Add(Units_WalkingGraphic[0], 1, wxEXPAND);
	Units_WalkingGraphic_Grid->Add(Units_WalkingGraphic[1], 1, wxEXPAND);
	Units_WalkingGraphic_Grid->Add(Units_WalkingGraphic_ComboBox[0], 1, wxEXPAND);
	Units_WalkingGraphic_Grid->Add(Units_WalkingGraphic_ComboBox[1], 1, wxEXPAND);
	Units_WalkingGraphic_Holder->Add(Units_WalkingGraphic_Text, 0, wxEXPAND);
	Units_WalkingGraphic_Holder->Add(Units_WalkingGraphic_Grid, 0, wxEXPAND);
	Units_DyingGraphic_Grid->Add(Units_DyingGraphic[0], 1, wxEXPAND);
	Units_DyingGraphic_Grid->Add(Units_DyingGraphic[1], 1, wxEXPAND);
	Units_DyingGraphic_Grid->Add(Units_DyingGraphic_ComboBox[0], 1, wxEXPAND);
	Units_DyingGraphic_Grid->Add(Units_DyingGraphic_ComboBox[1], 1, wxEXPAND);
	Units_DyingGraphic_Holder->Add(Units_DyingGraphic_Text, 0, wxEXPAND);
	Units_DyingGraphic_Holder->Add(Units_DyingGraphic_Grid, 0, wxEXPAND);

	Units_IconID_Grid->Add(Units_IconID_SLP, 1, wxEXPAND);
	Units_IconID_Grid->Add(Units_IconID_Holder, 1, wxEXPAND);
	Units_IconID_Grid->Add(Units_IconAngle_Holder, 1, wxEXPAND);
	Units_GraphicsArea4_Holder->Add(Units_IconID_Grid, 1, wxEXPAND);
	Units_GraphicsArea4_Holder->Add(Units_StandingGraphic_Holder, 1, wxEXPAND);
	Units_GraphicsArea4_Holder->Add(Units_DyingGraphic_Holder, 1, wxEXPAND);
	Units_GraphicsArea4_Holder->Add(Units_WalkingGraphic_Holder, 1, wxEXPAND);

	Units_GraphicsArea5_Holder->Add(Units_SnowGraphicID_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_GraphicsArea5_Holder->Add(Units_ConstructionGraphicID_Holder, 1, wxEXPAND);
	Units_GraphicsArea5_Holder->Add(Units_AttackGraphic_Holder, 1, wxEXPAND);
	Units_GraphicsArea5_Holder->Add(Units_GarrisonGraphic_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);

	DamageGraphics_GraphicID_Holder->Add(DamageGraphics_GraphicID_Text, 0, wxEXPAND);
	DamageGraphics_GraphicID_Holder->Add(DamageGraphics_GraphicID, 1, wxEXPAND);
	DamageGraphics_GraphicID_Holder->Add(DamageGraphics_GraphicID_ComboBox, 1, wxEXPAND);
	DamageGraphics_Unknown1_Holder->Add(DamageGraphics_Unknown1_Text, 0, wxEXPAND);
	DamageGraphics_Unknown1_Holder->Add(DamageGraphics_Unknown1, 1, wxEXPAND);
	DamageGraphics_DamagePercent_Holder->Add(DamageGraphics_DamagePercent_Text, 0, wxEXPAND);
	DamageGraphics_DamagePercent_Holder->Add(DamageGraphics_DamagePercent, 1, wxEXPAND);
	DamageGraphics_Unknown2_Holder->Add(DamageGraphics_Unknown2_Text, 0, wxEXPAND);
	DamageGraphics_Unknown2_Holder->Add(DamageGraphics_Unknown2, 1, wxEXPAND);
	Units_DamageGraphics_Holder_Data->Add(slpdmgunit, 0, wxEXPAND);
	Units_DamageGraphics_Holder_Data->AddSpacer(5);
	Units_DamageGraphics_Holder_Data->Add(DamageGraphics_GraphicID_Holder, 0, wxEXPAND);
	Units_DamageGraphics_Holder_Data->AddSpacer(5);
	Units_DamageGraphics_Holder_Data->Add(DamageGraphics_DamagePercent_Holder, 0, wxEXPAND);
	Units_DamageGraphics_Holder_Data->AddSpacer(5);
	Units_DamageGraphics_Holder_Data->Add(DamageGraphics_Unknown1_Holder, 0, wxEXPAND);
	Units_DamageGraphics_Holder_Data->AddSpacer(5);
	Units_DamageGraphics_Holder_Data->Add(DamageGraphics_Unknown2_Holder, 0, wxEXPAND);

	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_Add, 1, wxEXPAND);
	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_Delete, 1, wxEXPAND);
	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_Insert, 1, wxEXPAND);
	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_Copy, 1, wxEXPAND);
	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_Paste, 1, wxEXPAND);
	Units_DamageGraphics_Buttons->Add(Units_DamageGraphics_PasteInsert, 1, wxEXPAND);

	Units_DamageGraphics_ListArea->Add(Units_DamageGraphics_Search, 0, wxEXPAND);
	Units_DamageGraphics_ListArea->Add(Units_DamageGraphics_Search_R, 0, wxEXPAND);
	Units_DamageGraphics_ListArea->AddSpacer(2);
	Units_DamageGraphics_ListArea->Add(Units_DamageGraphics_ListV, 1, wxEXPAND);
	Units_DamageGraphics_ListArea->AddSpacer(2);
	Units_DamageGraphics_ListArea->Add(Units_DamageGraphics_Buttons, 0, wxEXPAND);
	Units_DamageGraphics_ListArea->AddSpacer(2);
	Units_DamageGraphics_ListArea->Add(Units_DamageGraphics_CopyToUnits, 0, wxEXPAND);

	Units_DamageGraphics->Add(Units_DamageGraphics_ListArea, 1, wxEXPAND);
	Units_DamageGraphics->AddSpacer(5);
	Units_DamageGraphics->Add(Units_DamageGraphics_Holder_Data, 1, wxEXPAND);

	Units_GraphicsArea1_Holder->Add(Units_DamageGraphics, 1, wxEXPAND);
	Units_GraphicsArea1_Holder->AddSpacer(5);
	Units_GraphicsArea1_Holder->Add(Units_GraphicsArea4_Holder, 1, wxEXPAND);

	Units_GraphicsArea_Holder->Add(slpradio, 0, wxEXPAND);
	Units_GraphicsArea_Holder->AddSpacer(5);
	Units_GraphicsArea_Holder->Add(Units_GraphicsArea1_Holder, 0, wxEXPAND);
	Units_GraphicsArea_Holder->AddSpacer(5);
	Units_GraphicsArea_Holder->Add(Units_GraphicsArea5_Holder, 0, wxEXPAND);

	Units_StatsArea1_Grid->Add(Units_HitPoints_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_Speed_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_RotationSpeed_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->AddStretchSpacer(1);
	Units_StatsArea1_Grid->AddStretchSpacer(1);
	Units_StatsArea1_Grid->Add(Units_LineOfSight_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_SearchRadius_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_MaxRange_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_MinRange_Holder, 1, wxEXPAND);
	Units_StatsArea1_Grid->Add(Units_DisplayedRange_Holder, 1, wxEXPAND);

	Units_Attacks_DataArea->Add(Attacks_Amount_Holder, 0, wxEXPAND);
	Units_Attacks_DataArea->AddSpacer(5);
	Units_Attacks_DataArea->Add(Attacks_Class_Holder, 0, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_DisplayedAttack_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_Delay_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_AccuracyPercent_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_AccuracyErrorRadius_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_ReloadTime1_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_ReloadTime2_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_BlastRadius_Holder, 1, wxEXPAND);
	Units_Attacks_Grid_Data2->Add(Units_BlastAttackLevel_Holder, 1, wxEXPAND);
	Units_Attacks_Holder_Data->AddSpacer(5);
	Units_Attacks_Holder_Data->Add(Units_Attacks_Grid_Data2, 0, wxEXPAND);

	Units_Armors_DataArea->Add(Armors_Amount_Holder, 0, wxEXPAND);
	Units_Armors_DataArea->Add(Armors_Class_Holder, 0, wxEXPAND);
	Units_Armors_Holder_Data3->AddSpacer(5);
	Units_Armors_Holder_Data3->Add(Units_DefaultArmor_Holder, 0, wxEXPAND);
	Units_Armors_Holder_Data3->AddSpacer(5);
	Units_Armors_Holder_Data3->Add(Units_TerRestrictionForDmgMultiply_Holder, 0, wxEXPAND);
	Units_Armors_Holder_Data3->AddSpacer(5);
	Units_Armors_Holder_Data3->Add(Units_DisplayedMeleeArmour_Holder, 0, wxEXPAND);
	Units_Armors_Holder_Data3->AddSpacer(5);
	Units_Armors_Holder_Data3->Add(Units_DisplayedPierceArmour_Holder, 0, wxEXPAND);
	Units_Armors_Holder_Data3->AddSpacer(5);
	Units_Armors_Holder_Data3->Add(Units_BlastArmorLevel_Holder, 0, wxEXPAND);

	for(short loop = 0; loop < 8; ++loop)
	Units_GarrisonType_Grid->Add(Units_GarrisonType_CheckBox[loop], 1, wxEXPAND);
	Units_GarrisonType_Holder->Add(Units_GarrisonType_Text, 0, wxEXPAND);
	Units_GarrisonType_Holder->Add(Units_GarrisonType, 1, wxEXPAND);
	Units_GarrisonType_Holder->Add(Units_GarrisonType_Grid, 1, wxEXPAND);

	Units_Attacks->Add(Units_Attacks_ListArea, 1, wxEXPAND);
	Units_Attacks->AddSpacer(5);
	Units_Attacks->Add(Units_Attacks_DataArea, 1, wxEXPAND);
	Units_Armors->Add(Units_Armors_ListArea, 1, wxEXPAND);
	Units_Armors->AddSpacer(5);
	Units_Armors->Add(Units_Armors_DataArea, 1, wxEXPAND);
	Units_Attacks_Holder->Add(Units_Attacks, 1, wxEXPAND);
	Units_Attacks_Holder->AddSpacer(5);
	Units_Attacks_Holder->Add(Units_Attacks_Holder_Data, 1, wxEXPAND);
	Units_Armors_Holder->Add(Units_Armors, 2, wxEXPAND);
	Units_Armors_Holder->AddSpacer(5);
	Units_Armors_Holder->Add(Units_Armors_Holder_Data3, 1, wxEXPAND);
	Units_Armors_Holder->AddStretchSpacer(1);
	Units_StatsAreaGarrison_Grid->Add(Units_GarrisonCapacity_Holder, 1, wxEXPAND);
	Units_StatsAreaGarrison_Grid->Add(Units_GarrisonType_Holder, 2, wxEXPAND);
	Units_StatsAreaGarrison_Grid->Add(Units_GarrisonHealRate_Holder, 1, wxEXPAND);
	Units_StatsArea2_Grid->Add(Units_ResourceCapacity_Holder, 1, wxEXPAND);
	Units_StatsArea2_Grid->Add(Units_ResourceDecay_Holder, 1, wxEXPAND);
	Units_StatsArea2_Grid->Add(Units_WorkRate_Holder, 1, wxEXPAND);

	Units_StatsArea_Holder->Add(Units_StatsArea1_Grid, 0, wxEXPAND);
	Units_StatsArea_Holder->AddSpacer(5);
	Units_StatsArea_Holder->Add(Units_Attacks_Holder, 0, wxEXPAND);
	Units_StatsArea_Holder->AddSpacer(5);
	Units_StatsArea_Holder->Add(Units_Armors_Holder, 0, wxEXPAND);
	Units_StatsArea_Holder->AddSpacer(5);
	Units_StatsArea_Holder->Add(Units_StatsArea2_Grid, 0, wxEXPAND);
	Units_StatsArea_Holder->AddSpacer(5);
	Units_StatsArea_Holder->Add(Units_StatsAreaGarrison_Grid, 0, wxEXPAND);


	Units_ProjectileUnitID_Holder->Add(Units_ProjectileUnitID_Text, 0, wxEXPAND);
	Units_ProjectileUnitID_Holder->Add(Units_ProjectileUnitID, 1, wxEXPAND);
	Units_ProjectileUnitID_Holder->Add(Units_ProjectileUnitID_ComboBox, 1, wxEXPAND);
	Units_AttackMissileDuplicationUnit_Holder->Add(Units_AttackMissileDuplicationUnit_Text, 0, wxEXPAND);
	Units_AttackMissileDuplicationUnit_Holder->Add(Units_AttackMissileDuplicationUnit, 1, wxEXPAND);
	Units_AttackMissileDuplicationUnit_Holder->Add(Units_AttackMissileDuplicationUnit_ComboBox, 1, wxEXPAND);
	Units_ChargingGraphic_Holder->Add(Units_ChargingGraphic_Text, 0, wxEXPAND);
	Units_ChargingGraphic_Holder->Add(Units_ChargingGraphic, 1, wxEXPAND);
	Units_ChargingGraphic_Holder->Add(Units_ChargingGraphic_ComboBox, 1, wxEXPAND);

	Units_ProjectilesArea1_Grid->Add(Units_StretchMode_Holder, 1, wxEXPAND);
	Units_ProjectilesArea1_Grid->Add(Units_CompensationMode_Holder, 1, wxEXPAND);
	Units_ProjectilesArea1_Grid->Add(Units_DropAnimationMode_Holder, 1, wxEXPAND);
	Units_ProjectilesArea1_Grid->AddStretchSpacer(1);
	Units_ProjectilesArea1_Grid->AddStretchSpacer(1);
	Units_ProjectilesArea1_Grid->Add(Units_PenetrationMode_Holder, 1, wxEXPAND);
	Units_ProjectilesArea1_Grid->Add(Units_Unknown24_Holder, 1, wxEXPAND);
	Units_ProjectilesArea1_Grid->Add(Units_ProjectileArc_Holder, 1, wxEXPAND);

	Units_ProjectilesArea2_Grid->Add(Units_ProjectileUnitID_Holder, 2, wxEXPAND);
	Units_ProjectilesArea3_Grid->Add(Units_MissileCount_Holder, 1, wxEXPAND);
	Units_ProjectilesArea3_Grid->Add(Units_MissileDuplicationCount_Holder, 1, wxEXPAND);
	Units_ProjectilesArea2_Grid->Add(Units_AttackMissileDuplicationUnit_Holder, 1, wxEXPAND);
	Units_ProjectilesArea2_Grid->Add(Units_ChargingGraphic_Holder, 1, wxEXPAND);
	Units_ProjectilesArea2_Grid->Add(Units_ChargingMode_Holder, 1, wxEXPAND);

	Units_ProjectilesArea_Holder->Add(Units_ProjectilesArea2_Grid, 0, wxEXPAND);
	Units_ProjectilesArea_Holder->AddSpacer(5);
	Units_ProjectilesArea_Holder->Add(Units_ProjectilesArea3_Grid, 0, wxEXPAND);
	Units_ProjectilesArea_Holder->AddSpacer(5);
	Units_ProjectilesArea_Holder->Add(Units_AttackMissileDuplicationSpawning_Holder, 0, wxEXPAND);
	Units_ProjectilesArea_Holder->AddSpacer(5);
	Units_ProjectilesArea_Holder->Add(Units_GraphicDisplacement_Holder, 0, wxEXPAND);
	Units_ProjectilesArea_Holder->AddSpacer(5);
	Units_ProjectilesArea_Holder->Add(Units_ProjectilesArea1_Grid, 0, wxEXPAND);

	Units_AttributesBoxes1_Grid->Add(Units_Enabled_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_Disabled_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_DeathMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_HideInEditor_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_AirMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_FlyMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_SheepConversion_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_AnimalMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_AdjacentMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_Unknown31b_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_TowerMode_Holder, 1, wxEXPAND);
	Units_AttributesBoxes1_Grid->Add(Units_HeroMode_Holder, 1, wxEXPAND);

	Units_AttributesModes1_Grid->Add(Units_PlacementMode_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_HillMode_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_VisibleInFog_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_TriggerType_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_InteractionMode_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_MinimapMode_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_MinimapColor_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_AttackMode_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_EdibleMeat_Holder, 1, wxEXPAND);
	Units_AttributesModes1_Grid->Add(Units_VillagerMode_Holder, 1, wxEXPAND);

	Units_Attributes2_Grid->Add(Units_Attribute_Holder, 1, wxEXPAND);
	Units_AttributesTerrain_Holder->Add(Units_PlacementTerrain_Holder, 1, wxEXPAND);
	Units_AttributesTerrain_Holder->AddSpacer(5);
	Units_AttributesTerrain_Holder->Add(Units_PlacementBypassTerrain_Holder, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_AttributesTerrain_Grid->Add(Units_TerrainRestriction_Holder, 1, wxEXPAND);
	Units_AttributesDropSite_Holder->Add(Units_DropSite_Grid, 0, wxEXPAND);
	Units_AttributesSizes_Holder->Add(Units_SizeRadius_Holder, 1, wxEXPAND);
	Units_AttributesSizes_Holder->Add(Units_EditorRadius_Holder, 1, wxEXPAND);
	Units_AttributesSizes_Holder->Add(Units_SelectionRadius_Holder, 1, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_Unselectable_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_Unknown6_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_Unknown7_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_Unknown8_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->AddStretchSpacer(1);
	Units_AttributesSelection1_Grid->Add(Units_SelectionMask_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_SelectionShapeType_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_SelectionShape_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->AddStretchSpacer(1);
	Units_AttributesSelection1_Grid->AddStretchSpacer(1);
	Units_AttributesSelection1_Grid->Add(Units_SelectionEffect_Holder, 0, wxEXPAND);
	Units_AttributesSelection1_Grid->Add(Units_EditorSelectionColour_Holder, 0, wxEXPAND);
	Units_ResourceStorageHeader_Holder->Add(Units_ResourceStorage_Holder[0], 0, wxEXPAND);
	Units_ResourceStorageHeader_Holder->AddSpacer(5);
	Units_ResourceStorageHeader_Holder->Add(Units_ResourceStorage_Holder[1], 0, wxEXPAND);
	Units_ResourceStorageHeader_Holder->AddSpacer(5);
	Units_ResourceStorageHeader_Holder->Add(Units_ResourceStorage_Holder[2], 0, wxEXPAND);
	Units_Attributes1_Grid->Add(Units_DeadUnitID_Holder, 1, wxEXPAND);
	Units_Attributes2_Grid->Add(Units_Civ_Holder, 1, wxEXPAND);
	Units_Attributes2_Grid->Add(Units_Unknown9_Holder, 1, wxEXPAND);
	Units_Attributes1_Grid->Add(Units_Unitline_Holder, 1, wxEXPAND);
	Units_Attributes1_Grid->Add(Units_MinTechLevel_Holder, 1, wxEXPAND);
	Units_AttributesTracking_Grid->Add(Units_TrackingUnit_Holder, 1, wxEXPAND);
	Units_AttributesTracking_Grid->Add(Units_TrackingUnitUsed_Holder, 1, wxEXPAND);
	Units_AttributesTracking_Grid->Add(Units_TrackingUnitDensity_Holder, 1, wxEXPAND);
	Units_CostHeader_Holder->Add(Units_CostType_Holder, 0, wxEXPAND);
	Units_CostHeader_Holder->AddSpacer(5);
	Units_CostHeader_Holder->Add(Units_CostAmount_Holder, 0, wxEXPAND);
	Units_CostHeader_Holder->AddSpacer(5);
	Units_CostHeader_Holder->Add(Units_CostUsed_Holder, 0, wxEXPAND);
	Units_AttributesTrain1_Grid->Add(Units_CommandID_Holder, 1, wxEXPAND);
	Units_AttributesTrain1_Grid->Add(Units_TrainTime_Holder, 1, wxEXPAND);
	Units_AttributesTrain1_Grid->Add(Units_TrainLocationID_Holder, 1, wxEXPAND);
	Units_Attributes3_Grid->Add(Units_StackUnitID_Holder, 1, wxEXPAND);
	Units_AttributesTerrain_Grid->Add(Units_TerrainID_Holder, 1, wxEXPAND);
	Units_AttributesTerrain_Grid->Add(Units_OldTerrainLikeID_Holder, 1, wxEXPAND);
	Units_AttributesTerrain_Grid->Add(Units_ResearchID_Holder, 1, wxEXPAND);
	Units_Attributes3_Grid->Add(Units_HeadUnit_Holder, 1, wxEXPAND);
	Units_Attributes3_Grid->Add(Units_TransformUnit_Holder, 1, wxEXPAND);
	Units_Attributes3_Grid->Add(Units_PileUnit_Holder, 1, wxEXPAND);
	Units_AttributesTrain1_Grid->Add(Units_ButtonID_Holder, 1, wxEXPAND);

	Units_Attributes_Holder->Add(Units_AttributesBoxes1_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesModes1_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_Attributes2_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_Attributes1_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesTerrain_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesTerrain_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesDropSite_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesSizes_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesSelection1_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesTracking_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_RotationAngles_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AttributesTrain1_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_ResourceStorageHeader_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_CostHeader_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_Attributes3_Grid, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AnnexUnit1_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_AnnexUnitMisplacement1_Holder, 0, wxEXPAND);
	Units_Attributes_Holder->AddSpacer(5);
	Units_Attributes_Holder->Add(Units_LootSwitch_Holder, 0, wxEXPAND);

	Units_TrainSound1_Holder->Add(Units_TrainSound[0], 1, wxEXPAND);
	Units_TrainSound1_Holder->Add(Units_TrainSound_ComboBox[0], 1, wxEXPAND);
	Units_TrainSound2_Holder->Add(Units_TrainSound[1], 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);
	Units_TrainSound2_Holder->Add(Units_TrainSound_ComboBox[1], 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);

	Units_TrainSound3_Holder->Add(Units_TrainSound1_Holder, 1, wxEXPAND);
	Units_TrainSound3_Holder->AddSpacer(5);
	Units_TrainSound3_Holder->Add(Units_TrainSound2_Holder, 1, wxEXPAND);

	Units_TrainSound_Holder->Add(Units_TrainSound_Text, 0, wxEXPAND);
	Units_TrainSound_Holder->Add(Units_TrainSound3_Holder, 1, wxEXPAND);

	Units_SoundsArea1_Holder->Add(Units_SelectionSound_Holder, 1, wxEXPAND);
	Units_SoundsArea1_Holder->AddSpacer(5);
	Units_SoundsArea1_Holder->Add(Units_DyingSound_Holder, 1, wxEXPAND);
	Units_SoundsArea1_Holder->AddSpacer(5);
	Units_SoundsArea1_Holder->Add(Units_TrainSound_Holder, 2, wxEXPAND);
	Units_SoundsArea2_Grid->Add(Units_AttackSound_Holder, 1, wxEXPAND);
	Units_SoundsArea2_Grid->Add(Units_MoveSound_Holder, 1, wxEXPAND);
	Units_SoundsArea2_Grid->Add(Units_ConstructionSound_Holder, 1, wxEXPAND);
	Units_SoundsArea2_Grid->Add(Units_UnknownSound_Holder, 1, wxEXPAND);

	Units_SoundsArea_Holder->Add(Units_SoundsArea1_Holder, 0, wxEXPAND);
	Units_SoundsArea_Holder->AddSpacer(5);
	Units_SoundsArea_Holder->Add(Units_SoundsArea2_Grid, 0, wxEXPAND);

	Units_HPBars_Grid->Add(Units_HPBarHeight1_Holder, 1, wxEXPAND);
	Units_HPBars_Grid->Add(Units_HPBarHeight2_Holder, 1, wxEXPAND);
	Units_MiscArea_Holder->Add(Units_HPBars_Grid, 1, wxEXPAND);

	Units_Type10plusUnknowns_Grid->Add(Units_Unknown1_Holder, 0, wxEXPAND);
	Units_Type10plusUnknowns_Grid->Add(Units_Unknown3A_Holder, 0, wxEXPAND);
	Units_Type10plusUnknownArea_Holder->Add(Units_Type10plusUnknowns_Grid, 0, wxEXPAND);

	Units_Type30plusUnknownArea_Grid->Add(Units_Unknown11_Holder, 0, wxEXPAND);
	Units_Type30plusUnknownArea_Grid->Add(Units_Unknown16_Holder, 0, wxEXPAND);
	Units_Type30plusUnknownArea_Holder->Add(Units_Type30plusUnknownArea_Grid, 0, wxEXPAND);

	Units_Type70plusUnknownArea_Grid->Add(Units_Unknown26_Holder, 0, wxEXPAND);
	Units_Type70plusUnknownArea_Grid->Add(Units_Unknown27_Holder, 0, wxEXPAND);
	Units_Type70plusUnknownArea_Grid->Add(Units_Unknown28_Holder, 0, wxEXPAND);
	Units_Type70plusUnknownArea_Holder->Add(Units_Type70plusUnknownArea_Grid, 0, wxEXPAND);

	Units_Type80plusUnknownArea_Grid->Add(Units_Unknown33_Holder, 0, wxEXPAND);
	Units_Type80plusUnknownArea_Grid->Add(Units_Unknown35_Holder, 0, wxEXPAND);
	Units_Type80plusUnknownArea_Holder->Add(Units_Type80plusUnknownArea_Grid, 0, wxEXPAND);

	Units_UnitCommands_Buttons->Add(Units_UnitCommands_Add, 1, wxEXPAND);
	Units_UnitCommands_Buttons->Add(Units_UnitCommands_Delete, 1, wxEXPAND);
	Units_UnitCommands_Buttons->Add(Units_UnitCommands_Insert, 1, wxEXPAND);
	Units_UnitCommands_Buttons->Add(Units_UnitCommands_Copy, 1, wxEXPAND);
	Units_UnitCommands_Buttons->Add(Units_UnitCommands_Paste, 1, wxEXPAND);
	Units_UnitCommands_Buttons->Add(Units_UnitCommands_PasteInsert, 1, wxEXPAND);

	Units_UnitCommands->Add(Units_UnitCommands_Search, 0, wxEXPAND);
	Units_UnitCommands->Add(Units_UnitCommands_Search_R, 0, wxEXPAND);
	Units_UnitCommands->AddSpacer(2);
	Units_UnitCommands->Add(Units_UnitCommands_ListV, 1, wxEXPAND);
	Units_UnitCommands->AddSpacer(2);
	Units_UnitCommands->Add(Units_UnitCommands_Buttons, 0, wxEXPAND);
	Units_UnitCommands->AddSpacer(2);
	Units_UnitCommands->Add(Units_UnitCommands_CopyToUnits, 0, wxEXPAND);

	Units_CommandHolder_Lists->Add(Units_UnitHeads_Name, 0, wxEXPAND);
	Units_CommandHolder_Lists->AddSpacer(5);
	Units_CommandHolder_Lists->Add(Units_UnitCommands, 0, wxEXPAND);
	Units_CommandHolder_Lists->AddSpacer(5);
	Units_CommandHolder_Lists->Add(Units_Exists_Holder, 0, wxEXPAND);

	UnitCommands_1_Holder->Add(UnitCommands_One_Holder, 1, wxEXPAND);
	UnitCommands_1_Holder->AddSpacer(5);
	UnitCommands_1_Holder->Add(UnitCommands_ID_Holder, 1, wxEXPAND);

	Units_CommandHolder_Grid1->Add(UnitCommands_ClassID_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_UnitID_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_TerrainID_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_ResourceIn_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_ProductivityResource_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_ResourceOut_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_Resource_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid1->Add(UnitCommands_WorkRateMultiplier_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid2->Add(UnitCommands_ExecutionRadius_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid2->Add(UnitCommands_ExtraRange_Holder, 1, wxEXPAND);

	Units_CommandHolder_Data2->Add(UnitCommands_1_Holder, 0, wxEXPAND);
	Units_CommandHolder_Data2->AddSpacer(5);
	Units_CommandHolder_Data2->Add(UnitCommands_Type_Holder, 0, wxEXPAND);
	Units_CommandHolder_Data2->AddSpacer(5);
	Units_CommandHolder_Data2->Add(Units_CommandHolder_Grid1, 0, wxEXPAND);
	Units_CommandHolder_Data2->AddSpacer(5);
	Units_CommandHolder_Data2->Add(Units_CommandHolder_Grid2, 0, wxEXPAND);
	Units_CommandHolder_Data2->AddSpacer(5);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown1_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown4_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown5_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_SelectionEnabler_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown7_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown8_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown9_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_SelectionMode_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown11_Holder, 1, wxEXPAND);
	Units_CommandHolder_Grid3->Add(UnitCommands_Unknown12_Holder, 1, wxEXPAND);

	Units_CommandHolder_Data1->Add(Units_CommandHolder_Data2, 2, wxEXPAND);
	Units_CommandHolder_Data1->AddSpacer(5);
	Units_CommandHolder_Data1->Add(Units_CommandHolder_Grid3, 1, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN);

	Units_CommandHolder_Data->Add(Units_CommandHolder_Data1, 0, wxEXPAND);
	Units_CommandHolder_Data->AddSpacer(5);
	Units_CommandHolder_Data->Add(UnitCommands_Graphics_Grid, 0, wxEXPAND);

	Units_CommandsArea_Holder->Add(Units_CommandHolder_Lists, 1, wxEXPAND);
	Units_CommandsArea_Holder->AddSpacer(5);
	Units_CommandsArea_Holder->Add(Units_CommandHolder_Data, 3, wxEXPAND);

	Units_UnknownArea_Holder->Add(Units_Type10plusUnknownArea_Holder, 0, wxEXPAND);
	Units_UnknownArea_Holder->AddSpacer(5);
	Units_UnknownArea_Holder->Add(Units_Type30plusUnknownArea_Holder, 0, wxEXPAND);
	Units_UnknownArea_Holder->AddSpacer(5);
	Units_UnknownArea_Holder->Add(Units_Type70plusUnknownArea_Holder, 0, wxEXPAND);
	Units_UnknownArea_Holder->AddSpacer(5);
	Units_UnknownArea_Holder->Add(Units_Type80plusUnknownArea_Holder, 0, wxEXPAND);

	Units_ScrollSpace->Add(Units_LangDLLArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_GraphicsArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_StatsArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_ProjectilesArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_Attributes_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_SoundsArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_MiscArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_UnknownArea_Holder, 0, wxEXPAND);
	Units_ScrollSpace->AddSpacer(5);
	Units_ScrollSpace->Add(Units_CommandsArea_Holder, 0, wxEXPAND);

	Units_ScrollArea->Add(Units_ScrollSpace, 1, wxEXPAND);
	Units_ScrollArea->AddSpacer(5);
	Units_Scroller->SetSizer(Units_ScrollArea);
	Units_Scroller->SetScrollRate(0, 20);

	Units_Top_Holder->Add(Units_AutoCopy, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_CopyTo, 0, wxEXPAND);
	Units_Top_Holder->AddSpacer(5);
	Units_Top_Holder->Add(Units_CopyGraphics, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_CopyToText, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_SelectAll, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_SelectClear, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_GraphicSetText, 0, wxEXPAND);
	Units_Top_Holder->Add(Units_GraphicSet, 0, wxEXPAND);
	Units_Identity_Holder->Add(Units_Type_Holder, 0, wxEXPAND);
	Units_Identity_Holder->AddSpacer(5);
	Units_Identity_Holder->Add(Units_TypeArea_Holder, 0, wxEXPAND);

	Units_DataArea->AddSpacer(15);
	Units_DataArea->Add(Units_Top_Holder, 0, wxEXPAND);
	Units_DataArea->Add(Units_TopGrid_Holder, 0, wxEXPAND);
	Units_DataArea->Add(Units_Identity_Holder, 0, wxEXPAND);
	Units_DataArea->AddSpacer(5);
	Units_DataArea->Add(Units_Scroller, 1, wxEXPAND);
	Units_DataArea->AddSpacer(5);

	Units_Main->AddSpacer(5);
	Units_Main->Add(Units_ListArea, 21, wxEXPAND);
	Units_Main->AddSpacer(5);
	Units_Main->Add(Units_DataArea, 65, wxEXPAND);
	Units_Main->AddSpacer(5);

	if(EnableIDFix)
	{
		Units_ID1->Enable(false);
		Units_ID2->Enable(false);
		Units_ID3->Enable(false);
		UnitCommands_ID->Enable(false);
	}

	Tab_Units->SetSizer(Units_Main);

	Connect(Units_Search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitsSearch));
	Connect(Units_Search_R->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitsSearch));
	Connect(Units_FilterSelector->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnSelection_SearchFilters));
	for(short loop = 0; loop < 2; ++loop)
	{
		Connect(Units_UseAnd[loop]->GetId(), wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsSearch));
		Connect(Units_SearchFilters[loop]->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnSelection_SearchFilters));
	}
	Connect(Units_Civs_List->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitSubList));
	Connect(Units_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitsSelect));
	Connect(Units_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(AGE_Frame::OnUnitsSelect));
	Connect(Units_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_FOCUSED, wxCommandEventHandler(AGE_Frame::OnUnitsSelect));
	Connect(Units_Add->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsAdd));
	Connect(Units_Insert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsInsert));
	Connect(Units_Delete->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsDelete));
	Connect(Units_Copy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsCopy));
	Connect(Units_SpecialCopy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsSpecialCopy));
	Connect(Units_SpecialPaste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsSpecialPaste));
	Connect(Units_Paste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsPaste));
	Connect(Units_PasteInsert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsPasteInsert));
	Connect(Units_Enable->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsEnable));
	Connect(Units_Disable->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitsDisable));
	Connect(Units_UnitCommands_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsSelect));
	Connect(Units_UnitCommands_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsSelect));
	Connect(Units_UnitCommands_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_FOCUSED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsSelect));
	Connect(Units_UnitCommands_Search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsSearch));
	Connect(Units_UnitCommands_Search_R->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsSearch));
	Connect(Units_UnitCommands_Add->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsAdd));
	Connect(Units_UnitCommands_Insert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsInsert));
	Connect(Units_UnitCommands_Delete->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsDelete));
	Connect(Units_UnitCommands_Copy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsCopy));
	Connect(Units_UnitCommands_Paste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsPaste));
	Connect(Units_UnitCommands_PasteInsert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsPasteInsert));
	Connect(Units_UnitCommands_CopyToUnits->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitCommandsCopyToUnits));
	Connect(Units_DamageGraphics_Search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsSearch));
	Connect(Units_DamageGraphics_Search_R->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsSearch));
	Connect(Units_DamageGraphics_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsSelect));
	Connect(Units_DamageGraphics_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsSelect));
	Connect(Units_DamageGraphics_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_FOCUSED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsSelect));
	Connect(Units_DamageGraphics_Add->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsAdd));
	Connect(Units_DamageGraphics_Insert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsInsert));
	Connect(Units_DamageGraphics_Delete->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsDelete));
	Connect(Units_DamageGraphics_Copy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsCopy));
	Connect(Units_DamageGraphics_Paste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsPaste));
	Connect(Units_DamageGraphics_PasteInsert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsPasteInsert));
	Connect(Units_DamageGraphics_CopyToUnits->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitDamageGraphicsCopyToUnits));
	Connect(Units_Attacks_Search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksSearch));
	Connect(Units_Attacks_Search_R->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksSearch));
	Connect(Units_Attacks_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksSelect));
	Connect(Units_Attacks_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksSelect));
	Connect(Units_Attacks_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_FOCUSED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksSelect));
	Connect(Units_Attacks_Add->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksAdd));
	Connect(Units_Attacks_Insert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksInsert));
	Connect(Units_Attacks_Delete->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksDelete));
	Connect(Units_Attacks_Copy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksCopy));
	Connect(Units_Attacks_Paste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksPaste));
	Connect(Units_Attacks_PasteInsert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksPasteInsert));
	Connect(Units_Attacks_CopyToUnits->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitAttacksCopyToUnits));
	Connect(Units_Armors_Search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsSearch));
	Connect(Units_Armors_Search_R->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsSearch));
	Connect(Units_Armors_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsSelect));
	Connect(Units_Armors_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsSelect));
	Connect(Units_Armors_ListV->GetId(), wxEVT_COMMAND_LIST_ITEM_FOCUSED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsSelect));
	Connect(Units_Armors_Add->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsAdd));
	Connect(Units_Armors_Insert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsInsert));
	Connect(Units_Armors_Delete->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsDelete));
	Connect(Units_Armors_Copy->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsCopy));
	Connect(Units_Armors_Paste->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsPaste));
	Connect(Units_Armors_PasteInsert->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsPasteInsert));
	Connect(Units_Armors_CopyToUnits->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AGE_Frame::OnUnitArmorsCopyToUnits));
	Connect(Units_LanguageDLLConverter[0]->GetId(), wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(AGE_Frame::UnitLangDLLConverter));
	Connect(Units_LanguageDLLConverter[1]->GetId(), wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(AGE_Frame::UnitLangDLLConverter));
	Connect(slpradio->GetId(), wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnChooseGraphic));
	Connect(slpdmgunit->GetId(), wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(AGE_Frame::OnChooseGraphic));

    unitTimer.Connect(unitTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitsTimer), NULL, this);
    dmgGraphicTimer.Connect(dmgGraphicTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitDamageGraphicsTimer), NULL, this);
    attackTimer.Connect(attackTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitAttacksTimer), NULL, this);
    armorTimer.Connect(armorTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitArmorsTimer), NULL, this);
    actionTimer.Connect(actionTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitCommandsTimer), NULL, this);
	Units_DLL_LanguageName->Connect(Units_DLL_LanguageName->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_LangDLL), NULL, this);
	Units_DLL_LanguageCreation->Connect(Units_DLL_LanguageCreation->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_LangDLL), NULL, this);
	Units_DLL_HotKey4->Connect(Units_DLL_HotKey4->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_LangDLL), NULL, this);
	Units_DLL_LanguageHelp->Connect(Units_DLL_LanguageHelp->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_LangDLL), NULL, this);
	Units_DLL_LanguageHKText->Connect(Units_DLL_LanguageHKText->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_LangDLL), NULL, this);

//	Listing and Auto-Copy

	Units_Type->Connect(Units_Type->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Connect(Units_Type_ComboBox->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnUpdateCombo_Units));
	Connect(Units_Type_ComboBox->GetId(), wxEVT_MOUSEWHEEL, wxMouseEventHandler(AGE_Frame::wheelParent));

	Units_Name->Connect(Units_Name->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_Name2->Connect(Units_Name2->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_LanguageDLLName->Connect(Units_LanguageDLLName->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_LanguageDLLCreation->Connect(Units_LanguageDLLCreation->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_HotKey->Connect(Units_HotKey->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_LanguageDLLHelp->Connect(Units_LanguageDLLHelp->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_LanguageDLLHotKeyText->Connect(Units_LanguageDLLHotKeyText->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_Attribute->Connect(Units_Attribute->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Units_GarrisonType->Connect(Units_GarrisonType->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);

	DamageGraphics_GraphicID->Connect(DamageGraphics_GraphicID->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	DamageGraphics_GraphicID_ComboBox->Connect(DamageGraphics_GraphicID_ComboBox->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnUpdateCombo_Units), NULL, this);
	DamageGraphics_DamagePercent->Connect(DamageGraphics_DamagePercent->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Attacks_Class->Connect(Attacks_Class->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Attacks_Amount->Connect(Attacks_Amount->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Armors_Class->Connect(Armors_Class->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Armors_Amount->Connect(Armors_Amount->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	for(short loop = 0; loop < 2; ++loop)
	Attacks_Class_ComboBox[loop]->Connect(Attacks_Class_ComboBox[loop]->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnUpdateCombo_Units), NULL, this);

	UnitCommands_Type->Connect(UnitCommands_Type->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	UnitCommands_ProductivityResource->Connect(UnitCommands_ProductivityResource->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler(AGE_Frame::OnKillFocus_Units), NULL, this);
	Connect(UnitCommands_Type_ComboBox->GetId(), wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(AGE_Frame::OnUpdateCombo_Units));
	Connect(UnitCommands_Type_ComboBox->GetId(), wxEVT_MOUSEWHEEL, wxMouseEventHandler(AGE_Frame::wheelParent));
	for(short loop = 0; loop < 8; ++loop)
	{
		Connect(Units_Attribute_CheckBox[loop]->GetId(), wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(AGE_Frame::OnUpdateCheck_UnitAttribute));
		Connect(Units_GarrisonType_CheckBox[loop]->GetId(), wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(AGE_Frame::OnUpdateCheck_UnitGarrisonType));
	}
	Units_IconID_SLP->Connect(Units_IconID_SLP->GetId(), wxEVT_PAINT, wxPaintEventHandler(AGE_Frame::OnDrawIconSLP), NULL, this);
    Units_IconID_SLP->Connect(Units_IconID_SLP->GetId(), wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(AGE_Frame::OnGraphicErase), NULL, this);
    unitAnimTimer.Connect(unitAnimTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler(AGE_Frame::OnUnitAnim), NULL, this);
}

void AGE_Frame::OnKillFocus_Units(wxFocusEvent &event)
{
	event.Skip();
	if(((AGETextCtrl*)event.GetEventObject())->SaveEdits() != 0) return;
	if(event.GetId() == Units_Name->GetId() || event.GetId() == Units_LanguageDLLName->GetId())
	{
		ListUnits(UnitCivID);
	}
	else if(event.GetId() == Units_Type->GetId()
	|| event.GetId() == Units_Name2->GetId()
	|| event.GetId() == Units_LanguageDLLCreation->GetId()
	|| event.GetId() == Units_HotKey->GetId()
	|| event.GetId() == Units_LanguageDLLHelp->GetId()
	|| event.GetId() == Units_LanguageDLLHotKeyText->GetId()
	|| event.GetId() == Units_Attribute->GetId()
	|| event.GetId() == Units_GarrisonType->GetId())
	{
		wxTimerEvent E;
		OnUnitsTimer(E);
	}
	else if(event.GetId() == Attacks_Amount->GetId() || event.GetId() == Attacks_Class->GetId())
	{
		ListUnitAttacks();
	}
	else if(event.GetId() == Armors_Amount->GetId() || event.GetId() == Armors_Class->GetId())
	{
		ListUnitArmors();
	}
	else if(event.GetId() == UnitCommands_Type->GetId() || event.GetId() == UnitCommands_ProductivityResource->GetId())
	{
		ListUnitCommands();
	}
	else if(event.GetId() == DamageGraphics_DamagePercent->GetId()
	|| event.GetId() == DamageGraphics_GraphicID->GetId())
	{
		ListUnitDamageGraphics();
	}
}

void AGE_Frame::OnUpdateCombo_Units(wxCommandEvent &event)
{
	if(event.GetId() == Units_Type_ComboBox->GetId())
	{
		switch(Units_Type_ComboBox->GetSelection())
		{
			case 1: Units_Type->ChangeValue("10"); break;
			case 2: Units_Type->ChangeValue("15"); break;
			case 3: Units_Type->ChangeValue("20"); break;
			case 4: Units_Type->ChangeValue("25"); break;
			case 5: Units_Type->ChangeValue("30"); break;
			case 6: Units_Type->ChangeValue("40"); break;
			case 7: Units_Type->ChangeValue("50"); break;
			case 8: Units_Type->ChangeValue("60"); break;
			case 9: Units_Type->ChangeValue("70"); break;
			case 10: Units_Type->ChangeValue("80"); break;
			case 11: Units_Type->ChangeValue("90"); break;
		}
		Units_Type->SaveEdits();
		wxTimerEvent E;
		OnUnitsTimer(E);	// Updates unit layout.
//		ListUnits(UnitCivID, false);	// For special search filters.
		return;
	}
	if(event.GetId() == UnitCommands_Type_ComboBox->GetId())
	{
		switch(UnitCommands_Type_ComboBox->GetSelection())
		{
			case 1: UnitCommands_Type->ChangeValue("1"); break;
			case 2: UnitCommands_Type->ChangeValue("2"); break;
			case 3: UnitCommands_Type->ChangeValue("3"); break;
			case 4: UnitCommands_Type->ChangeValue("4"); break;
			case 5: UnitCommands_Type->ChangeValue("5"); break;
			case 6: UnitCommands_Type->ChangeValue("6"); break;
			case 7: UnitCommands_Type->ChangeValue("7"); break;
			case 8: UnitCommands_Type->ChangeValue("8"); break;
			case 9: UnitCommands_Type->ChangeValue("10"); break;
			case 10: UnitCommands_Type->ChangeValue("11"); break;
			case 11: UnitCommands_Type->ChangeValue("12"); break;
			case 12: UnitCommands_Type->ChangeValue("13"); break;
			case 13: UnitCommands_Type->ChangeValue("20"); break;
			case 14: UnitCommands_Type->ChangeValue("21"); break;
			case 15: UnitCommands_Type->ChangeValue("101"); break;
			case 16: UnitCommands_Type->ChangeValue("102"); break;
			case 17: UnitCommands_Type->ChangeValue("103"); break;
			case 18: UnitCommands_Type->ChangeValue("104"); break;
			case 19: UnitCommands_Type->ChangeValue("105"); break;
			case 20: UnitCommands_Type->ChangeValue("106"); break;
			case 21: UnitCommands_Type->ChangeValue("107"); break;
			case 22: UnitCommands_Type->ChangeValue("108"); break;
			case 23: UnitCommands_Type->ChangeValue("109"); break;
			case 24: UnitCommands_Type->ChangeValue("110"); break;
			case 25: UnitCommands_Type->ChangeValue("111"); break;
			case 26: UnitCommands_Type->ChangeValue("120"); break;
			case 27: UnitCommands_Type->ChangeValue("121"); break;
			case 28: UnitCommands_Type->ChangeValue("122"); break;
			case 29: UnitCommands_Type->ChangeValue("123"); break;
			case 30: UnitCommands_Type->ChangeValue("125"); break;
			case 31: UnitCommands_Type->ChangeValue("131"); break;
			case 32: UnitCommands_Type->ChangeValue("132"); break;
			case 33: UnitCommands_Type->ChangeValue("135"); break;
			case 34: UnitCommands_Type->ChangeValue("136"); break;
			case 35: UnitCommands_Type->ChangeValue("149"); break;
			default: UnitCommands_Type->ChangeValue("-1");
		}
		UnitCommands_Type->SaveEdits();
		ListUnitCommands();
		return;
	}
	((AGEComboBox*)event.GetEventObject())->OnUpdate(event);
	if(event.GetId() == Attacks_Class_ComboBox[0]->GetId())
	{
		ListUnitAttacks();
	}
	else if(event.GetId() == Attacks_Class_ComboBox[1]->GetId())
	{
		ListUnitArmors();
	}
	else if(event.GetId() == DamageGraphics_GraphicID_ComboBox->GetId())
	{
		ListUnitDamageGraphics();
	}
}

void AGE_Frame::OnUpdateCheck_UnitGarrisonType(wxCommandEvent &event)
{
	if(Units_GarrisonType->GetValue().empty()) return;
	uint8_t type = lexical_cast<uint8_t>(Units_GarrisonType->GetValue());
	Units_GarrisonType_CheckBox[0]->GetValue() ? type |= 0x01 : type &= ~0x01;
	Units_GarrisonType_CheckBox[1]->GetValue() ? type |= 0x02 : type &= ~0x02;
	Units_GarrisonType_CheckBox[2]->GetValue() ? type |= 0x04 : type &= ~0x04;
	Units_GarrisonType_CheckBox[3]->GetValue() ? type |= 0x08 : type &= ~0x08;
	Units_GarrisonType_CheckBox[4]->GetValue() ? type |= 0x10 : type &= ~0x10;
	Units_GarrisonType_CheckBox[5]->GetValue() ? type |= 0x20 : type &= ~0x20;
	Units_GarrisonType_CheckBox[6]->GetValue() ? type |= 0x40 : type &= ~0x40;
	Units_GarrisonType_CheckBox[7]->GetValue() ? type |= 0x80 : type &= ~0x80;
	Units_GarrisonType->ChangeValue(lexical_cast<string>((short)type));
	Units_GarrisonType->SaveEdits();
}

void AGE_Frame::OnUpdateCheck_UnitAttribute(wxCommandEvent &event)
{
	if(Units_Attribute->GetValue().empty()) return;
	uint8_t attribute = lexical_cast<uint8_t>(Units_Attribute->GetValue());
	Units_Attribute_CheckBox[0]->GetValue() ? attribute |= 0x01 : attribute &= ~0x01;
	Units_Attribute_CheckBox[1]->GetValue() ? attribute |= 0x02 : attribute &= ~0x02;
	Units_Attribute_CheckBox[2]->GetValue() ? attribute |= 0x04 : attribute &= ~0x04;
	Units_Attribute_CheckBox[3]->GetValue() ? attribute |= 0x08 : attribute &= ~0x08;
	Units_Attribute_CheckBox[4]->GetValue() ? attribute |= 0x10 : attribute &= ~0x10;
	Units_Attribute_CheckBox[5]->GetValue() ? attribute |= 0x20 : attribute &= ~0x20;
	Units_Attribute_CheckBox[6]->GetValue() ? attribute |= 0x40 : attribute &= ~0x40;
	Units_Attribute_CheckBox[7]->GetValue() ? attribute |= 0x80 : attribute &= ~0x80;
	Units_Attribute->ChangeValue(lexical_cast<string>((short)attribute));
	Units_Attribute->SaveEdits();
}
