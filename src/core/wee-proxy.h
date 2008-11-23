/*
 * Copyright (c) 2003-2008 by FlashCode <flashcode@flashtux.org>
 * See README for License detail, AUTHORS for developers list.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __WEECHAT_PROXY_H
#define __WEECHAT_PROXY_H 1

enum t_proxy_option
{
    PROXY_OPTION_TYPE = 0,
    PROXY_OPTION_IPV6,
    PROXY_OPTION_ADDRESS,
    PROXY_OPTION_PORT,
    PROXY_OPTION_USERNAME,
    PROXY_OPTION_PASSWORD,
    /* number of proxy options */
    PROXY_NUM_OPTIONS,
};

enum t_proxy_type
{
    PROXY_TYPE_HTTP = 0,
    PROXY_TYPE_SOCKS4,
    PROXY_TYPE_SOCKS5,
    /* number of proxy types */
    PROXY_NUM_TYPES,
};

struct t_proxy
{
    char *name;                         /* proxy name                       */
    struct t_config_option *type;       /* type: http, socks4, socks5       */
    struct t_config_option *ipv6;       /* ipv6 ? or ipv4 ?                 */
    struct t_config_option *address;    /* address (IP or hostname)         */
    struct t_config_option *port;       /* port                             */
    struct t_config_option *username;   /* username (optional)              */
    struct t_config_option *password;   /* password (optional)              */
    
    struct t_proxy *prev_proxy;         /* link to previous bar             */
    struct t_proxy *next_proxy;         /* link to next bar                 */
};

/* variables */

extern char *proxy_type_string[];
extern struct t_proxy *weechat_proxies;
extern struct t_proxy *last_weechat_proxy;
extern struct t_proxy *weechat_temp_proxies;
extern struct t_proxy *last_weechat_temp_proxy;

/* functions */

extern int proxy_search_option (const char *option_name);
extern int proxy_search_type (const char *type);
extern struct t_proxy *proxy_search (const char *name);
extern int proxy_set (struct t_proxy *bar, const char *property,
                      const char *value);
extern void proxy_create_option_temp (struct t_proxy *temp_proxy,
                                      int index_option, const char *value);
extern struct t_proxy *proxy_alloc (const char *name);
extern struct t_proxy *proxy_new (const char *name,
                                  const char *type,
                                  const char *ipv6,
                                  const char *address,
                                  const char *port,
                                  const char *username,
                                  const char *password);
extern void proxy_use_temp_proxies ();
extern void proxy_free (struct t_proxy *proxy);
extern void proxy_free_all ();
extern void proxy_print_log ();

#endif /* wee-proxy.h */
