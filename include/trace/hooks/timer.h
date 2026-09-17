/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM timer

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_TIMER_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_TIMER_H

#include <trace/hooks/vendor_hooks.h>

struct task_struct;

#define ANDROID_TIMER_SLACK_NANOSLEEP		0
#define ANDROID_TIMER_SLACK_SCHED_HRTIMEOUT	1
#define ANDROID_TIMER_SLACK_FUTEX		2
#define ANDROID_TIMER_SLACK_TYPE_MAX		3

DECLARE_HOOK(android_vh_timer_calc_index,
	TP_PROTO(unsigned int lvl, unsigned long *expires),
	TP_ARGS(lvl, expires));

DECLARE_HOOK(android_vh_adjust_timer_slack,
	TP_PROTO(struct task_struct *task, ktime_t *expires,
		 u64 *delta_ns, int type),
	TP_ARGS(task, expires, delta_ns, type));

#endif /* _TRACE_HOOK_TIMER_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
