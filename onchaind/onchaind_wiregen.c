/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <onchaind/onchaind_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *onchaind_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum onchaind_wire)e) {
	case WIRE_ONCHAIND_INIT: return "WIRE_ONCHAIND_INIT";
	case WIRE_ONCHAIND_HTLC: return "WIRE_ONCHAIND_HTLC";
	case WIRE_ONCHAIND_INIT_REPLY: return "WIRE_ONCHAIND_INIT_REPLY";
	case WIRE_ONCHAIND_BROADCAST_TX: return "WIRE_ONCHAIND_BROADCAST_TX";
	case WIRE_ONCHAIND_SPENT: return "WIRE_ONCHAIND_SPENT";
	case WIRE_ONCHAIND_DEPTH: return "WIRE_ONCHAIND_DEPTH";
	case WIRE_ONCHAIND_UNWATCH_TX: return "WIRE_ONCHAIND_UNWATCH_TX";
	case WIRE_ONCHAIND_KNOWN_PREIMAGE: return "WIRE_ONCHAIND_KNOWN_PREIMAGE";
	case WIRE_ONCHAIND_EXTRACTED_PREIMAGE: return "WIRE_ONCHAIND_EXTRACTED_PREIMAGE";
	case WIRE_ONCHAIND_MISSING_HTLC_OUTPUT: return "WIRE_ONCHAIND_MISSING_HTLC_OUTPUT";
	case WIRE_ONCHAIND_HTLC_TIMEOUT: return "WIRE_ONCHAIND_HTLC_TIMEOUT";
	case WIRE_ONCHAIND_ALL_IRREVOCABLY_RESOLVED: return "WIRE_ONCHAIND_ALL_IRREVOCABLY_RESOLVED";
	case WIRE_ONCHAIND_ADD_UTXO: return "WIRE_ONCHAIND_ADD_UTXO";
	case WIRE_ONCHAIND_DEV_MEMLEAK: return "WIRE_ONCHAIND_DEV_MEMLEAK";
	case WIRE_ONCHAIND_DEV_MEMLEAK_REPLY: return "WIRE_ONCHAIND_DEV_MEMLEAK_REPLY";
	case WIRE_ONCHAIND_ANNOTATE_TXOUT: return "WIRE_ONCHAIND_ANNOTATE_TXOUT";
	case WIRE_ONCHAIND_ANNOTATE_TXIN: return "WIRE_ONCHAIND_ANNOTATE_TXIN";
	case WIRE_ONCHAIND_NOTIFY_COIN_MVT: return "WIRE_ONCHAIND_NOTIFY_COIN_MVT";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool onchaind_wire_is_defined(u16 type)
{
	switch ((enum onchaind_wire)type) {
	case WIRE_ONCHAIND_INIT:;
	case WIRE_ONCHAIND_HTLC:;
	case WIRE_ONCHAIND_INIT_REPLY:;
	case WIRE_ONCHAIND_BROADCAST_TX:;
	case WIRE_ONCHAIND_SPENT:;
	case WIRE_ONCHAIND_DEPTH:;
	case WIRE_ONCHAIND_UNWATCH_TX:;
	case WIRE_ONCHAIND_KNOWN_PREIMAGE:;
	case WIRE_ONCHAIND_EXTRACTED_PREIMAGE:;
	case WIRE_ONCHAIND_MISSING_HTLC_OUTPUT:;
	case WIRE_ONCHAIND_HTLC_TIMEOUT:;
	case WIRE_ONCHAIND_ALL_IRREVOCABLY_RESOLVED:;
	case WIRE_ONCHAIND_ADD_UTXO:;
	case WIRE_ONCHAIND_DEV_MEMLEAK:;
	case WIRE_ONCHAIND_DEV_MEMLEAK_REPLY:;
	case WIRE_ONCHAIND_ANNOTATE_TXOUT:;
	case WIRE_ONCHAIND_ANNOTATE_TXIN:;
	case WIRE_ONCHAIND_NOTIFY_COIN_MVT:;
	      return true;
	}
	return false;
}





/* WIRE: ONCHAIND_INIT */
/* Begin!  Here's the onchain tx which spends funding tx */
u8 *towire_onchaind_init(const tal_t *ctx, const struct shachain *shachain, const struct chainparams *chainparams, struct amount_sat funding_amount_satoshi, struct amount_msat our_msat, const struct pubkey *old_remote_per_commitment_point, const struct pubkey *remote_per_commitment_point, u32 local_to_self_delay, u32 remote_to_self_delay, u32 delayed_to_us_feerate, u32 htlc_feerate, u32 penalty_feerate, struct amount_sat local_dust_limit_satoshi, const struct bitcoin_txid *our_broadcast_txid, const u8 *local_scriptpubkey, const u8 *remote_scriptpubkey, const struct pubkey *ourwallet_pubkey, enum side opener, const struct basepoints *local_basepoints, const struct basepoints *remote_basepoints, const struct tx_parts *tx_parts, u32 locktime, u32 tx_blockheight, u32 reasonable_depth, const struct bitcoin_signature *htlc_signature, u64 num_htlcs, u32 min_possible_feerate, u32 max_possible_feerate, const struct pubkey *possible_remote_per_commit_point, const struct pubkey *local_funding_pubkey, const struct pubkey *remote_funding_pubkey, u64 local_static_remotekey_start, u64 remote_static_remotekey_start, bool option_anchor_outputs, bool is_replay, u32 min_relay_feerate)
{
	u16 local_scriptpubkey_len = tal_count(local_scriptpubkey);
	u16 remote_scriptpubkey_len = tal_count(remote_scriptpubkey);
	u16 num_htlc_sigs = tal_count(htlc_signature);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_INIT);
	towire_shachain(&p, shachain);
	/* This needs to be set explicitly since the same message also contains a */
	/* transaction that we need to parse correctly. */
	towire_chainparams(&p, chainparams);
	towire_amount_sat(&p, funding_amount_satoshi);
	/* Our current balance (of funding amount */
	towire_amount_msat(&p, our_msat);
	/* Remote per commit point for committed tx. */
	towire_pubkey(&p, old_remote_per_commitment_point);
	/* Remote per commit point for current tx (needed if we haven't got revoke_and_ack yet). */
	towire_pubkey(&p, remote_per_commitment_point);
	towire_u32(&p, local_to_self_delay);
	towire_u32(&p, remote_to_self_delay);
	towire_u32(&p, delayed_to_us_feerate);
	towire_u32(&p, htlc_feerate);
	towire_u32(&p, penalty_feerate);
	towire_amount_sat(&p, local_dust_limit_satoshi);
	/* Gives an easy way to tell if it's our unilateral close or theirs... */
	towire_bitcoin_txid(&p, our_broadcast_txid);
	towire_u16(&p, local_scriptpubkey_len);
	towire_u8_array(&p, local_scriptpubkey, local_scriptpubkey_len);
	towire_u16(&p, remote_scriptpubkey_len);
	towire_u8_array(&p, remote_scriptpubkey, remote_scriptpubkey_len);
	towire_pubkey(&p, ourwallet_pubkey);
	/* We need these two for commit number obscurer */
	towire_side(&p, opener);
	towire_basepoints(&p, local_basepoints);
	towire_basepoints(&p, remote_basepoints);
	towire_tx_parts(&p, tx_parts);
	towire_u32(&p, locktime);
	towire_u32(&p, tx_blockheight);
	towire_u32(&p, reasonable_depth);
	towire_u16(&p, num_htlc_sigs);
	for (size_t i = 0; i < num_htlc_sigs; i++)
		towire_bitcoin_signature(&p, htlc_signature + i);
	towire_u64(&p, num_htlcs);
	towire_u32(&p, min_possible_feerate);
	towire_u32(&p, max_possible_feerate);
	if (!possible_remote_per_commit_point)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, possible_remote_per_commit_point);
	}
	towire_pubkey(&p, local_funding_pubkey);
	towire_pubkey(&p, remote_funding_pubkey);
	towire_u64(&p, local_static_remotekey_start);
	towire_u64(&p, remote_static_remotekey_start);
	towire_bool(&p, option_anchor_outputs);
	towire_bool(&p, is_replay);
	/* We need this for BIP125 rule 4 */
	towire_u32(&p, min_relay_feerate);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_init(const tal_t *ctx, const void *p, struct shachain *shachain, const struct chainparams **chainparams, struct amount_sat *funding_amount_satoshi, struct amount_msat *our_msat, struct pubkey *old_remote_per_commitment_point, struct pubkey *remote_per_commitment_point, u32 *local_to_self_delay, u32 *remote_to_self_delay, u32 *delayed_to_us_feerate, u32 *htlc_feerate, u32 *penalty_feerate, struct amount_sat *local_dust_limit_satoshi, struct bitcoin_txid *our_broadcast_txid, u8 **local_scriptpubkey, u8 **remote_scriptpubkey, struct pubkey *ourwallet_pubkey, enum side *opener, struct basepoints *local_basepoints, struct basepoints *remote_basepoints, struct tx_parts **tx_parts, u32 *locktime, u32 *tx_blockheight, u32 *reasonable_depth, struct bitcoin_signature **htlc_signature, u64 *num_htlcs, u32 *min_possible_feerate, u32 *max_possible_feerate, struct pubkey **possible_remote_per_commit_point, struct pubkey *local_funding_pubkey, struct pubkey *remote_funding_pubkey, u64 *local_static_remotekey_start, u64 *remote_static_remotekey_start, bool *option_anchor_outputs, bool *is_replay, u32 *min_relay_feerate)
{
	u16 local_scriptpubkey_len;
	u16 remote_scriptpubkey_len;
	u16 num_htlc_sigs;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_INIT)
		return false;
 	fromwire_shachain(&cursor, &plen, shachain);
 	/* This needs to be set explicitly since the same message also contains a */
	/* transaction that we need to parse correctly. */
	fromwire_chainparams(&cursor, &plen, chainparams);
 	*funding_amount_satoshi = fromwire_amount_sat(&cursor, &plen);
 	/* Our current balance (of funding amount */
	*our_msat = fromwire_amount_msat(&cursor, &plen);
 	/* Remote per commit point for committed tx. */
	fromwire_pubkey(&cursor, &plen, old_remote_per_commitment_point);
 	/* Remote per commit point for current tx (needed if we haven't got revoke_and_ack yet). */
	fromwire_pubkey(&cursor, &plen, remote_per_commitment_point);
 	*local_to_self_delay = fromwire_u32(&cursor, &plen);
 	*remote_to_self_delay = fromwire_u32(&cursor, &plen);
 	*delayed_to_us_feerate = fromwire_u32(&cursor, &plen);
 	*htlc_feerate = fromwire_u32(&cursor, &plen);
 	*penalty_feerate = fromwire_u32(&cursor, &plen);
 	*local_dust_limit_satoshi = fromwire_amount_sat(&cursor, &plen);
 	/* Gives an easy way to tell if it's our unilateral close or theirs... */
	fromwire_bitcoin_txid(&cursor, &plen, our_broadcast_txid);
 	local_scriptpubkey_len = fromwire_u16(&cursor, &plen);
 	// 2nd case local_scriptpubkey
	*local_scriptpubkey = local_scriptpubkey_len ? tal_arr(ctx, u8, local_scriptpubkey_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *local_scriptpubkey, local_scriptpubkey_len);
 	remote_scriptpubkey_len = fromwire_u16(&cursor, &plen);
 	// 2nd case remote_scriptpubkey
	*remote_scriptpubkey = remote_scriptpubkey_len ? tal_arr(ctx, u8, remote_scriptpubkey_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *remote_scriptpubkey, remote_scriptpubkey_len);
 	fromwire_pubkey(&cursor, &plen, ourwallet_pubkey);
 	/* We need these two for commit number obscurer */
	*opener = fromwire_side(&cursor, &plen);
 	fromwire_basepoints(&cursor, &plen, local_basepoints);
 	fromwire_basepoints(&cursor, &plen, remote_basepoints);
 	*tx_parts = fromwire_tx_parts(ctx, &cursor, &plen);
 	*locktime = fromwire_u32(&cursor, &plen);
 	*tx_blockheight = fromwire_u32(&cursor, &plen);
 	*reasonable_depth = fromwire_u32(&cursor, &plen);
 	num_htlc_sigs = fromwire_u16(&cursor, &plen);
 	// 2nd case htlc_signature
	*htlc_signature = num_htlc_sigs ? tal_arr(ctx, struct bitcoin_signature, num_htlc_sigs) : NULL;
	for (size_t i = 0; i < num_htlc_sigs; i++)
		fromwire_bitcoin_signature(&cursor, &plen, *htlc_signature + i);
 	*num_htlcs = fromwire_u64(&cursor, &plen);
 	*min_possible_feerate = fromwire_u32(&cursor, &plen);
 	*max_possible_feerate = fromwire_u32(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*possible_remote_per_commit_point = NULL;
	else {
		*possible_remote_per_commit_point = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *possible_remote_per_commit_point);
	}
 	fromwire_pubkey(&cursor, &plen, local_funding_pubkey);
 	fromwire_pubkey(&cursor, &plen, remote_funding_pubkey);
 	*local_static_remotekey_start = fromwire_u64(&cursor, &plen);
 	*remote_static_remotekey_start = fromwire_u64(&cursor, &plen);
 	*option_anchor_outputs = fromwire_bool(&cursor, &plen);
 	*is_replay = fromwire_bool(&cursor, &plen);
 	/* We need this for BIP125 rule 4 */
	*min_relay_feerate = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_HTLC */
