/*
 * Copyright (C) 2010-2012 OregonCore <http://www.oregoncore.com/>
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2012 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Death_knight_darkreaver
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"

struct boss_death_knight_darkreaverAI : public ScriptedAI
{
    boss_death_knight_darkreaverAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
    }

    void DamageTaken(Unit * /*done_by*/, uint32 &damage)
    {
        if (me->GetHealth() <= damage)
            DoCast(me, 23261, true);   //Summon Darkreaver's Fallen Charger
    }

    void EnterCombat(Unit * /*who*/)
    {
    }
};
CreatureAI* GetAI_boss_death_knight_darkreaver(Creature* pCreature)
{
    return new boss_death_knight_darkreaverAI (pCreature);
}

void AddSC_boss_death_knight_darkreaver()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_death_knight_darkreaver";
    newscript->GetAI = &GetAI_boss_death_knight_darkreaver;
    newscript->RegisterSelf();
}

