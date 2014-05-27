//
//  DDLog+LOGV.h
//  Lumberjack
//
//  Created by Mike Pontillo on 11/20/12.
//
//

#ifndef Lumberjack_DDLog_LOGV_h
#define Lumberjack_DDLog_LOGV_h

#import "DDLog.h"


#define LOGV_MACRO(isAsynchronous, lvl, flg, ctx, atag, frmt, avalist) \
  [DDLog log:isAsynchronous                                                  \
       level:lvl                                                             \
        flag:flg                                                             \
     context:ctx                                                             \
        file:__FILE__                                                        \
     function:__PRETTY_FUNCTION__                                            \
        line:__LINE__                                                        \
         tag:atag                                                            \
      format:frmt                                                            \
        args:avalist]

#define LOGV_MAYBE(async, lvl, flg, ctx, frmt, avalist) \
  do { if(lvl & flg) LOGV_MACRO(async, lvl, flg, ctx, nil, frmt, avalist); } while(0)

#define  SYNC_LOGV_MAYBE(lvl, flg, ctx, frmt, avalist) \
              LOGV_MAYBE( NO, lvl, flg, ctx, frmt, avalist)

#define ASYNC_LOGV_MAYBE(lvl, flg, ctx, frmt, avalist) \
              LOGV_MAYBE(YES, lvl, flg, ctx, frmt, avalist)


#define LOGV_TAG_MAYBE(async, lvl, flg, ctx, tag, frmt, avalist) \
  do { if(lvl & flg) LOGV_MACRO(async, lvl, flg, ctx, tag, frmt, avalist); } while(0)


#define DDLogvError(frmt, avalist)   LOGV_MAYBE(LOG_ASYNC_ERROR,   ddLogLevel, LOG_FLAG_ERROR,   0, frmt, avalist)
#define DDLogvWarn(frmt, avalist)    LOGV_MAYBE(LOG_ASYNC_WARN,    ddLogLevel, LOG_FLAG_WARN,    0, frmt, avalist)
#define DDLogvInfo(frmt, avalist)    LOGV_MAYBE(LOG_ASYNC_INFO,    ddLogLevel, LOG_FLAG_INFO,    0, frmt, avalist)
#define DDLogvVerbose(frmt, avalist) LOGV_MAYBE(LOG_ASYNC_VERBOSE, ddLogLevel, LOG_FLAG_VERBOSE, 0, frmt, avalist)

#endif