/* This is all the HTLCs: one per message */
u8 *towire_onchaind_htlc(const tal_t *ctx, const struct htlc_stub *htlc, bool tell_if_missing, bool tell_immediately)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_HTLC);
	towire_htlc_stub(&p, htlc);
	/* If it's not in the commitment tx */
	towire_bool(&p, tell_if_missing);
	towire_bool(&p, tell_immediately);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_htlc(const void *p, struct htlc_stub *htlc, bool *tell_if_missing, bool *tell_immediately)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_HTLC)
		return false;
 	fromwire_htlc_stub(&cursor, &plen, htlc);
 	/* If it's not in the commitment tx */
	*tell_if_missing = fromwire_bool(&cursor, &plen);
 	*tell_immediately = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_INIT_REPLY */
/* This says we're ready; give us preimages. */
u8 *towire_onchaind_init_reply(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_INIT_REPLY);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_init_reply(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_INIT_REPLY)
		return false;
	return cursor != NULL;
}

/* WIRE: ONCHAIND_BROADCAST_TX */
/* onchaind->master: Send out a tx. */
/* If is_rbf is false then master should rebroadcast the tx. */
/* If is_rbf is true then onchaind is responsible for rebroadcasting */
/*  it with a higher fee. */
u8 *towire_onchaind_broadcast_tx(const tal_t *ctx, const struct bitcoin_tx *tx, enum wallet_tx_type type, bool is_rbf)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_BROADCAST_TX);
	towire_bitcoin_tx(&p, tx);
	towire_wallet_tx_type(&p, type);
	towire_bool(&p, is_rbf);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_broadcast_tx(const tal_t *ctx, const void *p, struct bitcoin_tx **tx, enum wallet_tx_type *type, bool *is_rbf)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_BROADCAST_TX)
		return false;
 	*tx = fromwire_bitcoin_tx(ctx, &cursor, &plen);
 	*type = fromwire_wallet_tx_type(&cursor, &plen);
 	*is_rbf = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_SPENT */
