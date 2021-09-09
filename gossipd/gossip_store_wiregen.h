/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_GOSSIPD_GOSSIP_STORE_WIREGEN_H
#define LIGHTNING_GOSSIPD_GOSSIP_STORE_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <common/amount.h>
#include <common/node_id.h>

enum gossip_store_wire {
        /*  This always follows the channel_announce / private_announce */
        WIRE_GOSSIP_STORE_CHANNEL_AMOUNT = 4101,
        /*  Mimics a channel_announce */
        WIRE_GOSSIP_STORE_PRIVATE_CHANNEL = 4104,
        WIRE_GOSSIP_STORE_PRIVATE_UPDATE = 4102,
        WIRE_GOSSIP_STORE_DELETE_CHAN = 4103,
        WIRE_GOSSIP_STORE_ENDED = 4105,
        /*  FIXME: Here for COMPAT with v0.9.0 and before only. */
        WIRE_GOSSIPD_LOCAL_ADD_CHANNEL_OBS = 3503,
};

const char *gossip_store_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool gossip_store_wire_is_defined(u16 type);


/* WIRE: GOSSIP_STORE_CHANNEL_AMOUNT */
/*  This always follows the channel_announce / private_announce */
u8 *towire_gossip_store_channel_amount(const tal_t *ctx, struct amount_sat satoshis);
bool fromwire_gossip_store_channel_amount(const void *p, struct amount_sat *satoshis);

/* WIRE: GOSSIP_STORE_PRIVATE_CHANNEL */
/*  Mimics a channel_announce */
u8 *towire_gossip_store_private_channel(const tal_t *ctx, struct amount_sat satoshis, const u8 *announcement);
bool fromwire_gossip_store_private_channel(const tal_t *ctx, const void *p, struct amount_sat *satoshis, u8 **announcement);

/* WIRE: GOSSIP_STORE_PRIVATE_UPDATE */
u8 *towire_gossip_store_private_update(const tal_t *ctx, const u8 *update);
bool fromwire_gossip_store_private_update(const tal_t *ctx, const void *p, u8 **update);

/* WIRE: GOSSIP_STORE_DELETE_CHAN */
u8 *towire_gossip_store_delete_chan(const tal_t *ctx, const struct short_channel_id *scid);
bool fromwire_gossip_store_delete_chan(const void *p, struct short_channel_id *scid);

/* WIRE: GOSSIP_STORE_ENDED */
u8 *towire_gossip_store_ended(const tal_t *ctx, u64 equivalent_offset);
bool fromwire_gossip_store_ended(const void *p, u64 *equivalent_offset);

/* WIRE: GOSSIPD_LOCAL_ADD_CHANNEL_OBS */
/*  FIXME: Here for COMPAT with v0.9.0 and before only. */
u8 *towire_gossipd_local_add_channel_obs(const tal_t *ctx, const struct short_channel_id *short_channel_id, const struct node_id *remote_node_id, struct amount_sat satoshis, const u8 *features);
bool fromwire_gossipd_local_add_channel_obs(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct node_id *remote_node_id, struct amount_sat *satoshis, u8 **features);


#endif /* LIGHTNING_GOSSIPD_GOSSIP_STORE_WIREGEN_H */
// SHA256STAMP:349d7e48ef1b41ce203a634053cbd5c9f290443e408bfa53aa7e67aaa28969d9
