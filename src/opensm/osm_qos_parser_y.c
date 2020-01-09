
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "osm_qos_parser_y.y"

/*
 * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.
 * Copyright (c) 2002-2008 Mellanox Technologies LTD. All rights reserved.
 * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.
 * Copyright (c) 2008 HNR Consulting. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

/*
 * Abstract:
 *    Grammar of OSM QoS parser.
 *
 * Environment:
 *    Linux User Mode
 *
 * Author:
 *    Yevgeny Kliteynik, Mellanox
 */

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <opensm/osm_opensm.h>
#include <opensm/osm_qos_policy.h>

#define OSM_QOS_POLICY_MAX_LINE_LEN         1024*10
#define OSM_QOS_POLICY_SL2VL_TABLE_LEN      IB_MAX_NUM_VLS
#define OSM_QOS_POLICY_MAX_VL_NUM           IB_MAX_NUM_VLS

typedef struct tmp_parser_struct_t_ {
    char       str[OSM_QOS_POLICY_MAX_LINE_LEN];
    uint64_t   num_pair[2];
    cl_list_t  str_list;
    cl_list_t  num_list;
    cl_list_t  num_pair_list;
} tmp_parser_struct_t;

static void __parser_tmp_struct_init();
static void __parser_tmp_struct_reset();
static void __parser_tmp_struct_destroy();

static char * __parser_strip_white(char * str);

static void __parser_str2uint64(uint64_t * p_val, char * str);

static void __parser_port_group_start();
static int __parser_port_group_end();

static void __parser_sl2vl_scope_start();
static int __parser_sl2vl_scope_end();

static void __parser_vlarb_scope_start();
static int __parser_vlarb_scope_end();

static void __parser_qos_level_start();
static int __parser_qos_level_end();

static void __parser_match_rule_start();
static int __parser_match_rule_end();

static void __parser_ulp_match_rule_start();
static int __parser_ulp_match_rule_end();

static void __pkey_rangelist2rangearr(
    cl_list_t    * p_list,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len);

static void __rangelist2rangearr(
    cl_list_t    * p_list,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len);

static void __merge_rangearr(
    uint64_t  **   range_arr_1,
    unsigned       range_len_1,
    uint64_t  **   range_arr_2,
    unsigned       range_len_2,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len );

static void __parser_add_port_to_port_map(
    cl_qmap_t   * p_map,
    osm_physp_t * p_physp);

static void __parser_add_guid_range_to_port_map(
    cl_qmap_t  * p_map,
    uint64_t  ** range_arr,
    unsigned     range_len);

static void __parser_add_pkey_range_to_port_map(
    cl_qmap_t  * p_map,
    uint64_t  ** range_arr,
    unsigned     range_len);

static void __parser_add_partition_list_to_port_map(
    cl_qmap_t  * p_map,
    cl_list_t  * p_list);

static void __parser_add_map_to_port_map(
    cl_qmap_t * p_dmap,
    cl_map_t  * p_smap);

static int __validate_pkeys(
    uint64_t ** range_arr,
    unsigned    range_len,
    boolean_t   is_ipoib);

static void __setup_simple_qos_levels();
static void __clear_simple_qos_levels();
static void __setup_ulp_match_rules();
static void __process_ulp_match_rules();
static void yyerror(const char *format, ...);

extern char * yytext;
extern int yylex (void);
extern FILE * yyin;
extern int errno;
int yyparse();

#define RESET_BUFFER  __parser_tmp_struct_reset()

tmp_parser_struct_t tmp_parser_struct;

int column_num;
int line_num;

osm_qos_policy_t       * p_qos_policy = NULL;
osm_qos_port_group_t   * p_current_port_group = NULL;
osm_qos_sl2vl_scope_t  * p_current_sl2vl_scope = NULL;
osm_qos_vlarb_scope_t  * p_current_vlarb_scope = NULL;
osm_qos_level_t        * p_current_qos_level = NULL;
osm_qos_match_rule_t   * p_current_qos_match_rule = NULL;
osm_log_t              * p_qos_parser_osm_log;

/* 16 Simple QoS Levels - one for each SL */
static osm_qos_level_t osm_qos_policy_simple_qos_levels[16];

/* Default Simple QoS Level */
osm_qos_level_t __default_simple_qos_level;

/*
 * List of match rules that will be generated by the
 * qos-ulp section. These rules are concatenated to
 * the end of the usual matching rules list at the
 * end of parsing.
 */
static cl_list_t __ulp_match_rules;

/***************************************************/



/* Line 189 of yacc.c  */
#line 260 "osm_qos_parser_y.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_NUMBER = 258,
     TK_DASH = 259,
     TK_DOTDOT = 260,
     TK_COMMA = 261,
     TK_ASTERISK = 262,
     TK_TEXT = 263,
     TK_QOS_ULPS_START = 264,
     TK_QOS_ULPS_END = 265,
     TK_PORT_GROUPS_START = 266,
     TK_PORT_GROUPS_END = 267,
     TK_PORT_GROUP_START = 268,
     TK_PORT_GROUP_END = 269,
     TK_QOS_SETUP_START = 270,
     TK_QOS_SETUP_END = 271,
     TK_VLARB_TABLES_START = 272,
     TK_VLARB_TABLES_END = 273,
     TK_VLARB_SCOPE_START = 274,
     TK_VLARB_SCOPE_END = 275,
     TK_SL2VL_TABLES_START = 276,
     TK_SL2VL_TABLES_END = 277,
     TK_SL2VL_SCOPE_START = 278,
     TK_SL2VL_SCOPE_END = 279,
     TK_QOS_LEVELS_START = 280,
     TK_QOS_LEVELS_END = 281,
     TK_QOS_LEVEL_START = 282,
     TK_QOS_LEVEL_END = 283,
     TK_QOS_MATCH_RULES_START = 284,
     TK_QOS_MATCH_RULES_END = 285,
     TK_QOS_MATCH_RULE_START = 286,
     TK_QOS_MATCH_RULE_END = 287,
     TK_NAME = 288,
     TK_USE = 289,
     TK_PORT_GUID = 290,
     TK_PORT_NAME = 291,
     TK_PARTITION = 292,
     TK_NODE_TYPE = 293,
     TK_GROUP = 294,
     TK_ACROSS = 295,
     TK_VLARB_HIGH = 296,
     TK_VLARB_LOW = 297,
     TK_VLARB_HIGH_LIMIT = 298,
     TK_TO = 299,
     TK_FROM = 300,
     TK_ACROSS_TO = 301,
     TK_ACROSS_FROM = 302,
     TK_SL2VL_TABLE = 303,
     TK_SL = 304,
     TK_MTU_LIMIT = 305,
     TK_RATE_LIMIT = 306,
     TK_PACKET_LIFE = 307,
     TK_PATH_BITS = 308,
     TK_QOS_CLASS = 309,
     TK_SOURCE = 310,
     TK_DESTINATION = 311,
     TK_SERVICE_ID = 312,
     TK_QOS_LEVEL_NAME = 313,
     TK_PKEY = 314,
     TK_NODE_TYPE_ROUTER = 315,
     TK_NODE_TYPE_CA = 316,
     TK_NODE_TYPE_SWITCH = 317,
     TK_NODE_TYPE_SELF = 318,
     TK_NODE_TYPE_ALL = 319,
     TK_ULP_DEFAULT = 320,
     TK_ULP_ANY_SERVICE_ID = 321,
     TK_ULP_ANY_PKEY = 322,
     TK_ULP_ANY_TARGET_PORT_GUID = 323,
     TK_ULP_SDP_DEFAULT = 324,
     TK_ULP_SDP_PORT = 325,
     TK_ULP_RDS_DEFAULT = 326,
     TK_ULP_RDS_PORT = 327,
     TK_ULP_ISER_DEFAULT = 328,
     TK_ULP_ISER_PORT = 329,
     TK_ULP_SRP_GUID = 330,
     TK_ULP_IPOIB_DEFAULT = 331,
     TK_ULP_IPOIB_PKEY = 332
   };