/* master->onchaind: Notifier that an output has been spent by input_num of tx. */
u8 *towire_onchaind_spent(const tal_t *ctx, const struct tx_parts *tx, u32 input_num, u32 blockheight, bool is_replay)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_SPENT);
	towire_tx_parts(&p, tx);
	towire_u32(&p, input_num);
	towire_u32(&p, blockheight);
	towire_bool(&p, is_replay);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_spent(const tal_t *ctx, const void *p, struct tx_parts **tx, u32 *input_num, u32 *blockheight, bool *is_replay)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_SPENT)
		return false;
 	*tx = fromwire_tx_parts(ctx, &cursor, &plen);
 	*input_num = fromwire_u32(&cursor, &plen);
 	*blockheight = fromwire_u32(&cursor, &plen);
 	*is_replay = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_DEPTH */
/* master->onchaind: We will receive more than one of these */
u8 *towire_onchaind_depth(const tal_t *ctx, const struct bitcoin_txid *txid, u32 depth, bool is_replay)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_DEPTH);
	towire_bitcoin_txid(&p, txid);
	towire_u32(&p, depth);
	towire_bool(&p, is_replay);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_depth(const void *p, struct bitcoin_txid *txid, u32 *depth, bool *is_replay)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_DEPTH)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, txid);
 	*depth = fromwire_u32(&cursor, &plen);
 	*is_replay = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_UNWATCH_TX */
