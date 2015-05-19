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

#ifndef CHAR_LOGINIF_H
#define CHAR_LOGINIF_H

#include "char.h"

/**
 * loginif interface
 **/
struct loginif_interface {
	void (*init) (void);
	void (*final) (void);
	void (*reset) (void);
	void (*check_shutdown) (void);
	void (*on_disconnect) (void);
	void (*on_ready) (void);
	void (*block_account) (int account_id, int flag);
	void (*ban_account) (int account_id, short year, short month, short day, short hour, short minute, short second);
	void (*unban_account) (int account_id);
	void (*changesex) (int account_id);
	void (*auth) (int fd, struct char_session_data* sd, uint32 ipl);
	void (*send_users_count) (int users);
	void (*connect_to_server) (void);
};

struct loginif_interface *loginif;

#ifdef BRATHENA_CORE
void loginif_defaults(void);
#endif // BRATHENA_CORE

#endif /* CHAR_LOGINIF_H */