#endif
/* Tokens.  */
#define TK_NUMBER 258
#define TK_DASH 259
#define TK_DOTDOT 260
#define TK_COMMA 261
#define TK_ASTERISK 262
#define TK_TEXT 263
#define TK_QOS_ULPS_START 264
#define TK_QOS_ULPS_END 265
#define TK_PORT_GROUPS_START 266
#define TK_PORT_GROUPS_END 267
#define TK_PORT_GROUP_START 268
#define TK_PORT_GROUP_END 269
#define TK_QOS_SETUP_START 270
#define TK_QOS_SETUP_END 271
#define TK_VLARB_TABLES_START 272
#define TK_VLARB_TABLES_END 273
#define TK_VLARB_SCOPE_START 274
#define TK_VLARB_SCOPE_END 275
#define TK_SL2VL_TABLES_START 276
#define TK_SL2VL_TABLES_END 277
#define TK_SL2VL_SCOPE_START 278
#define TK_SL2VL_SCOPE_END 279
#define TK_QOS_LEVELS_START 280
#define TK_QOS_LEVELS_END 281
#define TK_QOS_LEVEL_START 282
#define TK_QOS_LEVEL_END 283
#define TK_QOS_MATCH_RULES_START 284
#define TK_QOS_MATCH_RULES_END 285
#define TK_QOS_MATCH_RULE_START 286
#define TK_QOS_MATCH_RULE_END 287
#define TK_NAME 288
#define TK_USE 289
#define TK_PORT_GUID 290
#define TK_PORT_NAME 291
#define TK_PARTITION 292
#define TK_NODE_TYPE 293
#define TK_GROUP 294
#define TK_ACROSS 295
#define TK_VLARB_HIGH 296
#define TK_VLARB_LOW 297
#define TK_VLARB_HIGH_LIMIT 298
#define TK_TO 299
#define TK_FROM 300
#define TK_ACROSS_TO 301
#define TK_ACROSS_FROM 302
#define TK_SL2VL_TABLE 303
#define TK_SL 304
#define TK_MTU_LIMIT 305
#define TK_RATE_LIMIT 306
#define TK_PACKET_LIFE 307
#define TK_PATH_BITS 308
#define TK_QOS_CLASS 309
#define TK_SOURCE 310
#define TK_DESTINATION 311
#define TK_SERVICE_ID 312
#define TK_QOS_LEVEL_NAME 313
#define TK_PKEY 314
#define TK_NODE_TYPE_ROUTER 315
#define TK_NODE_TYPE_CA 316
#define TK_NODE_TYPE_SWITCH 317
#define TK_NODE_TYPE_SELF 318
#define TK_NODE_TYPE_ALL 319
#define TK_ULP_DEFAULT 320
#define TK_ULP_ANY_SERVICE_ID 321
#define TK_ULP_ANY_PKEY 322
#define TK_ULP_ANY_TARGET_PORT_GUID 323
#define TK_ULP_SDP_DEFAULT 324
#define TK_ULP_SDP_PORT 325
#define TK_ULP_RDS_DEFAULT 326
#define TK_ULP_RDS_PORT 327
#define TK_ULP_ISER_DEFAULT 328
#define TK_ULP_ISER_PORT 329
#define TK_ULP_SRP_GUID 330
#define TK_ULP_IPOIB_DEFAULT 331
#define TK_ULP_IPOIB_PKEY 332




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 456 "osm_qos_parser_y.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNRULES -- Number of states.  */
#define YYNSTATES  328

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      19,    23,    25,    28,    32,    34,    37,    41,    43,    45,
      46,    49,    51,    53,    55,    57,    59,    61,    63,    67,
      68,    71,    74,    78,    79,    82,    86,    88,    90,    91,
      94,    96,    98,   100,   102,   104,   108,   109,   112,   116,
     118,   120,   121,   124,   126,   128,   130,   132,   134,   136,
     138,   142,   143,   146,   150,   152,   154,   155,   158,   160,
     162,   164,   166,   168,   170,   172,   174,   178,   179,   182,
     186,   188,   190,   191,   194,   196,   198,   200,   202,   204,
     206,   208,   211,   212,   218,   219,   225,   226,   232,   233,
     237,   238,   244,   245,   249,   250,   256,   257,   261,   262,
     268,   269,   275,   276,   280,   281,   287,   289,   291,   293,
     295,   297,   299,   301,   303,   305,   307,   309,   311,   313,
     316,   318,   321,   323,   326,   328,   331,   333,   336,   338,
     341,   343,   346,   348,   350,   354,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   377,   379,   382,   384,
     387,   389,   392,   394,   397,   399,   402,   404,   407,   409,
     412,   414,   417,   419,   422,   424,   427,   429,   431,   433,
     435,   437,   439,   441,   443,   445,   448,   450,   453,   455,
     458,   460,   463,   465,   468,   470,   473,   475,   478,   480,
     483,   485,   488,   490,   493,   495,   498,   500,   503,   505,
     508,   510,   513,   515,   518,   520,   523,   525,   527,   529,
     532,   534,   536,   540,   542,   544,   548,   550,   554,   560,
     562,   564,   566,   568,   572,   578,   582,   584,   586
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    80,    -1,    -1,    80,    81,    -1,    82,
      -1,    84,    -1,    91,    -1,   107,    -1,   114,    -1,     9,
      83,    10,    -1,   121,    -1,    83,   121,    -1,    11,    85,
      12,    -1,    86,    -1,    85,    86,    -1,    87,    89,    88,
      -1,    13,    -1,    14,    -1,    -1,    89,    90,    -1,   147,
      -1,   149,    -1,   153,    -1,   151,    -1,   155,    -1,   157,
      -1,   159,    -1,    15,    92,    16,    -1,    -1,    92,    93,
      -1,    92,   100,    -1,    17,    94,    18,    -1,    -1,    94,
      95,    -1,    96,    98,    97,    -1,    19,    -1,    20,    -1,
      -1,    98,    99,    -1,   168,    -1,   170,    -1,   174,    -1,
     176,    -1,   172,    -1,    21,   101,    22,    -1,    -1,   101,
     102,    -1,   103,   105,   104,    -1,    23,    -1,    24,    -1,
      -1,   105,   106,    -1,   178,    -1,   180,    -1,   182,    -1,
     184,    -1,   186,    -1,   188,    -1,   196,    -1,    25,   108,
      26,    -1,    -1,   108,   109,    -1,   110,   112,   111,    -1,
      27,    -1,    28,    -1,    -1,   112,   113,    -1,   198,    -1,
     200,    -1,   202,    -1,   204,    -1,   206,    -1,   208,    -1,
     210,    -1,   212,    -1,    29,   115,    30,    -1,    -1,   115,
     116,    -1,   117,   119,   118,    -1,    31,    -1,    32,    -1,
      -1,   119,   120,    -1,   214,    -1,   216,    -1,   222,    -1,
     218,    -1,   220,    -1,   224,    -1,   226,    -1,    65,   232,
      -1,    -1,   134,   238,     5,   122,   146,    -1,    -1,   135,
     238,     5,   123,   146,    -1,    -1,   136,   238,     5,   124,
     146,    -1,    -1,   137,   125,   146,    -1,    -1,   138,   238,
       5,   126,   146,    -1,    -1,   139,   127,   146,    -1,    -1,
     140,   238,     5,   128,   146,    -1,    -1,   141,   129,   146,
      -1,    -1,   142,   238,     5,   130,   146,    -1,    -1,   143,
     238,     5,   131,   146,    -1,    -1,   144,   132,   146,    -1,
      -1,   145,   238,     5,   133,   146,    -1,    66,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,   232,    -1,   148,   228,    -1,    33,    -1,   150,   228,
      -1,    34,    -1,   152,   231,    -1,    36,    -1,   154,   238,
      -1,    35,    -1,   156,   238,    -1,    59,    -1,   158,   231,
      -1,    37,    -1,   160,   161,    -1,    38,    -1,   162,    -1,
     161,     6,   162,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,    61,    -1,    62,    -1,    60,    -1,
      64,    -1,    63,    -1,   169,   231,    -1,    39,    -1,   171,
     231,    -1,    40,    -1,   173,   232,    -1,    43,    -1,   175,
     235,    -1,    41,    -1,   177,   235,    -1,    42,    -1,   179,
     231,    -1,    39,    -1,   181,   231,    -1,    40,    -1,   183,
     231,    -1,    47,    -1,   185,   231,    -1,    46,    -1,   187,
     190,    -1,    45,    -1,   189,   192,    -1,    44,    -1,   191,
      -1,   194,    -1,     7,    -1,   193,    -1,   195,    -1,     7,
      -1,   238,    -1,   238,    -1,   197,   233,    -1,    48,    -1,
     199,   228,    -1,    33,    -1,   201,   228,    -1,    34,    -1,
     203,   232,    -1,    49,    -1,   205,   232,    -1,    50,    -1,
     207,   232,    -1,    51,    -1,   209,   232,    -1,    52,    -1,
     211,   238,    -1,    53,    -1,   213,   238,    -1,    59,    -1,
     215,   228,    -1,    34,    -1,   217,   238,    -1,    54,    -1,
     219,   231,    -1,    55,    -1,   221,   231,    -1,    56,    -1,
     223,   228,    -1,    58,    -1,   225,   238,    -1,    57,    -1,
     227,   238,    -1,    59,    -1,   229,    -1,   230,    -1,   229,
     230,    -1,     8,    -1,   228,    -1,   231,     6,   228,    -1,
     234,    -1,   234,    -1,   233,     6,   234,    -1,     3,    -1,
     236,     5,   237,    -1,   235,     6,   236,     5,   237,    -1,
       3,    -1,     3,    -1,   239,    -1,   240,    -1,   241,     4,
     242,    -1,   239,     6,   241,     4,   242,    -1,   239,     6,
     240,    -1,     3,    -1,     3,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   276,   276,   279,   280,   283,   284,   285,   286,   287,
     311,   314,   315,   344,   347,   348,   351,   354,   359,   365,
     366,   369,   370,   371,   372,   373,   374,   375,   402,   405,
     406,   407,   412,   415,   416,   419,   422,   427,   433,   434,
     449,   450,   451,   452,   453,   458,   461,   462,   465,   468,
     473,   479,   480,   499,   500,   501,   502,   503,   504,   505,
     529,   532,   533,   536,   539,   544,   550,   551,   554,   555,
     556,   557,   558,   559,   560,   561,   583,   586,   587,   590,
     593,   598,   604,   605,   608,   609,   610,   611,   612,   613,
     614,   636,   654,   654,   675,   675,   696,   696,   731,   731,
     744,   744,   777,   777,   790,   790,   823,   823,   836,   836,
     869,   869,   905,   905,   925,   925,   956,   959,   962,   965,
     968,   971,   974,   977,   980,   983,   986,   989,   993,  1032,
    1055,  1060,  1083,  1088,  1154,  1159,  1179,  1184,  1204,  1209,
    1217,  1222,  1227,  1232,  1233,  1236,  1237,  1238,  1239,  1240,
    1243,  1249,  1255,  1261,  1269,  1291,  1308,  1313,  1330,  1335,
    1353,  1358,  1375,  1380,  1397,  1413,  1430,  1435,  1454,  1459,
    1476,  1481,  1499,  1504,  1509,  1514,  1519,  1524,  1525,  1528,
    1535,  1536,  1539,  1546,  1578,  1611,  1654,  1671,  1694,  1699,
    1722,  1727,  1747,  1752,  1772,  1778,  1798,  1804,  1824,  1830,
    1865,  1870,  1903,  1920,  1943,  1948,  1982,  1987,  2004,  2009,
    2026,  2031,  2054,  2059,  2092,  2097,  2130,  2141,  2148,  2149,
    2152,  2159,  2160,  2165,  2168,  2169,  2172,  2180,  2186,  2194,
    2200,  2206,  2209,  2215,  2227,  2239,  2247,  2254,  2260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUMBER", "TK_DASH", "TK_DOTDOT",
  "TK_COMMA", "TK_ASTERISK", "TK_TEXT", "TK_QOS_ULPS_START",
  "TK_QOS_ULPS_END", "TK_PORT_GROUPS_START", "TK_PORT_GROUPS_END",
  "TK_PORT_GROUP_START", "TK_PORT_GROUP_END", "TK_QOS_SETUP_START",
  "TK_QOS_SETUP_END", "TK_VLARB_TABLES_START", "TK_VLARB_TABLES_END",
  "TK_VLARB_SCOPE_START", "TK_VLARB_SCOPE_END", "TK_SL2VL_TABLES_START",
  "TK_SL2VL_TABLES_END", "TK_SL2VL_SCOPE_START", "TK_SL2VL_SCOPE_END",
  "TK_QOS_LEVELS_START", "TK_QOS_LEVELS_END", "TK_QOS_LEVEL_START",
  "TK_QOS_LEVEL_END", "TK_QOS_MATCH_RULES_START", "TK_QOS_MATCH_RULES_END",
  "TK_QOS_MATCH_RULE_START", "TK_QOS_MATCH_RULE_END", "TK_NAME", "TK_USE",
  "TK_PORT_GUID", "TK_PORT_NAME", "TK_PARTITION", "TK_NODE_TYPE",
  "TK_GROUP", "TK_ACROSS", "TK_VLARB_HIGH", "TK_VLARB_LOW",
  "TK_VLARB_HIGH_LIMIT", "TK_TO", "TK_FROM", "TK_ACROSS_TO",
  "TK_ACROSS_FROM", "TK_SL2VL_TABLE", "TK_SL", "TK_MTU_LIMIT",
  "TK_RATE_LIMIT", "TK_PACKET_LIFE", "TK_PATH_BITS", "TK_QOS_CLASS",
  "TK_SOURCE", "TK_DESTINATION", "TK_SERVICE_ID", "TK_QOS_LEVEL_NAME",
  "TK_PKEY", "TK_NODE_TYPE_ROUTER", "TK_NODE_TYPE_CA",
  "TK_NODE_TYPE_SWITCH", "TK_NODE_TYPE_SELF", "TK_NODE_TYPE_ALL",
  "TK_ULP_DEFAULT", "TK_ULP_ANY_SERVICE_ID", "TK_ULP_ANY_PKEY",
  "TK_ULP_ANY_TARGET_PORT_GUID", "TK_ULP_SDP_DEFAULT", "TK_ULP_SDP_PORT",
  "TK_ULP_RDS_DEFAULT", "TK_ULP_RDS_PORT", "TK_ULP_ISER_DEFAULT",
  "TK_ULP_ISER_PORT", "TK_ULP_SRP_GUID", "TK_ULP_IPOIB_DEFAULT",
  "TK_ULP_IPOIB_PKEY", "$accept", "head", "qos_policy_entries",
  "qos_policy_entry", "qos_ulps_section", "qos_ulps",
  "port_groups_section", "port_groups", "port_group", "port_group_start",
  "port_group_end", "port_group_entries", "port_group_entry",
  "qos_setup_section", "qos_setup_items", "vlarb_tables",
  "vlarb_scope_items", "vlarb_scope", "vlarb_scope_start",
  "vlarb_scope_end", "vlarb_scope_entries", "vlarb_scope_entry",
  "sl2vl_tables", "sl2vl_scope_items", "sl2vl_scope", "sl2vl_scope_start",
  "sl2vl_scope_end", "sl2vl_scope_entries", "sl2vl_scope_entry",
  "qos_levels_section", "qos_levels", "qos_level", "qos_level_start",
  "qos_level_end", "qos_level_entries", "qos_level_entry",
  "qos_match_rules_section", "qos_match_rules", "qos_match_rule",
  "qos_match_rule_start", "qos_match_rule_end", "qos_match_rule_entries",
  "qos_match_rule_entry", "qos_ulp", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "qos_ulp_type_any_service", "qos_ulp_type_any_pkey",
  "qos_ulp_type_any_target_port_guid", "qos_ulp_type_sdp_default",
  "qos_ulp_type_sdp_port", "qos_ulp_type_rds_default",
  "qos_ulp_type_rds_port", "qos_ulp_type_iser_default",
  "qos_ulp_type_iser_port", "qos_ulp_type_srp_guid",
  "qos_ulp_type_ipoib_default", "qos_ulp_type_ipoib_pkey", "qos_ulp_sl",
  "port_group_name", "port_group_name_start", "port_group_use",
  "port_group_use_start", "port_group_port_name",
  "port_group_port_name_start", "port_group_port_guid",
  "port_group_port_guid_start", "port_group_pkey", "port_group_pkey_start",
  "port_group_partition", "port_group_partition_start",
  "port_group_node_type", "port_group_node_type_start",
  "port_group_node_type_list", "node_type_item", "node_type_ca",
  "node_type_switch", "node_type_router", "node_type_all",
  "node_type_self", "vlarb_scope_group", "vlarb_scope_group_start",
  "vlarb_scope_across", "vlarb_scope_across_start",
  "vlarb_scope_vlarb_high_limit", "vlarb_scope_vlarb_high_limit_start",
  "vlarb_scope_vlarb_high", "vlarb_scope_vlarb_high_start",
  "vlarb_scope_vlarb_low", "vlarb_scope_vlarb_low_start",
  "sl2vl_scope_group", "sl2vl_scope_group_start", "sl2vl_scope_across",
  "sl2vl_scope_across_start", "sl2vl_scope_across_from",
  "sl2vl_scope_across_from_start", "sl2vl_scope_across_to",
  "sl2vl_scope_across_to_start", "sl2vl_scope_from",
  "sl2vl_scope_from_start", "sl2vl_scope_to", "sl2vl_scope_to_start",
  "sl2vl_scope_from_list_or_asterisk", "sl2vl_scope_from_asterisk",
  "sl2vl_scope_to_list_or_asterisk", "sl2vl_scope_to_asterisk",
  "sl2vl_scope_from_list_of_ranges", "sl2vl_scope_to_list_of_ranges",
  "sl2vl_scope_sl2vl_table", "sl2vl_scope_sl2vl_table_start",
  "qos_level_name", "qos_level_name_start", "qos_level_use",
  "qos_level_use_start", "qos_level_sl", "qos_level_sl_start",
  "qos_level_mtu_limit", "qos_level_mtu_limit_start",
  "qos_level_rate_limit", "qos_level_rate_limit_start",
  "qos_level_packet_life", "qos_level_packet_life_start",
  "qos_level_path_bits", "qos_level_path_bits_start", "qos_level_pkey",
  "qos_level_pkey_start", "qos_match_rule_use", "qos_match_rule_use_start",
  "qos_match_rule_qos_class", "qos_match_rule_qos_class_start",
  "qos_match_rule_source", "qos_match_rule_source_start",
  "qos_match_rule_destination", "qos_match_rule_destination_start",
  "qos_match_rule_qos_level_name", "qos_match_rule_qos_level_name_start",
  "qos_match_rule_service_id", "qos_match_rule_service_id_start",
  "qos_match_rule_pkey", "qos_match_rule_pkey_start", "single_string",
  "single_string_elems", "single_string_element", "string_list",
  "single_number", "num_list", "number", "num_list_with_dotdot",
  "number_from_pair_1", "number_from_pair_2", "list_of_ranges",
  "num_list_with_dash", "single_number_from_range", "number_from_range_1",
  "number_from_range_2", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    87,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    92,
      92,    92,    93,    94,    94,    95,    96,    97,    98,    98,
      99,    99,    99,    99,    99,   100,   101,   101,   102,   103,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     107,   108,   108,   109,   110,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   115,   115,   116,
     117,   118,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   121,   122,   121,   123,   121,   124,   121,   125,   121,
     126,   121,   127,   121,   128,   121,   129,   121,   130,   121,
     131,   121,   132,   121,   133,   121,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   161,   162,   162,   162,   162,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   190,   191,
     192,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   229,
     230,   231,   231,   232,   233,   233,   234,   235,   235,   236,
     237,   238,   239,   239,   239,   239,   240,   241,   242
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       2,     2,     3,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     5,     0,     5,     0,     5,     0,     3,
       0,     5,     0,     3,     0,     5,     0,     3,     0,     5,
       0,     5,     0,     3,     0,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     2,
       1,     1,     3,     1,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     3,     5,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,    29,    61,    77,     4,
       5,     6,     7,     8,     9,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,    11,
       0,     0,     0,    98,     0,   102,     0,   106,     0,     0,
     112,     0,    17,     0,    14,    19,     0,     0,     0,   226,
      91,   223,    10,    12,   236,     0,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    15,     0,    28,    33,    46,    30,    31,    60,    64,
      62,    66,    76,    80,    78,    82,    92,     0,     0,    94,
      96,    99,   128,   100,   103,   104,   107,   108,   110,   113,
     114,    18,   130,   132,   136,   134,   140,   142,   138,    16,
      20,    21,     0,    22,     0,    24,     0,    23,     0,    25,
       0,    26,     0,    27,     0,     0,     0,     0,     0,     0,
     235,     0,   238,   233,     0,     0,     0,     0,     0,     0,
       0,   220,   129,   217,   218,   131,   221,   133,   135,   137,
     139,   152,   150,   151,   154,   153,   141,   143,   145,   146,
     147,   148,   149,    32,    36,    34,    38,    45,    49,    47,
      51,    65,   188,   190,   192,   194,   196,   198,   200,   202,
      63,    67,    68,     0,    69,     0,    70,     0,    71,     0,
      72,     0,    73,     0,    74,     0,    75,     0,    81,   204,
     206,   208,   210,   214,   212,   216,    79,    83,    84,     0,
      85,     0,    87,     0,    88,     0,    86,     0,    89,     0,
      90,     0,    93,     0,    95,    97,   101,   105,   109,   111,
     115,   219,     0,     0,     0,     0,   187,   189,   191,   193,
     195,   197,   199,   201,   203,   205,   207,   209,   211,   213,
     215,   234,   222,   144,    37,   156,   158,   162,   164,   160,
      35,    39,    40,     0,    41,     0,    44,     0,    42,     0,
      43,     0,    50,   166,   168,   176,   174,   172,   170,   186,
      48,    52,    53,     0,    54,     0,    55,     0,    56,     0,
      57,     0,    58,     0,    59,     0,   155,   157,   159,   229,
     161,     0,   163,   165,   167,   169,   171,   179,   173,   177,
     178,   183,   182,   175,   180,   181,   184,   185,   224,     0,
       0,     0,     0,   230,   227,   225,     0,   228
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    28,    11,    43,    44,    45,
     109,    72,   110,    12,    46,    76,   125,   165,   166,   260,
     234,   261,    77,   126,   169,   170,   280,   235,   281,    13,
      47,    80,    81,   180,   127,   181,    14,    48,    84,    85,
     206,   128,   207,    29,   129,   134,   135,    61,   136,    63,
     137,    65,   138,   139,    68,   140,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    91,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   156,   157,   158,   159,   160,   161,   162,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   308,   309,   313,   314,   310,   315,   294,   295,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     146,   143,   144,   147,    92,   317,    51,   300,   301,   324,
      55,    56,    57,    58,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -279