/* onchaind->master: We don't want to watch this tx */
u8 *towire_onchaind_unwatch_tx(const tal_t *ctx, const struct bitcoin_txid *txid)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_UNWATCH_TX);
	towire_bitcoin_txid(&p, txid);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_unwatch_tx(const void *p, struct bitcoin_txid *txid)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_UNWATCH_TX)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, txid);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_KNOWN_PREIMAGE */
/* master->onchaind: We know HTLC preimage */
u8 *towire_onchaind_known_preimage(const tal_t *ctx, const struct preimage *preimage, bool is_replay)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_KNOWN_PREIMAGE);
	towire_preimage(&p, preimage);
	towire_bool(&p, is_replay);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_known_preimage(const void *p, struct preimage *preimage, bool *is_replay)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_KNOWN_PREIMAGE)
		return false;
 	fromwire_preimage(&cursor, &plen, preimage);
 	*is_replay = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_EXTRACTED_PREIMAGE */
/* onchaind->master: We discovered HTLC preimage */
u8 *towire_onchaind_extracted_preimage(const tal_t *ctx, const struct preimage *preimage)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_EXTRACTED_PREIMAGE);
	towire_preimage(&p, preimage);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_extracted_preimage(const void *p, struct preimage *preimage)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_EXTRACTED_PREIMAGE)
		return false;
 	fromwire_preimage(&cursor, &plen, preimage);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_MISSING_HTLC_OUTPUT */
