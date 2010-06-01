//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef EPERSONALQUESTION_H
#define EPERSONALQUESTION_H
#ifdef _WIN32
#pragma once
#endif

typedef enum EPersonalQuestion
{
	// Never ever change these after initial release.
	k_EPSMsgNameOfSchool = 0,			// Question: What is the name of your school?
	k_EPSMsgFavoriteTeam = 1,			// Question: What is your favorite team?
	k_EPSMsgMothersName = 2,			// Question: What is your mother's maiden name?
	k_EPSMsgNameOfPet = 3,				// Question: What is the name of your pet?
	k_EPSMsgChildhoodHero = 4,			// Question: Who was your childhood hero?
	k_EPSMsgCityBornIn = 5,				// Question: What city were you born in?

	k_EPSMaxPersonalQuestion,

} EPersonalQuestion;

#endif // EPERSONALQUESTION_H