static const yytype_int16 yypact[] =
{
    -279,    19,     5,  -279,    63,     9,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,    21,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,    45,  -279,
      29,    29,    29,  -279,    29,  -279,    29,  -279,    29,    29,
    -279,    29,  -279,     0,  -279,  -279,    36,    33,    -4,  -279,
    -279,  -279,  -279,  -279,    31,    61,    62,  -279,    70,    71,
      79,    21,    80,    21,    81,    21,    83,    85,    21,    86,
    -279,  -279,     4,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,    29,    64,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,    84,  -279,    84,  -279,    84,  -279,    29,  -279,
      29,  -279,    84,  -279,    91,    32,    39,    -5,    24,    21,
    -279,    90,  -279,  -279,    21,    21,    21,    21,    21,    21,
      21,  -279,  -279,    84,  -279,  -279,  -279,    92,  -279,  -279,
      92,  -279,  -279,  -279,  -279,  -279,    93,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,    84,  -279,    84,  -279,    21,  -279,    21,
    -279,    21,  -279,    21,  -279,    29,  -279,    29,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,    84,
    -279,    29,  -279,    84,  -279,    84,  -279,    84,  -279,    29,
    -279,    29,  -279,    64,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,    84,    91,   107,    25,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,    92,    92,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,    84,  -279,    84,  -279,    21,  -279,    97,
    -279,    97,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,    84,  -279,    84,  -279,    84,  -279,    84,
    -279,     8,  -279,    18,  -279,    21,    92,    92,  -279,  -279,
     117,   120,   117,    92,    92,    92,    92,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   135,  -279,    97,
     123,    21,   137,  -279,  -279,  -279,   123,  -279
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,    53,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,   116,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   -32,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,   -77,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -108,  -279,    14,  -120,    -6,  -279,  -278,  -113,  -160,  -166,
     -31,  -279,    74,    75,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -238
static const yytype_int16 yytable[] =
{
      59,    60,   150,    62,   142,    64,   145,    66,    67,    50,
      69,    54,    70,    42,     4,   307,     5,   318,   101,     3,
       6,    54,    42,   171,    49,   312,    82,    83,   172,   173,
       7,    94,    54,    96,     8,  -237,    99,   102,   103,   104,
     105,   106,   107,   325,   174,   175,   176,   177,   178,   272,
     163,   164,    73,    74,   179,    52,   198,    75,   199,    78,
      79,   167,   168,   108,   273,   274,    86,   132,    87,   275,
     276,   277,   278,   279,    88,   236,    89,   237,   200,   201,
     202,   203,   204,   205,    90,    93,    95,   148,    97,   149,
      98,   100,   141,   246,   223,   247,    71,   222,   232,   233,
     299,   244,   224,   225,   226,   227,   228,   229,   230,   248,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   319,   252,   320,   323,   254,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   321,   326,   296,    53,   297,   255,   256,   257,   258,
     259,   151,   152,   153,   154,   155,   253,   231,   302,   322,
     327,   130,   131,   303,   242,   304,   243,   305,   251,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   238,     0,   239,     0,   240,     0,   241,   249,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     311,   298,   316
};

static const yytype_int16 yycheck[] =
{
      31,    32,   122,    34,   112,    36,   114,    38,    39,    15,
      41,     3,    12,    13,     9,     7,    11,   295,    14,     0,
      15,     3,    13,    28,     3,     7,    30,    31,    33,    34,
      25,    63,     3,    65,    29,     4,    68,    33,    34,    35,
      36,    37,    38,   321,    49,    50,    51,    52,    53,    24,
      18,    19,    16,    17,    59,    10,    32,    21,    34,    26,
      27,    22,    23,    59,    39,    40,     5,     3,     6,    44,
      45,    46,    47,    48,     4,   183,     5,   185,    54,    55,
      56,    57,    58,    59,     5,     5,     5,   118,     5,   120,
       5,     5,     8,   213,     4,   215,    43,   129,     6,     6,
       3,   209,   134,   135,   136,   137,   138,   139,   140,   217,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     6,   232,     5,     3,    20,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     6,     5,   263,    28,   265,    39,    40,    41,    42,
      43,    60,    61,    62,    63,    64,   233,   143,   271,   319,
     326,    87,    87,   283,   195,   285,   197,   287,   223,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   187,    -1,   189,    -1,   191,    -1,   193,   219,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,   267,   293
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,    80,     0,     9,    11,    15,    25,    29,    81,
      82,    84,    91,   107,   114,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    83,   121,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    13,    85,    86,    87,    92,   108,   115,     3,
     232,   234,    10,   121,     3,   238,   239,   240,   241,   238,
     238,   125,   238,   127,   238,   129,   238,   238,   132,   238,
      12,    86,    89,    16,    17,    21,    93,   100,    26,    27,
     109,   110,    30,    31,   116,   117,     5,     6,     4,     5,
       5,   146,   232,     5,   146,     5,   146,     5,     5,   146,
       5,    14,    33,    34,    35,    36,    37,    38,    59,    88,
      90,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    94,   101,   112,   119,   122,
     240,   241,     3,   242,   123,   124,   126,   128,   130,   131,
     133,     8,   228,   229,   230,   228,   228,   231,   238,   238,
     231,    60,    61,    62,    63,    64,   161,   162,   163,   164,
     165,   166,   167,    18,    19,    95,    96,    22,    23,   102,
     103,    28,    33,    34,    49,    50,    51,    52,    53,    59,
     111,   113,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    32,    34,
      54,    55,    56,    57,    58,    59,   118,   120,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   146,     4,   146,   146,   146,   146,   146,   146,
     146,   230,     6,     6,    98,   105,   228,   228,   232,   232,
     232,   232,   238,   238,   228,   238,   231,   231,   228,   238,
     238,   242,   228,   162,    20,    39,    40,    41,    42,    43,
      97,    99,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    24,    39,    40,    44,    45,    46,    47,    48,
     104,   106,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   196,   197,   231,   231,   232,     3,
     235,   236,   235,   231,   231,   231,   231,     7,   190,   191,
     194,   238,     7,   192,   193,   195,   238,   233,   234,     6,
       5,     6,   236,     3,   237,   234,     5,   237
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 17:

/* Line 1455 of yacc.c  */
#line 354 "osm_qos_parser_y.y"
    {
                        __parser_port_group_start();
                    }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 359 "osm_qos_parser_y.y"
    {
                        if ( __parser_port_group_end() )
                            return 1;
                    }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 422 "osm_qos_parser_y.y"
    {
                        __parser_vlarb_scope_start();
                    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 427 "osm_qos_parser_y.y"
    {
                        if ( __parser_vlarb_scope_end() )
                            return 1;
                    }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 468 "osm_qos_parser_y.y"
    {
                        __parser_sl2vl_scope_start();
                    }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 473 "osm_qos_parser_y.y"
    {
                        if ( __parser_sl2vl_scope_end() )
                            return 1;
                    }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 539 "osm_qos_parser_y.y"
    {
                        __parser_qos_level_start();
                    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 544 "osm_qos_parser_y.y"
    {
                        if ( __parser_qos_level_end() )
                            return 1;
                    }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 593 "osm_qos_parser_y.y"
    {
                        __parser_match_rule_start();
                    }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 598 "osm_qos_parser_y.y"
    {
                        if ( __parser_match_rule_end() )
                            return 1;
                    }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 636 "osm_qos_parser_y.y"
    {
                        /* parsing default ulp rule: "default: num" */
                        cl_list_iterator_t    list_iterator;
                        uint64_t            * p_tmp_num;

                        list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                        p_tmp_num = (uint64_t*)cl_list_obj(list_iterator);
                        if (*p_tmp_num > 15)
                        {
                            yyerror("illegal SL value");
                            return 1;
                        }
                        __default_simple_qos_level.sl = (uint8_t)(*p_tmp_num);
                        __default_simple_qos_level.sl_set = TRUE;
                        free(p_tmp_num);
                        cl_list_remove_all(&tmp_parser_struct.num_list);
                    }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 654 "osm_qos_parser_y.y"
    {
                        /* "any, service-id ... : sl" - one instance of list of ranges */
                        uint64_t ** range_arr;
                        unsigned    range_len;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("ULP rule doesn't have service ids");
                            return 1;
                        }

                        /* get all the service id ranges */
                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = range_len;

                    }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 675 "osm_qos_parser_y.y"
    {
                        /* "any, pkey ... : sl" - one instance of list of ranges */
                        uint64_t ** range_arr;
                        unsigned    range_len;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("ULP rule doesn't have pkeys");
                            return 1;
                        }

                        /* get all the pkey ranges */
                        __pkey_rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );

                        p_current_qos_match_rule->pkey_range_arr = range_arr;
                        p_current_qos_match_rule->pkey_range_len = range_len;

                    }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 696 "osm_qos_parser_y.y"
    {
                        /* any, target-port-guid ... : sl */
                        uint64_t ** range_arr;
                        unsigned    range_len;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("ULP rule doesn't have port guids");
                            return 1;
                        }

                        /* create a new port group with these ports */
                        __parser_port_group_start();

                        p_current_port_group->name = strdup("_ULP_Targets_");
                        p_current_port_group->use = strdup("Generated from ULP rules");

                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );

                        __parser_add_guid_range_to_port_map(
                                              &p_current_port_group->port_map,
                                              range_arr,
                                              range_len);

                        /* add this port group to the destination
                           groups of the current match rule */
                        cl_list_insert_tail(&p_current_qos_match_rule->destination_group_list,
                                            p_current_port_group);

                        __parser_port_group_end();

                    }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 731 "osm_qos_parser_y.y"
    {
                        /* "sdp : sl" - default SL for SDP */
                        uint64_t ** range_arr =
                               (uint64_t **)malloc(sizeof(uint64_t *));
                        range_arr[0] = (uint64_t *)malloc(2*sizeof(uint64_t));
                        range_arr[0][0] = OSM_QOS_POLICY_ULP_SDP_SERVICE_ID;
                        range_arr[0][1] = OSM_QOS_POLICY_ULP_SDP_SERVICE_ID + 0xFFFF;

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = 1;

                    }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 744 "osm_qos_parser_y.y"
    {
                        /* sdp with port numbers */
                        uint64_t ** range_arr;
                        unsigned    range_len;
                        unsigned    i;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("SDP ULP rule doesn't have port numbers");
                            return 1;
                        }

                        /* get all the port ranges */
                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );
                        /* now translate these port numbers into service ids */
                        for (i = 0; i < range_len; i++)
                        {
                            if (range_arr[i][0] > 0xFFFF || range_arr[i][1] > 0xFFFF)
                            {
                                yyerror("SDP port number out of range");
                                return 1;
                            }
                            range_arr[i][0] += OSM_QOS_POLICY_ULP_SDP_SERVICE_ID;
                            range_arr[i][1] += OSM_QOS_POLICY_ULP_SDP_SERVICE_ID;
                        }

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = range_len;

                    }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 777 "osm_qos_parser_y.y"
    {
                        /* "rds : sl" - default SL for RDS */
                        uint64_t ** range_arr =
                               (uint64_t **)malloc(sizeof(uint64_t *));
                        range_arr[0] = (uint64_t *)malloc(2*sizeof(uint64_t));
                        range_arr[0][0] = range_arr[0][1] =
                           OSM_QOS_POLICY_ULP_RDS_SERVICE_ID + OSM_QOS_POLICY_ULP_RDS_PORT;

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = 1;

                    }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 790 "osm_qos_parser_y.y"
    {
                        /* rds with port numbers */
                        uint64_t ** range_arr;
                        unsigned    range_len;
                        unsigned    i;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("RDS ULP rule doesn't have port numbers");
                            return 1;
                        }

                        /* get all the port ranges */
                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );
                        /* now translate these port numbers into service ids */
                        for (i = 0; i < range_len; i++)
                        {
                            if (range_arr[i][0] > 0xFFFF || range_arr[i][1] > 0xFFFF)
                            {
                                yyerror("SDP port number out of range");
                                return 1;
                            }
                            range_arr[i][0] += OSM_QOS_POLICY_ULP_RDS_SERVICE_ID;
                            range_arr[i][1] += OSM_QOS_POLICY_ULP_RDS_SERVICE_ID;
                        }

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = range_len;

                    }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 823 "osm_qos_parser_y.y"
    {
                        /* "iSER : sl" - default SL for iSER */
                        uint64_t ** range_arr =
                               (uint64_t **)malloc(sizeof(uint64_t *));
                        range_arr[0] = (uint64_t *)malloc(2*sizeof(uint64_t));
                        range_arr[0][0] = range_arr[0][1] =
                           OSM_QOS_POLICY_ULP_ISER_SERVICE_ID + OSM_QOS_POLICY_ULP_ISER_PORT;

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = 1;

                    }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 836 "osm_qos_parser_y.y"
    {
                        /* iser with port numbers */
                        uint64_t ** range_arr;
                        unsigned    range_len;
                        unsigned    i;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("iSER ULP rule doesn't have port numbers");
                            return 1;
                        }

                        /* get all the port ranges */
                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );
                        /* now translate these port numbers into service ids */
                        for (i = 0; i < range_len; i++)
                        {
                            if (range_arr[i][0] > 0xFFFF || range_arr[i][1] > 0xFFFF)
                            {
                                yyerror("SDP port number out of range");
                                return 1;
                            }
                            range_arr[i][0] += OSM_QOS_POLICY_ULP_ISER_SERVICE_ID;
                            range_arr[i][1] += OSM_QOS_POLICY_ULP_ISER_SERVICE_ID;
                        }

                        p_current_qos_match_rule->service_id_range_arr = range_arr;
                        p_current_qos_match_rule->service_id_range_len = range_len;

                    }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 869 "osm_qos_parser_y.y"
    {
                        /* srp with target guids - this rule is similar
                           to writing 'any' ulp with target port guids */
                        uint64_t ** range_arr;
                        unsigned    range_len;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("SRP ULP rule doesn't have port guids");
                            return 1;
                        }

                        /* create a new port group with these ports */
                        __parser_port_group_start();

                        p_current_port_group->name = strdup("_SRP_Targets_");
                        p_current_port_group->use = strdup("Generated from ULP rules");

                        __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );

                        __parser_add_guid_range_to_port_map(
                                              &p_current_port_group->port_map,
                                              range_arr,
                                              range_len);

                        /* add this port group to the destination
                           groups of the current match rule */
                        cl_list_insert_tail(&p_current_qos_match_rule->destination_group_list,
                                            p_current_port_group);

                        __parser_port_group_end();

                    }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 905 "osm_qos_parser_y.y"
    {
                        /* ipoib w/o any pkeys (default pkey) */
                        uint64_t ** range_arr =
                               (uint64_t **)malloc(sizeof(uint64_t *));
                        range_arr[0] = (uint64_t *)malloc(2*sizeof(uint64_t));
                        range_arr[0][0] = range_arr[0][1] = 0x7fff;

                        /*
                         * Although we know that the default partition exists,
                         * we still need to validate it by checking that it has
                         * at least two full members. Otherwise IPoIB won't work.
                         */
                        if (__validate_pkeys(range_arr, 1, TRUE))
                            return 1;

                        p_current_qos_match_rule->pkey_range_arr = range_arr;
                        p_current_qos_match_rule->pkey_range_len = 1;

                    }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 925 "osm_qos_parser_y.y"
    {
                        /* ipoib with pkeys */
                        uint64_t ** range_arr;
                        unsigned    range_len;

                        if (!cl_list_count(&tmp_parser_struct.num_pair_list))
                        {
                            yyerror("IPoIB ULP rule doesn't have pkeys");
                            return 1;
                        }

                        /* get all the pkey ranges */
                        __pkey_rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                              &range_arr,
                                              &range_len );

                        /*
                         * Validate pkeys.
                         * For IPoIB pkeys the validation is strict.
                         * If some problem would be found, parsing will
                         * be aborted with a proper error messages.
                         */
                        if (__validate_pkeys(range_arr, range_len, TRUE))
                            return 1;

                        p_current_qos_match_rule->pkey_range_arr = range_arr;
                        p_current_qos_match_rule->pkey_range_len = range_len;

                    }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 957 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 960 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 963 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 966 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 969 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 972 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 975 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 978 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 981 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 984 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 987 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 990 "osm_qos_parser_y.y"
    { __parser_ulp_match_rule_start(); }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 993 "osm_qos_parser_y.y"
    {
                        /* get the SL for ULP rules */
                        cl_list_iterator_t  list_iterator;
                        uint64_t          * p_tmp_num;
                        uint8_t             sl;

                        list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                        p_tmp_num = (uint64_t*)cl_list_obj(list_iterator);
                        if (*p_tmp_num > 15)
                        {
                            yyerror("illegal SL value");
                            return 1;
                        }

                        sl = (uint8_t)(*p_tmp_num);
                        free(p_tmp_num);
                        cl_list_remove_all(&tmp_parser_struct.num_list);

                        p_current_qos_match_rule->p_qos_level =
                                 &osm_qos_policy_simple_qos_levels[sl];
                        p_current_qos_match_rule->qos_level_name =
                                 strdup(osm_qos_policy_simple_qos_levels[sl].name);

                        if (__parser_ulp_match_rule_end())
                            return 1;
                    }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1032 "osm_qos_parser_y.y"
    {
                            /* 'name' of 'port-group' - one instance */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            if (p_current_port_group->name)
                            {
                                yyerror("port-group has multiple 'name' tags");
                                cl_list_remove_all(&tmp_parser_struct.str_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_port_group->name = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1055 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1060 "osm_qos_parser_y.y"
    {
                            /* 'use' of 'port-group' - one instance */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            if (p_current_port_group->use)
                            {
                                yyerror("port-group has multiple 'use' tags");
                                cl_list_remove_all(&tmp_parser_struct.str_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_port_group->use = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1083 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1088 "osm_qos_parser_y.y"
    {
                            /* 'port-name' in 'port-group' - any num of instances */
                            cl_list_iterator_t list_iterator;
                            osm_node_t * p_node;
                            osm_physp_t * p_physp;
                            unsigned port_num;
                            char * tmp_str;
                            char * port_str;

                            /* parsing port name strings */
                            for (list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                                 list_iterator != cl_list_end(&tmp_parser_struct.str_list);
                                 list_iterator = cl_list_next(list_iterator))
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                {
                                    /* last slash in port name string is a separator
                                       between node name and port number */
                                    port_str = strrchr(tmp_str, '/');
                                    if (!port_str || (strlen(port_str) < 3) ||
                                        (port_str[1] != 'p' && port_str[1] != 'P')) {
                                        yyerror("'%s' - illegal port name",
                                                           tmp_str);
                                        free(tmp_str);
                                        cl_list_remove_all(&tmp_parser_struct.str_list);
                                        return 1;
                                    }

                                    if (!(port_num = strtoul(&port_str[2],NULL,0))) {
                                        yyerror(
                                               "'%s' - illegal port number in port name",
                                               tmp_str);
                                        free(tmp_str);
                                        cl_list_remove_all(&tmp_parser_struct.str_list);
                                        return 1;
                                    }

                                    /* separate node name from port number */
                                    port_str[0] = '\0';

                                    if (st_lookup(p_qos_policy->p_node_hash,
                                                  (st_data_t)tmp_str,
                                                  (void *)&p_node))
                                    {
                                        /* we found the node, now get the right port */
                                        p_physp = osm_node_get_physp_ptr(p_node, port_num);
                                        if (!p_physp) {
                                            yyerror(
                                                   "'%s' - port number out of range in port name",
                                                   tmp_str);
                                            free(tmp_str);
                                            cl_list_remove_all(&tmp_parser_struct.str_list);
                                            return 1;
                                        }
                                        /* we found the port, now add it to guid table */
                                        __parser_add_port_to_port_map(&p_current_port_group->port_map,
                                                                      p_physp);
                                    }
                                    free(tmp_str);
                                }
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1154 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1159 "osm_qos_parser_y.y"
    {
                            /* 'port-guid' in 'port-group' - any num of instances */
                            /* list of guid ranges */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                __parser_add_guid_range_to_port_map(
                                                      &p_current_port_group->port_map,
                                                      range_arr,
                                                      range_len);
                            }
                        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1179 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1184 "osm_qos_parser_y.y"
    {
                            /* 'pkey' in 'port-group' - any num of instances */
                            /* list of pkey ranges */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __pkey_rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                __parser_add_pkey_range_to_port_map(
                                                      &p_current_port_group->port_map,
                                                      range_arr,
                                                      range_len);
                            }
                        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1204 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1209 "osm_qos_parser_y.y"
    {
                            /* 'partition' in 'port-group' - any num of instances */
                            __parser_add_partition_list_to_port_map(
                                               &p_current_port_group->port_map,
                                               &tmp_parser_struct.str_list);
                        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1217 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1222 "osm_qos_parser_y.y"
    {
                            /* 'node-type' in 'port-group' - any num of instances */
                        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1227 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1243 "osm_qos_parser_y.y"
    {
                            p_current_port_group->node_types |=
                               OSM_QOS_POLICY_NODE_TYPE_CA;
                        }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1249 "osm_qos_parser_y.y"
    {
                            p_current_port_group->node_types |=
                               OSM_QOS_POLICY_NODE_TYPE_SWITCH;
                        }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1255 "osm_qos_parser_y.y"
    {
                            p_current_port_group->node_types |=
                               OSM_QOS_POLICY_NODE_TYPE_ROUTER;
                        }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1261 "osm_qos_parser_y.y"
    {
                            p_current_port_group->node_types |=
                               (OSM_QOS_POLICY_NODE_TYPE_CA |
                                OSM_QOS_POLICY_NODE_TYPE_SWITCH |
                                OSM_QOS_POLICY_NODE_TYPE_ROUTER);
                        }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1269 "osm_qos_parser_y.y"
    {
                            osm_port_t * p_osm_port =
                                osm_get_port_by_guid(p_qos_policy->p_subn,
                                     p_qos_policy->p_subn->sm_port_guid);
                            if (p_osm_port)
                                __parser_add_port_to_port_map(
                                   &p_current_port_group->port_map,
                                   p_osm_port->p_physp);
                        }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1291 "osm_qos_parser_y.y"
    {
                            /* 'group' in 'vlarb-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_vlarb_scope->group_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1308 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1313 "osm_qos_parser_y.y"
    {
                            /* 'across' in 'vlarb-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_vlarb_scope->across_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1330 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1335 "osm_qos_parser_y.y"
    {
                            /* 'vl-high-limit' in 'vlarb-scope' - one instance of one number */
                            cl_list_iterator_t    list_iterator;
                            uint64_t            * p_tmp_num;

                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            p_tmp_num = (uint64_t*)cl_list_obj(list_iterator);
                            if (p_tmp_num)
                            {
                                p_current_vlarb_scope->vl_high_limit = (uint32_t)(*p_tmp_num);
                                p_current_vlarb_scope->vl_high_limit_set = TRUE;
                                free(p_tmp_num);
                            }

                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1353 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1358 "osm_qos_parser_y.y"
    {
                            /* 'vlarb-high' in 'vlarb-scope' - list of pairs of numbers with ':' and ',' */
                            cl_list_iterator_t    list_iterator;
                            uint64_t            * num_pair;

                            list_iterator = cl_list_head(&tmp_parser_struct.num_pair_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.num_pair_list) )
                            {
                                num_pair = (uint64_t*)cl_list_obj(list_iterator);
                                if (num_pair)
                                    cl_list_insert_tail(&p_current_vlarb_scope->vlarb_high_list,num_pair);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1375 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1380 "osm_qos_parser_y.y"
    {
                            /* 'vlarb-low' in 'vlarb-scope' - list of pairs of numbers with ':' and ',' */
                            cl_list_iterator_t    list_iterator;
                            uint64_t            * num_pair;

                            list_iterator = cl_list_head(&tmp_parser_struct.num_pair_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.num_pair_list) )
                            {
                                num_pair = (uint64_t*)cl_list_obj(list_iterator);
                                if (num_pair)
                                    cl_list_insert_tail(&p_current_vlarb_scope->vlarb_low_list,num_pair);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1397 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1413 "osm_qos_parser_y.y"
    {
                            /* 'group' in 'sl2vl-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_sl2vl_scope->group_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1430 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1435 "osm_qos_parser_y.y"
    {
                            /* 'across' in 'sl2vl-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str) {
                                    cl_list_insert_tail(&p_current_sl2vl_scope->across_from_list,tmp_str);
                                    cl_list_insert_tail(&p_current_sl2vl_scope->across_to_list,strdup(tmp_str));
                                }
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1454 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1459 "osm_qos_parser_y.y"
    {
                            /* 'across-from' in 'sl2vl-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_sl2vl_scope->across_from_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1476 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1481 "osm_qos_parser_y.y"
    {
                            /* 'across-to' in 'sl2vl-scope' - any num of instances */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str) {
                                    cl_list_insert_tail(&p_current_sl2vl_scope->across_to_list,tmp_str);
                                }
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1499 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1504 "osm_qos_parser_y.y"
    {
                            /* 'from' in 'sl2vl-scope' - any num of instances */
                        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1509 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1514 "osm_qos_parser_y.y"
    {
                            /* 'to' in 'sl2vl-scope' - any num of instances */
                        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1519 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1528 "osm_qos_parser_y.y"
    {
                            int i;
                            for (i = 0; i < OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH; i++)
                                p_current_sl2vl_scope->from[i] = TRUE;
                        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1539 "osm_qos_parser_y.y"
    {
                            int i;
                            for (i = 0; i < OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH; i++)
                                p_current_sl2vl_scope->to[i] = TRUE;
                        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1546 "osm_qos_parser_y.y"
    {
                            int i;
                            cl_list_iterator_t    list_iterator;
                            uint64_t            * num_pair;
                            uint8_t               num1, num2;

                            list_iterator = cl_list_head(&tmp_parser_struct.num_pair_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.num_pair_list) )
                            {
                                num_pair = (uint64_t*)cl_list_obj(list_iterator);
                                if (num_pair)
                                {
                                    if ( num_pair[0] < 0 ||
                                         num_pair[1] >= OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH )
                                    {
                                        yyerror("port number out of range 'from' list");
                                        free(num_pair);
                                        cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                                        return 1;
                                    }
                                    num1 = (uint8_t)num_pair[0];
                                    num2 = (uint8_t)num_pair[1];
                                    free(num_pair);
                                    for (i = num1; i <= num2; i++)
                                        p_current_sl2vl_scope->from[i] = TRUE;
                                }
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1578 "osm_qos_parser_y.y"
    {
                            int i;
                            cl_list_iterator_t    list_iterator;
                            uint64_t            * num_pair;
                            uint8_t               num1, num2;

                            list_iterator = cl_list_head(&tmp_parser_struct.num_pair_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.num_pair_list) )
                            {
                                num_pair = (uint64_t*)cl_list_obj(list_iterator);
                                if (num_pair)
                                {
                                    if ( num_pair[0] < 0 ||
                                         num_pair[1] >= OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH )
                                    {
                                        yyerror("port number out of range 'to' list");
                                        free(num_pair);
                                        cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                                        return 1;
                                    }
                                    num1 = (uint8_t)num_pair[0];
                                    num2 = (uint8_t)num_pair[1];
                                    free(num_pair);
                                    for (i = num1; i <= num2; i++)
                                        p_current_sl2vl_scope->to[i] = TRUE;
                                }
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.num_pair_list);
                        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1611 "osm_qos_parser_y.y"
    {
                            /* 'sl2vl-table' - one instance of exactly
                               OSM_QOS_POLICY_SL2VL_TABLE_LEN numbers */
                            cl_list_iterator_t    list_iterator;
                            uint64_t              num;
                            uint64_t            * p_num;
                            int                   i = 0;

                            if (p_current_sl2vl_scope->sl2vl_table_set)
                            {
                                yyerror("sl2vl-scope has more than one sl2vl-table");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }

                            if (cl_list_count(&tmp_parser_struct.num_list) != OSM_QOS_POLICY_SL2VL_TABLE_LEN)
                            {
                                yyerror("wrong number of values in 'sl2vl-table' (should be 16)");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.num_list) )
                            {
                                p_num = (uint64_t*)cl_list_obj(list_iterator);
                                num = *p_num;
                                free(p_num);
                                if (num >= OSM_QOS_POLICY_MAX_VL_NUM)
                                {
                                    yyerror("wrong VL value in 'sl2vl-table' (should be 0 to 15)");
                                    cl_list_remove_all(&tmp_parser_struct.num_list);
                                    return 1;
                                }

                                p_current_sl2vl_scope->sl2vl_table[i++] = (uint8_t)num;
                                list_iterator = cl_list_next(list_iterator);
                            }
                            p_current_sl2vl_scope->sl2vl_table_set = TRUE;
                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1654 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1671 "osm_qos_parser_y.y"
    {
                            /* 'name' of 'qos-level' - one instance */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            if (p_current_qos_level->name)
                            {
                                yyerror("qos-level has multiple 'name' tags");
                                cl_list_remove_all(&tmp_parser_struct.str_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_qos_level->name = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1694 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1699 "osm_qos_parser_y.y"
    {
                            /* 'use' of 'qos-level' - one instance */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            if (p_current_qos_level->use)
                            {
                                yyerror("qos-level has multiple 'use' tags");
                                cl_list_remove_all(&tmp_parser_struct.str_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_qos_level->use = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1722 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1727 "osm_qos_parser_y.y"
    {
                            /* 'sl' in 'qos-level' - one instance */
                            cl_list_iterator_t   list_iterator;
                            uint64_t           * p_num;

                            if (p_current_qos_level->sl_set)
                            {
                                yyerror("'qos-level' has multiple 'sl' tags");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }
                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            p_num = (uint64_t*)cl_list_obj(list_iterator);
                            p_current_qos_level->sl = (uint8_t)(*p_num);
                            free(p_num);
                            p_current_qos_level->sl_set = TRUE;
                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1747 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1752 "osm_qos_parser_y.y"
    {
                            /* 'mtu-limit' in 'qos-level' - one instance */
                            cl_list_iterator_t   list_iterator;
                            uint64_t           * p_num;

                            if (p_current_qos_level->mtu_limit_set)
                            {
                                yyerror("'qos-level' has multiple 'mtu-limit' tags");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }
                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            p_num = (uint64_t*)cl_list_obj(list_iterator);
                            p_current_qos_level->mtu_limit = (uint8_t)(*p_num);
                            free(p_num);
                            p_current_qos_level->mtu_limit_set = TRUE;
                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1772 "osm_qos_parser_y.y"
    {
                            /* 'mtu-limit' in 'qos-level' - one instance */
                            RESET_BUFFER;
                        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1778 "osm_qos_parser_y.y"
    {
                            /* 'rate-limit' in 'qos-level' - one instance */
                            cl_list_iterator_t   list_iterator;
                            uint64_t           * p_num;

                            if (p_current_qos_level->rate_limit_set)
                            {
                                yyerror("'qos-level' has multiple 'rate-limit' tags");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }
                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            p_num = (uint64_t*)cl_list_obj(list_iterator);
                            p_current_qos_level->rate_limit = (uint8_t)(*p_num);
                            free(p_num);
                            p_current_qos_level->rate_limit_set = TRUE;
                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1798 "osm_qos_parser_y.y"
    {
                            /* 'rate-limit' in 'qos-level' - one instance */
                            RESET_BUFFER;
                        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1804 "osm_qos_parser_y.y"
    {
                            /* 'packet-life' in 'qos-level' - one instance */
                            cl_list_iterator_t   list_iterator;
                            uint64_t           * p_num;

                            if (p_current_qos_level->pkt_life_set)
                            {
                                yyerror("'qos-level' has multiple 'packet-life' tags");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }
                            list_iterator = cl_list_head(&tmp_parser_struct.num_list);
                            p_num = (uint64_t*)cl_list_obj(list_iterator);
                            p_current_qos_level->pkt_life = (uint8_t)(*p_num);
                            free(p_num);
                            p_current_qos_level->pkt_life_set= TRUE;
                            cl_list_remove_all(&tmp_parser_struct.num_list);
                        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1824 "osm_qos_parser_y.y"
    {
                            /* 'packet-life' in 'qos-level' - one instance */
                            RESET_BUFFER;
                        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1830 "osm_qos_parser_y.y"
    {
                            /* 'path-bits' in 'qos-level' - any num of instances */
                            /* list of path bit ranges */

                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                if ( !p_current_qos_level->path_bits_range_len )
                                {
                                    p_current_qos_level->path_bits_range_arr = range_arr;
                                    p_current_qos_level->path_bits_range_len = range_len;
                                }
                                else
                                {
                                    uint64_t ** new_range_arr;
                                    unsigned new_range_len;
                                    __merge_rangearr( p_current_qos_level->path_bits_range_arr,
                                                      p_current_qos_level->path_bits_range_len,
                                                      range_arr,
                                                      range_len,
                                                      &new_range_arr,
                                                      &new_range_len );
                                    p_current_qos_level->path_bits_range_arr = new_range_arr;
                                    p_current_qos_level->path_bits_range_len = new_range_len;
                                }
                            }
                        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1865 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1870 "osm_qos_parser_y.y"
    {
                            /* 'pkey' in 'qos-level' - num of instances of list of ranges */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __pkey_rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                if ( !p_current_qos_level->pkey_range_len )
                                {
                                    p_current_qos_level->pkey_range_arr = range_arr;
                                    p_current_qos_level->pkey_range_len = range_len;
                                }
                                else
                                {
                                    uint64_t ** new_range_arr;
                                    unsigned new_range_len;
                                    __merge_rangearr( p_current_qos_level->pkey_range_arr,
                                                      p_current_qos_level->pkey_range_len,
                                                      range_arr,
                                                      range_len,
                                                      &new_range_arr,
                                                      &new_range_len );
                                    p_current_qos_level->pkey_range_arr = new_range_arr;
                                    p_current_qos_level->pkey_range_len = new_range_len;
                                }
                            }
                        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1903 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1920 "osm_qos_parser_y.y"
    {
                            /* 'use' of 'qos-match-rule' - one instance */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            if (p_current_qos_match_rule->use)
                            {
                                yyerror("'qos-match-rule' has multiple 'use' tags");
                                cl_list_remove_all(&tmp_parser_struct.str_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_qos_match_rule->use = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1943 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1948 "osm_qos_parser_y.y"
    {
                            /* 'qos-class' in 'qos-match-rule' - num of instances of list of ranges */
                            /* list of class ranges (QoS Class is 12-bit value) */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                if ( !p_current_qos_match_rule->qos_class_range_len )
                                {
                                    p_current_qos_match_rule->qos_class_range_arr = range_arr;
                                    p_current_qos_match_rule->qos_class_range_len = range_len;
                                }
                                else
                                {
                                    uint64_t ** new_range_arr;
                                    unsigned new_range_len;
                                    __merge_rangearr( p_current_qos_match_rule->qos_class_range_arr,
                                                      p_current_qos_match_rule->qos_class_range_len,
                                                      range_arr,
                                                      range_len,
                                                      &new_range_arr,
                                                      &new_range_len );
                                    p_current_qos_match_rule->qos_class_range_arr = new_range_arr;
                                    p_current_qos_match_rule->qos_class_range_len = new_range_len;
                                }
                            }
                        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1982 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1987 "osm_qos_parser_y.y"
    {
                            /* 'source' in 'qos-match-rule' - text */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_qos_match_rule->source_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 2004 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 2009 "osm_qos_parser_y.y"
    {
                            /* 'destination' in 'qos-match-rule' - text */
                            cl_list_iterator_t    list_iterator;
                            char                * tmp_str;

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            while( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    cl_list_insert_tail(&p_current_qos_match_rule->destination_list,tmp_str);
                                list_iterator = cl_list_next(list_iterator);
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 2026 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 2031 "osm_qos_parser_y.y"
    {
                            /* 'qos-level-name' in 'qos-match-rule' - single string */
                            cl_list_iterator_t   list_iterator;
                            char               * tmp_str;

                            if (p_current_qos_match_rule->qos_level_name)
                            {
                                yyerror("qos-match-rule has multiple 'qos-level-name' tags");
                                cl_list_remove_all(&tmp_parser_struct.num_list);
                                return 1;
                            }

                            list_iterator = cl_list_head(&tmp_parser_struct.str_list);
                            if ( list_iterator != cl_list_end(&tmp_parser_struct.str_list) )
                            {
                                tmp_str = (char*)cl_list_obj(list_iterator);
                                if (tmp_str)
                                    p_current_qos_match_rule->qos_level_name = tmp_str;
                            }
                            cl_list_remove_all(&tmp_parser_struct.str_list);
                        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 2054 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 2059 "osm_qos_parser_y.y"
    {
                            /* 'service-id' in 'qos-match-rule' - num of instances of list of ranges */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                if ( !p_current_qos_match_rule->service_id_range_len )
                                {
                                    p_current_qos_match_rule->service_id_range_arr = range_arr;
                                    p_current_qos_match_rule->service_id_range_len = range_len;
                                }
                                else
                                {
                                    uint64_t ** new_range_arr;
                                    unsigned new_range_len;
                                    __merge_rangearr( p_current_qos_match_rule->service_id_range_arr,
                                                      p_current_qos_match_rule->service_id_range_len,
                                                      range_arr,
                                                      range_len,
                                                      &new_range_arr,
                                                      &new_range_len );
                                    p_current_qos_match_rule->service_id_range_arr = new_range_arr;
                                    p_current_qos_match_rule->service_id_range_len = new_range_len;
                                }
                            }
                        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 2092 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 2097 "osm_qos_parser_y.y"
    {
                            /* 'pkey' in 'qos-match-rule' - num of instances of list of ranges */
                            if (cl_list_count(&tmp_parser_struct.num_pair_list))
                            {
                                uint64_t ** range_arr;
                                unsigned range_len;

                                __pkey_rangelist2rangearr( &tmp_parser_struct.num_pair_list,
                                                      &range_arr,
                                                      &range_len );

                                if ( !p_current_qos_match_rule->pkey_range_len )
                                {
                                    p_current_qos_match_rule->pkey_range_arr = range_arr;
                                    p_current_qos_match_rule->pkey_range_len = range_len;
                                }
                                else
                                {
                                    uint64_t ** new_range_arr;
                                    unsigned new_range_len;
                                    __merge_rangearr( p_current_qos_match_rule->pkey_range_arr,
                                                      p_current_qos_match_rule->pkey_range_len,
                                                      range_arr,
                                                      range_len,
                                                      &new_range_arr,
                                                      &new_range_len );
                                    p_current_qos_match_rule->pkey_range_arr = new_range_arr;
                                    p_current_qos_match_rule->pkey_range_len = new_range_len;
                                }
                            }
                        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 2130 "osm_qos_parser_y.y"
    {
                            RESET_BUFFER;
                        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 2141 "osm_qos_parser_y.y"
    {
                        cl_list_insert_tail(&tmp_parser_struct.str_list,
                                            strdup(__parser_strip_white(tmp_parser_struct.str)));
                        tmp_parser_struct.str[0] = '\0';
                    }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 2152 "osm_qos_parser_y.y"
    {
                        strcat(tmp_parser_struct.str,(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 2172 "osm_qos_parser_y.y"
    {
                        uint64_t * p_num = (uint64_t*)malloc(sizeof(uint64_t));
                        __parser_str2uint64(p_num,(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                        cl_list_insert_tail(&tmp_parser_struct.num_list, p_num);
                    }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 2180 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        num_pair[0] = tmp_parser_struct.num_pair[0];
                        num_pair[1] = tmp_parser_struct.num_pair[1];
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 2186 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        num_pair[0] = tmp_parser_struct.num_pair[0];
                        num_pair[1] = tmp_parser_struct.num_pair[1];
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 2194 "osm_qos_parser_y.y"
    {
                        __parser_str2uint64(&tmp_parser_struct.num_pair[0],(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 2200 "osm_qos_parser_y.y"
    {
                        __parser_str2uint64(&tmp_parser_struct.num_pair[1],(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 2209 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        num_pair[0] = tmp_parser_struct.num_pair[0];
                        num_pair[1] = tmp_parser_struct.num_pair[1];
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 2215 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        if (tmp_parser_struct.num_pair[0] <= tmp_parser_struct.num_pair[1]) {
                            num_pair[0] = tmp_parser_struct.num_pair[0];
                            num_pair[1] = tmp_parser_struct.num_pair[1];
                        }
                        else {
                            num_pair[1] = tmp_parser_struct.num_pair[0];
                            num_pair[0] = tmp_parser_struct.num_pair[1];
                        }
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 2227 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        if (tmp_parser_struct.num_pair[0] <= tmp_parser_struct.num_pair[1]) {
                            num_pair[0] = tmp_parser_struct.num_pair[0];
                            num_pair[1] = tmp_parser_struct.num_pair[1];
                        }
                        else {
                            num_pair[1] = tmp_parser_struct.num_pair[0];
                            num_pair[0] = tmp_parser_struct.num_pair[1];
                        }
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 2239 "osm_qos_parser_y.y"
    {
                        uint64_t * num_pair = (uint64_t*)malloc(sizeof(uint64_t)*2);
                        num_pair[0] = tmp_parser_struct.num_pair[0];
                        num_pair[1] = tmp_parser_struct.num_pair[1];
                        cl_list_insert_tail(&tmp_parser_struct.num_pair_list, num_pair);
                    }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 2247 "osm_qos_parser_y.y"
    {
                        __parser_str2uint64(&tmp_parser_struct.num_pair[0],(yyvsp[(1) - (1)]));
                        __parser_str2uint64(&tmp_parser_struct.num_pair[1],(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 2254 "osm_qos_parser_y.y"
    {
                        __parser_str2uint64(&tmp_parser_struct.num_pair[0],(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 2260 "osm_qos_parser_y.y"
    {
                        __parser_str2uint64(&tmp_parser_struct.num_pair[1],(yyvsp[(1) - (1)]));
                        free((yyvsp[(1) - (1)]));
                    }
    break;



/* Line 1455 of yacc.c  */
#line 4167 "osm_qos_parser_y.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2266 "osm_qos_parser_y.y"


/***************************************************
 ***************************************************/

int osm_qos_parse_policy_file(IN osm_subn_t * p_subn)
{
    int res = 0;
    static boolean_t first_time = TRUE;
    p_qos_parser_osm_log = &p_subn->p_osm->log;

    OSM_LOG_ENTER(p_qos_parser_osm_log);

    osm_qos_policy_destroy(p_subn->p_qos_policy);
    p_subn->p_qos_policy = NULL;

    yyin = fopen (p_subn->opt.qos_policy_file, "r");
    if (!yyin)
    {
        if (strcmp(p_subn->opt.qos_policy_file,OSM_DEFAULT_QOS_POLICY_FILE)) {
            OSM_LOG(p_qos_parser_osm_log, OSM_LOG_ERROR, "ERR AC01: "
                    "Failed opening QoS policy file %s - %s\n",
                    p_subn->opt.qos_policy_file, strerror(errno));
            res = 1;
        }
        else
            OSM_LOG(p_qos_parser_osm_log, OSM_LOG_VERBOSE,
                    "QoS policy file not found (%s)\n",
                    p_subn->opt.qos_policy_file);

        goto Exit;
    }

    if (first_time)
    {
        first_time = FALSE;
        __setup_simple_qos_levels();
        __setup_ulp_match_rules();
        OSM_LOG(p_qos_parser_osm_log, OSM_LOG_INFO,
		"Loading QoS policy file (%s)\n",
                p_subn->opt.qos_policy_file);
    }
    else
        /*
         * ULP match rules list was emptied at the end of
         * previous parsing iteration.
         * What's left is to clear simple QoS levels.
         */
        __clear_simple_qos_levels();

    column_num = 1;
    line_num = 1;

    p_subn->p_qos_policy = osm_qos_policy_create(p_subn);

    __parser_tmp_struct_init();
    p_qos_policy = p_subn->p_qos_policy;

    res = yyparse();

    __parser_tmp_struct_destroy();

    if (res != 0)
    {
        OSM_LOG(p_qos_parser_osm_log, OSM_LOG_ERROR, "ERR AC03: "
                "Failed parsing QoS policy file (%s)\n",
                p_subn->opt.qos_policy_file);
        osm_qos_policy_destroy(p_subn->p_qos_policy);
        p_subn->p_qos_policy = NULL;
        res = 1;
        goto Exit;
    }

    /* add generated ULP match rules to the usual match rules */
    __process_ulp_match_rules();

    if (osm_qos_policy_validate(p_subn->p_qos_policy,p_qos_parser_osm_log))
    {
        OSM_LOG(p_qos_parser_osm_log, OSM_LOG_ERROR, "ERR AC04: "
                "Error(s) in QoS policy file (%s)\n",
                p_subn->opt.qos_policy_file);
        fprintf(stderr, "Error(s) in QoS policy file (%s)\n",
                p_subn->opt.qos_policy_file);
        osm_qos_policy_destroy(p_subn->p_qos_policy);
        p_subn->p_qos_policy = NULL;
        res = 1;
        goto Exit;
    }

  Exit:
    if (yyin)
        fclose(yyin);
    OSM_LOG_EXIT(p_qos_parser_osm_log);
    return res;
}

/***************************************************
 ***************************************************/

int yywrap()
{
    return(1);
}

/***************************************************
 ***************************************************/

static void yyerror(const char *format, ...)
{
    char s[256];
    va_list pvar;

    OSM_LOG_ENTER(p_qos_parser_osm_log);

    va_start(pvar, format);
    vsnprintf(s, sizeof(s), format, pvar);
    va_end(pvar);

    OSM_LOG(p_qos_parser_osm_log, OSM_LOG_ERROR, "ERR AC05: "
            "Syntax error (line %d:%d): %s\n",
            line_num, column_num, s);
    fprintf(stderr, "Error in QoS Policy File (line %d:%d): %s.\n",
            line_num, column_num, s);
    OSM_LOG_EXIT(p_qos_parser_osm_log);
}

/***************************************************
 ***************************************************/

static char * __parser_strip_white(char * str)
{
	char *p;

	while (isspace(*str))
		str++;
	if (!*str)
		return str;
	p = str + strlen(str) - 1;
	while (isspace(*p))
		*p-- = '\0';

	return str;
}

/***************************************************
 ***************************************************/

static void __parser_str2uint64(uint64_t * p_val, char * str)
{
   *p_val = strtoull(str, NULL, 0);
}

/***************************************************
 ***************************************************/

static void __parser_port_group_start()
{
    p_current_port_group = osm_qos_policy_port_group_create();
}

/***************************************************
 ***************************************************/

static int __parser_port_group_end()
{
    if(!p_current_port_group->name)
    {
        yyerror("port-group validation failed - no port group name specified");
        return -1;
    }

    cl_list_insert_tail(&p_qos_policy->port_groups,
                        p_current_port_group);
    p_current_port_group = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_vlarb_scope_start()
{
    p_current_vlarb_scope = osm_qos_policy_vlarb_scope_create();
}

/***************************************************
 ***************************************************/

static int __parser_vlarb_scope_end()
{
    if ( !cl_list_count(&p_current_vlarb_scope->group_list) &&
         !cl_list_count(&p_current_vlarb_scope->across_list) )
    {
        yyerror("vlarb-scope validation failed - no port groups specified by 'group' or by 'across'");
        return -1;
    }

    cl_list_insert_tail(&p_qos_policy->vlarb_tables,
                        p_current_vlarb_scope);
    p_current_vlarb_scope = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_sl2vl_scope_start()
{
    p_current_sl2vl_scope = osm_qos_policy_sl2vl_scope_create();
}

/***************************************************
 ***************************************************/

static int __parser_sl2vl_scope_end()
{
    if (!p_current_sl2vl_scope->sl2vl_table_set)
    {
        yyerror("sl2vl-scope validation failed - no sl2vl table specified");
        return -1;
    }
    if ( !cl_list_count(&p_current_sl2vl_scope->group_list) &&
         !cl_list_count(&p_current_sl2vl_scope->across_to_list) &&
         !cl_list_count(&p_current_sl2vl_scope->across_from_list) )
    {
        yyerror("sl2vl-scope validation failed - no port groups specified by 'group', 'across-to' or 'across-from'");
        return -1;
    }

    cl_list_insert_tail(&p_qos_policy->sl2vl_tables,
                        p_current_sl2vl_scope);
    p_current_sl2vl_scope = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_qos_level_start()
{
    p_current_qos_level = osm_qos_policy_qos_level_create();
}

/***************************************************
 ***************************************************/

static int __parser_qos_level_end()
{
    if (!p_current_qos_level->sl_set)
    {
        yyerror("qos-level validation failed - no 'sl' specified");
        return -1;
    }
    if (!p_current_qos_level->name)
    {
        yyerror("qos-level validation failed - no 'name' specified");
        return -1;
    }

    cl_list_insert_tail(&p_qos_policy->qos_levels,
                        p_current_qos_level);
    p_current_qos_level = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_match_rule_start()
{
    p_current_qos_match_rule = osm_qos_policy_match_rule_create();
}

/***************************************************
 ***************************************************/

static int __parser_match_rule_end()
{
    if (!p_current_qos_match_rule->qos_level_name)
    {
        yyerror("match-rule validation failed - no 'qos-level-name' specified");
        return -1;
    }

    cl_list_insert_tail(&p_qos_policy->qos_match_rules,
                        p_current_qos_match_rule);
    p_current_qos_match_rule = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_ulp_match_rule_start()
{
    p_current_qos_match_rule = osm_qos_policy_match_rule_create();
}

/***************************************************
 ***************************************************/

static int __parser_ulp_match_rule_end()
{
    CL_ASSERT(p_current_qos_match_rule->p_qos_level);
    cl_list_insert_tail(&__ulp_match_rules,
                        p_current_qos_match_rule);
    p_current_qos_match_rule = NULL;
    return 0;
}

/***************************************************
 ***************************************************/

static void __parser_tmp_struct_init()
{
    tmp_parser_struct.str[0] = '\0';
    cl_list_construct(&tmp_parser_struct.str_list);
    cl_list_init(&tmp_parser_struct.str_list, 10);
    cl_list_construct(&tmp_parser_struct.num_list);
    cl_list_init(&tmp_parser_struct.num_list, 10);
    cl_list_construct(&tmp_parser_struct.num_pair_list);
    cl_list_init(&tmp_parser_struct.num_pair_list, 10);
}

/***************************************************
 ***************************************************/

/*
 * Do NOT free objects from the temp struct.
 * Either they are inserted into the parse tree data
 * structure, or they are already freed when copying
 * their values to the parse tree data structure.
 */
static void __parser_tmp_struct_reset()
{
    tmp_parser_struct.str[0] = '\0';
    cl_list_remove_all(&tmp_parser_struct.str_list);
    cl_list_remove_all(&tmp_parser_struct.num_list);
    cl_list_remove_all(&tmp_parser_struct.num_pair_list);
}

/***************************************************
 ***************************************************/

static void __parser_tmp_struct_destroy()
{
    __parser_tmp_struct_reset();
    cl_list_destroy(&tmp_parser_struct.str_list);
    cl_list_destroy(&tmp_parser_struct.num_list);
    cl_list_destroy(&tmp_parser_struct.num_pair_list);
}

/***************************************************
 ***************************************************/

#define __SIMPLE_QOS_LEVEL_NAME "SimpleQoSLevel_SL"
#define __SIMPLE_QOS_LEVEL_DEFAULT_NAME "SimpleQoSLevel_DEFAULT"

static void __setup_simple_qos_levels()
{
    uint8_t i;
    char tmp_buf[30];
    memset(osm_qos_policy_simple_qos_levels, 0,
           sizeof(osm_qos_policy_simple_qos_levels));
    for (i = 0; i < 16; i++)
    {
        osm_qos_policy_simple_qos_levels[i].sl = i;
        osm_qos_policy_simple_qos_levels[i].sl_set = TRUE;
        sprintf(tmp_buf, "%s%u", __SIMPLE_QOS_LEVEL_NAME, i);
        osm_qos_policy_simple_qos_levels[i].name = strdup(tmp_buf);
    }

    memset(&__default_simple_qos_level, 0,
           sizeof(__default_simple_qos_level));
    __default_simple_qos_level.name =
           strdup(__SIMPLE_QOS_LEVEL_DEFAULT_NAME);
}

/***************************************************
 ***************************************************/

static void __clear_simple_qos_levels()
{
    /*
     * Simple QoS levels are static.
     * What's left is to invalidate default simple QoS level.
     */
    __default_simple_qos_level.sl_set = FALSE;
}

/***************************************************
 ***************************************************/

static void __setup_ulp_match_rules()
{
    cl_list_construct(&__ulp_match_rules);
    cl_list_init(&__ulp_match_rules, 10);
}

/***************************************************
 ***************************************************/

static void __process_ulp_match_rules()
{
    cl_list_iterator_t list_iterator;
    osm_qos_match_rule_t *p_qos_match_rule = NULL;

    list_iterator = cl_list_head(&__ulp_match_rules);
    while (list_iterator != cl_list_end(&__ulp_match_rules))
    {
        p_qos_match_rule = (osm_qos_match_rule_t *) cl_list_obj(list_iterator);
        if (p_qos_match_rule)
            cl_list_insert_tail(&p_qos_policy->qos_match_rules,
                                p_qos_match_rule);
        list_iterator = cl_list_next(list_iterator);
    }
    cl_list_remove_all(&__ulp_match_rules);
}

/***************************************************
 ***************************************************/

static int __cmp_num_range(const void * p1, const void * p2)
{
    uint64_t * pair1 = *((uint64_t **)p1);
    uint64_t * pair2 = *((uint64_t **)p2);

    if (pair1[0] < pair2[0])
        return -1;
    if (pair1[0] > pair2[0])
        return 1;

    if (pair1[1] < pair2[1])
        return -1;
    if (pair1[1] > pair2[1])
        return 1;

    return 0;
}

/***************************************************
 ***************************************************/

static void __sort_reduce_rangearr(
    uint64_t  **   arr,
    unsigned       arr_len,
    uint64_t  ** * p_res_arr,
    unsigned     * p_res_arr_len )
{
    unsigned i = 0;
    unsigned j = 0;
    unsigned last_valid_ind = 0;
    unsigned valid_cnt = 0;
    uint64_t ** res_arr;
    boolean_t * is_valid_arr;

    *p_res_arr = NULL;
    *p_res_arr_len = 0;

    qsort(arr, arr_len, sizeof(uint64_t*), __cmp_num_range);

    is_valid_arr = (boolean_t *)malloc(arr_len * sizeof(boolean_t));
    is_valid_arr[last_valid_ind] = TRUE;
    valid_cnt++;
    for (i = 1; i < arr_len; i++)
    {
        if (arr[i][0] <= arr[last_valid_ind][1])
        {
            if (arr[i][1] > arr[last_valid_ind][1])
                arr[last_valid_ind][1] = arr[i][1];
            free(arr[i]);
            arr[i] = NULL;
            is_valid_arr[i] = FALSE;
        }
        else if ((arr[i][0] - 1) == arr[last_valid_ind][1])
        {
            arr[last_valid_ind][1] = arr[i][1];
            free(arr[i]);
            arr[i] = NULL;
            is_valid_arr[i] = FALSE;
        }
        else
        {
            is_valid_arr[i] = TRUE;
            last_valid_ind = i;
            valid_cnt++;
        }
    }

    res_arr = (uint64_t **)malloc(valid_cnt * sizeof(uint64_t *));
    for (i = 0; i < arr_len; i++)
    {
        if (is_valid_arr[i])
            res_arr[j++] = arr[i];
    }
    free(is_valid_arr);
    free(arr);

    *p_res_arr = res_arr;
    *p_res_arr_len = valid_cnt;
}

/***************************************************
 ***************************************************/

static void __pkey_rangelist2rangearr(
    cl_list_t    * p_list,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len)
{
    uint64_t   tmp_pkey;
    uint64_t * p_pkeys;
    cl_list_iterator_t list_iterator;

    list_iterator= cl_list_head(p_list);
    while( list_iterator != cl_list_end(p_list) )
    {
       p_pkeys = (uint64_t *)cl_list_obj(list_iterator);
       p_pkeys[0] &= 0x7fff;
       p_pkeys[1] &= 0x7fff;
       if (p_pkeys[0] > p_pkeys[1])
       {
           tmp_pkey = p_pkeys[1];
           p_pkeys[1] = p_pkeys[0];
           p_pkeys[0] = tmp_pkey;
       }
       list_iterator = cl_list_next(list_iterator);
    }

    __rangelist2rangearr(p_list, p_arr, p_arr_len);
}

/***************************************************
 ***************************************************/

static void __rangelist2rangearr(
    cl_list_t    * p_list,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len)
{
    cl_list_iterator_t list_iterator;
    unsigned len = cl_list_count(p_list);
    unsigned i = 0;
    uint64_t ** tmp_arr;
    uint64_t ** res_arr = NULL;
    unsigned res_arr_len = 0;

    tmp_arr = (uint64_t **)malloc(len * sizeof(uint64_t *));

    list_iterator = cl_list_head(p_list);
    while( list_iterator != cl_list_end(p_list) )
    {
       tmp_arr[i++] = (uint64_t *)cl_list_obj(list_iterator);
       list_iterator = cl_list_next(list_iterator);
    }
    cl_list_remove_all(p_list);

    __sort_reduce_rangearr( tmp_arr,
                            len,
                            &res_arr,
                            &res_arr_len );
    *p_arr = res_arr;
    *p_arr_len = res_arr_len;
}

/***************************************************
 ***************************************************/

static void __merge_rangearr(
    uint64_t  **   range_arr_1,
    unsigned       range_len_1,
    uint64_t  **   range_arr_2,
    unsigned       range_len_2,
    uint64_t  ** * p_arr,
    unsigned     * p_arr_len )
{
    unsigned i = 0;
    unsigned j = 0;
    unsigned len = range_len_1 + range_len_2;
    uint64_t ** tmp_arr;
    uint64_t ** res_arr = NULL;
    unsigned res_arr_len = 0;

    *p_arr = NULL;
    *p_arr_len = 0;

    tmp_arr = (uint64_t **)malloc(len * sizeof(uint64_t *));

    for (i = 0; i < range_len_1; i++)
       tmp_arr[j++] = range_arr_1[i];
    for (i = 0; i < range_len_2; i++)
       tmp_arr[j++] = range_arr_2[i];
    free(range_arr_1);
    free(range_arr_2);

    __sort_reduce_rangearr( tmp_arr,
                            len,
                            &res_arr,
                            &res_arr_len );
    *p_arr = res_arr;
    *p_arr_len = res_arr_len;
}

/***************************************************
 ***************************************************/

static void __parser_add_port_to_port_map(
    cl_qmap_t   * p_map,
    osm_physp_t * p_physp)
{
    if (cl_qmap_get(p_map, cl_ntoh64(osm_physp_get_port_guid(p_physp))) ==
        cl_qmap_end(p_map))
    {
        osm_qos_port_t * p_port = osm_qos_policy_port_create(p_physp);
        if (p_port)
            cl_qmap_insert(p_map,
                           cl_ntoh64(osm_physp_get_port_guid(p_physp)),
                           &p_port->map_item);
    }
}

/***************************************************
 ***************************************************/

static void __parser_add_guid_range_to_port_map(
    cl_qmap_t  * p_map,
    uint64_t  ** range_arr,
    unsigned     range_len)
{
    unsigned i;
    uint64_t guid_ho;
    osm_port_t * p_osm_port;

    if (!range_arr || !range_len)
        return;

    for (i = 0; i < range_len; i++) {
         for (guid_ho = range_arr[i][0]; guid_ho <= range_arr[i][1]; guid_ho++) {
             p_osm_port =
                osm_get_port_by_guid(p_qos_policy->p_subn, cl_hton64(guid_ho));
             if (p_osm_port)
                 __parser_add_port_to_port_map(p_map, p_osm_port->p_physp);
         }
         free(range_arr[i]);
    }
    free(range_arr);
}

/***************************************************
 ***************************************************/

static void __parser_add_pkey_range_to_port_map(
    cl_qmap_t  * p_map,
    uint64_t  ** range_arr,
    unsigned     range_len)
{
    unsigned i;
    uint64_t pkey_64;
    ib_net16_t pkey;
    osm_prtn_t * p_prtn;

    if (!range_arr || !range_len)
        return;

    for (i = 0; i < range_len; i++) {
         for (pkey_64 = range_arr[i][0]; pkey_64 <= range_arr[i][1]; pkey_64++) {
             pkey = cl_hton16((uint16_t)(pkey_64 & 0x7fff));
             p_prtn = (osm_prtn_t *)
                 cl_qmap_get(&p_qos_policy->p_subn->prtn_pkey_tbl, pkey);
             if (p_prtn != (osm_prtn_t *)cl_qmap_end(
                   &p_qos_policy->p_subn->prtn_pkey_tbl)) {
                 __parser_add_map_to_port_map(p_map, &p_prtn->part_guid_tbl);
                 __parser_add_map_to_port_map(p_map, &p_prtn->full_guid_tbl);
             }
         }
         free(range_arr[i]);
    }
    free(range_arr);
}

/***************************************************
 ***************************************************/

static void __parser_add_partition_list_to_port_map(
    cl_qmap_t  * p_map,
    cl_list_t  * p_list)
{
    cl_list_iterator_t    list_iterator;
    char                * tmp_str;
    osm_prtn_t          * p_prtn;

    /* extract all the ports from the partition
       to the port map of this port group */
    list_iterator = cl_list_head(p_list);
    while(list_iterator != cl_list_end(p_list)) {
        tmp_str = (char*)cl_list_obj(list_iterator);
        if (tmp_str) {
            p_prtn = osm_prtn_find_by_name(p_qos_policy->p_subn, tmp_str);
            if (p_prtn) {
                __parser_add_map_to_port_map(p_map, &p_prtn->part_guid_tbl);
                __parser_add_map_to_port_map(p_map, &p_prtn->full_guid_tbl);
            }
            free(tmp_str);
        }
        list_iterator = cl_list_next(list_iterator);
    }
    cl_list_remove_all(p_list);
}

/***************************************************
 ***************************************************/

static void __parser_add_map_to_port_map(
    cl_qmap_t * p_dmap,
    cl_map_t  * p_smap)
{
    cl_map_iterator_t map_iterator;
    osm_physp_t * p_physp;

    if (!p_dmap || !p_smap)
        return;

    map_iterator = cl_map_head(p_smap);
    while (map_iterator != cl_map_end(p_smap)) {
        p_physp = (osm_physp_t*)cl_map_obj(map_iterator);
        __parser_add_port_to_port_map(p_dmap, p_physp);
        map_iterator = cl_map_next(map_iterator);
    }
}

/***************************************************
 ***************************************************/

static int __validate_pkeys( uint64_t ** range_arr,
                             unsigned    range_len,
                             boolean_t   is_ipoib)
{
    unsigned i;
    uint64_t pkey_64;
    ib_net16_t pkey;
    osm_prtn_t * p_prtn;

    if (!range_arr || !range_len)
        return 0;

    for (i = 0; i < range_len; i++) {
        for (pkey_64 = range_arr[i][0]; pkey_64 <= range_arr[i][1]; pkey_64++) {
            pkey = cl_hton16((uint16_t)(pkey_64 & 0x7fff));
            p_prtn = (osm_prtn_t *)
                cl_qmap_get(&p_qos_policy->p_subn->prtn_pkey_tbl, pkey);

            if (p_prtn == (osm_prtn_t *)cl_qmap_end(
                  &p_qos_policy->p_subn->prtn_pkey_tbl))
                p_prtn = NULL;

            if (is_ipoib) {
                /*
                 * Be very strict for IPoIB partition:
                 *  - the partition for the pkey have to exist
                 *  - it has to have at least 2 full members
                 */
                if (!p_prtn) {
                    yyerror("IPoIB partition, pkey 0x%04X - "
                                       "partition doesn't exist",
                                       cl_ntoh16(pkey));
                    return 1;
                }
                else if (cl_map_count(&p_prtn->full_guid_tbl) < 2) {
                    yyerror("IPoIB partition, pkey 0x%04X - "
                                       "partition has less than two full members",
                                       cl_ntoh16(pkey));
                    return 1;
                }
            }
            else if (!p_prtn) {
                /*
                 * For non-IPoIB pkey we just want to check that
                 * the relevant partition exists.
                 * And even if it doesn't, don't exit - just print
                 * error message and continue.
                 */
                 OSM_LOG(p_qos_parser_osm_log, OSM_LOG_ERROR, "ERR AC02: "
			 "pkey 0x%04X - partition doesn't exist",
                         cl_ntoh16(pkey));
            }
        }
    }
    return 0;
}

/***************************************************
 ***************************************************/