/* onchaind->master: this HTLC was missing from commit tx. */
u8 *towire_onchaind_missing_htlc_output(const tal_t *ctx, const struct htlc_stub *htlc)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_MISSING_HTLC_OUTPUT);
	towire_htlc_stub(&p, htlc);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_missing_htlc_output(const void *p, struct htlc_stub *htlc)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_MISSING_HTLC_OUTPUT)
		return false;
 	fromwire_htlc_stub(&cursor, &plen, htlc);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_HTLC_TIMEOUT */
/* onchaind->master: this HTLC has timed out (after reasonable_depth) */
u8 *towire_onchaind_htlc_timeout(const tal_t *ctx, const struct htlc_stub *htlc)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_HTLC_TIMEOUT);
	towire_htlc_stub(&p, htlc);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_htlc_timeout(const void *p, struct htlc_stub *htlc)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_HTLC_TIMEOUT)
		return false;
 	fromwire_htlc_stub(&cursor, &plen, htlc);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_ALL_IRREVOCABLY_RESOLVED */
/* onchaind->master: this peer can be forgotten */
u8 *towire_onchaind_all_irrevocably_resolved(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_ALL_IRREVOCABLY_RESOLVED);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_all_irrevocably_resolved(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_ALL_IRREVOCABLY_RESOLVED)
		return false;
	return cursor != NULL;
}

