#ifndef ZENO_INT_H
#define ZENO_INT_H

#include "zeno-config-int.h"

struct out_conduit;
struct out_mconduit;
struct in_conduit;

struct peerid {
    uint8_t id[PEERID_SIZE];
    zpsize_t len;
};

void xrce_panic(uint16_t line, uint16_t code);
uint16_t xmitw_pos_add(uint16_t p, uint16_t a);
uint16_t xmitw_bytesavail(const struct out_conduit *c);
void pack_reserve(zeno_address_t *dst, struct out_conduit *oc, zpsize_t cnt);
void pack1(uint8_t x);
void pack2(uint8_t x, uint8_t y);
void pack_u16(uint16_t x);
void pack_vec(zpsize_t n, const uint8_t *buf);
cid_t oc_get_cid(struct out_conduit *c);
int ocm_have_peers(const struct out_mconduit *mc);
zmsize_t oc_pack_payload_msgprep(seq_t *s, struct out_conduit *c, int relflag, zpsize_t sz);
void oc_pack_copyrel(struct out_conduit *c, zmsize_t from);
void oc_pack_payload(struct out_conduit *c, int relflag, zpsize_t sz, const void *vdata);
void oc_pack_payload_done(struct out_conduit *c, int relflag);
void rsub_register(rid_t rid, uint8_t submode);
uint8_t rsub_precommit(rid_t *err_rid);
void rsub_commit(void);
int rsub_exists(uint8_t pubidx);
void rsub_precommit_curpkt_abort(void);
void rsub_precommit_curpkt_done(void);
void rsub_clear(void);
int seq_lt(seq_t a, seq_t b);
int seq_le(seq_t a, seq_t b);
int ic_may_deliver_seq(struct in_conduit *ic, uint8_t hdr, seq_t seq);
void ic_update_seq (struct in_conduit *ic, uint8_t hdr, seq_t seq);
void reset_pubs_to_declare(void);
void reset_subs_to_declare(void);
pubidx_t publish(rid_t rid, int reliable);
subidx_t subscribe(rid_t rid, zpsize_t xmitneed, subhandler_t handler, void *arg);
void flush_output(ztime_t tnow);
void send_msynch(ztime_t tnow);
void send_declares(ztime_t tnow);

#endif