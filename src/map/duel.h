/****************************************************************************!
*                _           _   _   _                                       *
*               | |__  _ __ / \ | |_| |__   ___ _ __   __ _                  *
*               | '_ \| '__/ _ \| __| '_ \ / _ \ '_ \ / _` |                 *
*               | |_) | | / ___ \ |_| | | |  __/ | | | (_| |                 *
*               |_.__/|_|/_/   \_\__|_| |_|\___|_| |_|\__,_|                 *
*                                                                            *
******************************************************************************
*                          www.brathena.org                                  *
*****************************************************************************/

#ifndef MAP_DUEL_H
#define MAP_DUEL_H

#include "../common/cbasetypes.h"

struct map_session_data;

struct duel {
	int members_count;
	int invites_count;
	int max_players_limit;
};

#define MAX_DUEL 1024

/**
 * duel.c Interface
 **/
struct duel_interface {

	/* vars */
	struct duel list[MAX_DUEL];
	int count;

	/* funcs */
	//Duel functions // [LuzZza]
	int (*create) (struct map_session_data* sd, const unsigned int maxpl);
	void (*invite) (const unsigned int did, struct map_session_data* sd, struct map_session_data* target_sd);
	void (*accept) (const unsigned int did, struct map_session_data* sd);
	void (*reject) (const unsigned int did, struct map_session_data* sd);
	void (*leave) (const unsigned int did, struct map_session_data* sd);
	void (*showinfo) (const unsigned int did, struct map_session_data* sd);
	int (*checktime) (struct map_session_data* sd);

	void (*init) (bool minimal);
	void (*final) (void);
};

struct duel_interface *duel;

#ifdef BRATHENA_CORE
void duel_defaults(void);
#endif // BRATHENA_CORE

#endif /* MAP_DUEL_H */