/* WIRE: ONCHAIND_ADD_UTXO */
/* onchaind->master: hey */
u8 *towire_onchaind_add_utxo(const tal_t *ctx, const struct bitcoin_txid *prev_out_tx, u32 prev_out_index, const struct pubkey *per_commit_point, struct amount_sat value, u32 blockheight, const u8 *scriptpubkey, u32 csv_lock)
{
	u16 len = tal_count(scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_ADD_UTXO);
	towire_bitcoin_txid(&p, prev_out_tx);
	towire_u32(&p, prev_out_index);
	if (!per_commit_point)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_pubkey(&p, per_commit_point);
	}
	towire_amount_sat(&p, value);
	towire_u32(&p, blockheight);
	towire_u16(&p, len);
	towire_u8_array(&p, scriptpubkey, len);
	towire_u32(&p, csv_lock);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_add_utxo(const tal_t *ctx, const void *p, struct bitcoin_txid *prev_out_tx, u32 *prev_out_index, struct pubkey **per_commit_point, struct amount_sat *value, u32 *blockheight, u8 **scriptpubkey, u32 *csv_lock)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_ADD_UTXO)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, prev_out_tx);
 	*prev_out_index = fromwire_u32(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*per_commit_point = NULL;
	else {
		*per_commit_point = tal(ctx, struct pubkey);
		fromwire_pubkey(&cursor, &plen, *per_commit_point);
	}
 	*value = fromwire_amount_sat(&cursor, &plen);
 	*blockheight = fromwire_u32(&cursor, &plen);
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case scriptpubkey
	*scriptpubkey = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *scriptpubkey, len);
 	*csv_lock = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_DEV_MEMLEAK */
/* master -> onchaind: do you have a memleak? */
u8 *towire_onchaind_dev_memleak(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_DEV_MEMLEAK);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_dev_memleak(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_DEV_MEMLEAK)
		return false;
	return cursor != NULL;
}

/* WIRE: ONCHAIND_DEV_MEMLEAK_REPLY */
u8 *towire_onchaind_dev_memleak_reply(const tal_t *ctx, bool leak)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_DEV_MEMLEAK_REPLY);
	towire_bool(&p, leak);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_dev_memleak_reply(const void *p, bool *leak)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_DEV_MEMLEAK_REPLY)
		return false;
 	*leak = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_ANNOTATE_TXOUT */
/* Tell the main daemon what we've been watching */
/* that we tracked automatically but only onchaind knows how to classify their */
/* transactions. */
u8 *towire_onchaind_annotate_txout(const tal_t *ctx, const struct bitcoin_txid *txid, u32 outnum, enum wallet_tx_type type)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_ANNOTATE_TXOUT);
	towire_bitcoin_txid(&p, txid);
	towire_u32(&p, outnum);
	towire_wallet_tx_type(&p, type);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_annotate_txout(const void *p, struct bitcoin_txid *txid, u32 *outnum, enum wallet_tx_type *type)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_ANNOTATE_TXOUT)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, txid);
 	*outnum = fromwire_u32(&cursor, &plen);
 	*type = fromwire_wallet_tx_type(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_ANNOTATE_TXIN */
u8 *towire_onchaind_annotate_txin(const tal_t *ctx, const struct bitcoin_txid *txid, u32 innum, enum wallet_tx_type type)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_ANNOTATE_TXIN);
	towire_bitcoin_txid(&p, txid);
	towire_u32(&p, innum);
	towire_wallet_tx_type(&p, type);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_annotate_txin(const void *p, struct bitcoin_txid *txid, u32 *innum, enum wallet_tx_type *type)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_ANNOTATE_TXIN)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, txid);
 	*innum = fromwire_u32(&cursor, &plen);
 	*type = fromwire_wallet_tx_type(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: ONCHAIND_NOTIFY_COIN_MVT */
u8 *towire_onchaind_notify_coin_mvt(const tal_t *ctx, const struct chain_coin_mvt *mvt)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_ONCHAIND_NOTIFY_COIN_MVT);
	towire_chain_coin_mvt(&p, mvt);

	return memcheck(p, tal_count(p));
}
bool fromwire_onchaind_notify_coin_mvt(const void *p, struct chain_coin_mvt *mvt)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_ONCHAIND_NOTIFY_COIN_MVT)
		return false;
 	fromwire_chain_coin_mvt(&cursor, &plen, mvt);
	return cursor != NULL;
}
// SHA256STAMP:f591fbdc03a41071e5db7a11ee0420f52a1edf1fdd282d32aca0dadca9ef58e9
