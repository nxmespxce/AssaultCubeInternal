#pragma once

#include "stdafx.h"

struct EntityListEntry {
	Entity* Ent;
	int ListIdx;
};

namespace EntityList {
	inline Entity* GetEntity(int index) {

		uintptr_t List = *(uintptr_t*)(Globals::ModuleBase + dwEntityList);
		return (Entity*)(List + (index * 0x4));

	}

	inline void Cache() {

		std::vector<EntityListEntry>TempEntityList = {};

		for (int i = 1; i < 64; i++) { // We start at i = 1 because Index 0 in AssaultCube is actually always 0. Didn't know till I reversed it. Cool lesson
			Entity* Ent = EntityList::GetEntity(i);
			if (!Ent)
				continue;

			if (Ent->iHealth < 0 || Ent->iHealth > 100) // Is a live player
				continue;

			std::cout << Ent->iHealth << std::endl;

			EntityListEntry Entry;
			Entry.Ent = Ent;
			Entry.ListIdx = i;

			TempEntityList.push_back(Entry);
		}

		Globals::EntityList = TempEntityList;

	}

	inline void Thread() {

		while (1) {

			Cache();

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		}

	}
}