/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef UV_DARWIN_H
#define UV_DARWIN_H

#if defined(__APPLE__) && defined(__MACH__)
# include <mach/mach.h>
# include <mach/task.h>
# include <mach/semaphore.h>
# include <TargetConditionals.h>
# define UV_PLATFORM_SEM_T semaphore_t
#endif

#define UV_PLATFORM_LOOP_FIELDS                                               \
  uv_thread_t cf_thread;                                                      \
  void* cf_cb;                                                                \
  void* cf_loop;                                                              \
  uv_mutex_t cf_mutex;                                                        \
  uv_sem_t cf_sem;                                                            \
  ngx_queue_t cf_signals;                                                     \

#define UV_PLATFORM_FS_EVENT_FIELDS                                           \
  ev_io event_watcher;                                                        \
  int fflags;                                                                 \
  int fd;                                                                     \
  char* realpath;                                                             \
  int realpath_len;                                                           \
  int cf_flags;                                                               \
  void* cf_eventstream;                                                       \
  uv_async_t* cf_cb;                                                          \
  ngx_queue_t cf_events;                                                      \
  uv_sem_t cf_sem;                                                            \
  uv_mutex_t cf_mutex;                                                        \

#define UV_STREAM_PRIVATE_PLATFORM_FIELDS                                     \
  void* select;                                                               \

#endif /* UV_DARWIN_H */
