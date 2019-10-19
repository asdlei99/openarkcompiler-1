/*
 * Copyright (c) [2019] Huawei Technologies Co.,Ltd.All rights reserved.
 *
 * OpenArkCompiler is licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *
 *     http://license.coscl.org.cn/MulanPSL
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
 * FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v1 for more details.
 */
#ifndef MAPLE_DRIVER_INCLUDE_USAGES_H
#define MAPLE_DRIVER_INCLUDE_USAGES_H

namespace maple {
enum OptionIndex {
  kUnknown,
  kHelp,
  kVersion,
  kInFile,
  kInMplt,
  kOptimization0,
  kSaveTemps,
  kRun,
  kOption,
  kAllDebug,
  // ----------jbc2mpl begin-------
  kUseStringFactory,
  kJbc2mplOutMpl,
  //-------- comb begin-------- --
  kCombTimePhases,
  kGenMeMpl,
  kGenVtableImpl,
  //----------me begin-----------
  kMeHelp,
  kMeDumpPhases,
  kMeSkipPhases,
  kMeDumpFunc,
  kMeQuiet,
  kMeNoDot,
  kSetCalleeHasSideEffect,
  kNoSteensgaard,
  kNoTBAA,
  kAliasAnalysisLevel,
  kStmtNum,
  kMeDumpAfter,
  kMeRange,
  kLessThrowAlias,
  kFinalFieldAlias,
  kRegReadAtReturn,
  //----------mpl2mpl begin---------
  kMpl2MplHelp,
  kMpl2MplDumpPhase,
  kMpl2MplSkipPhase,
  kMpl2MplSkipFrom,
  kMpl2MplSkipAfter,
  kMpl2MplDumpFunc,
  kMpl2MplQuiet,
  kMpl2MplStubJniFunc,
  kMpl2MplSkipVirtual,
  kRegNativeDynamicOnly,
  kRegNativeStaticBindingList,
  kNativeWrapper,
  kMpl2MplDumpBefore,
  kMpl2MplDumpAfter,
  kMpl2MplMapleLinker,
  kMplnkDumpMuid,
  kEmitVtableImpl,
  //----------mplcg begin---------
  kCGQuiet,
  kPie,
  kPic,
  kVerbose,
  kCGMapleLinker,
};

enum EnabledIndex { kDisable, kEnable };

const static mapleOption::Descriptor USAGES[] = {
  // index, type , shortOption , longOption, connector, isCanAppend, delimiter, enableBuildType, checkPolicy, help,
  // extra
  { kUnknown,
    0,
    nullptr,
    nullptr,
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "USAGE: maple [options]\n\n Options:",
    "all",
    { { nullptr } } },
  { kHelp,
    0,
    "h",
    "help",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyOptional,
    "  -h --help [command]         \tPrint usage and exit.\n",
    "all",
    { { nullptr } } },
  { kVersion,
    0,
    nullptr,
    "version",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyOptional,
    "  --version [command]         \tPrint version and exit.\n",
    "all",
    { { nullptr } } },
  { kInFile,
    0,
    nullptr,
    "infile",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --infile file1,file2,file3  \tInput files.\n",
    "all",
    { { nullptr } } },
  { kInMplt,
    0,
    nullptr,
    "mplt",
    "=",
    true,
    ",",
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --mplt=file1,file2,file3    \tImport mplt files.\n",
    "all",
    { { "jbc2mpl", "-mplt", " ", nullptr },
      // End
      { nullptr, nullptr, nullptr, nullptr } } },
  { kOptimization0,
    0,
    "O0",
    nullptr,
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  -O0                         \tNo optimization.\n",
    "all",
    { { nullptr } } },
  { kSaveTemps,
    0,
    nullptr,
    "save-temps",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --save-temps                \tDo not delete intermediate files.\n"
    "                              \t--save-temps Save all intermediate files.\n"
    "                              \t--save-temps=file1,file2,file3 Save the\n"
    "                              \ttarget files.\n",
    "all",
    { { nullptr } } },
  { kRun,
    0,
    nullptr,
    "run",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeDebug,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --run=cmd1:cmd2             \tThe name of executables that are going\n"
    "                              \tto execute. IN SEQUENCE.\n"
    "                              \tSeparated by \":\".Available exe names:\n"
    "                              \tjbc2mpl, me, mpl2mpl, mplcg\n"
    "                              \tInput file must match the tool can\n"
    "                              \thandle\n",
    "all",
    { { nullptr } } },
  { kOption,
    0,
    nullptr,
    "option",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeDebug,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --option=\"opt1:opt2\"      \tOptions for each executable,\n"
    "                              \tseparated by \":\".\n"
    "                              \tThe sequence must match the sequence in\n"
    "                              \t--run.\n",
    "all",
    { { nullptr } } },
  { kCombTimePhases,
    0,
    "time-phases",
    nullptr,
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  -time-phases                \tTiming phases and print percentages\n",
    "all",
    { { nullptr } } },
  { kGenMeMpl,
    0,
    nullptr,
    "genmempl",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --genmempl                  \tGenerate me.mpl file\n",
    "all",
    { { nullptr } } },
  { kGenVtableImpl,
    0,
    nullptr,
    "genVtableImpl",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --genVtableImpl             \tGenerate VtableImpl.mpl file\n",
    "all",
    { { nullptr } } },
  { kAllDebug,
    0,
    nullptr,
    "debug",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --debug                     \tPrint debug info.\n",
    "all",
    { { nullptr } } },
  // jbc2mpl
  { kUseStringFactory,
    0,
    nullptr,
    "use-string-factory",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  -use-string-factory         \tReplace String.<init> by StringFactory call\n",
    "jbc2mpl",
    { { nullptr } } },
  { kJbc2mplOutMpl,
    0,
    "o",
    "out",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeDebug,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  -o, -out=output.mpl         \toutput mpl name\n",
    "jbc2mpl",
    { { nullptr } } },
  // me
  { kMeHelp,
    0,
    "h-me",
    "help-me",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyOptional,
    "  -h-me --help-me             \tPrint usage and exit.Available command names:\n"
    "                              \tme\n",
    "all",
    { { nullptr } } },
  { kMeRange,
    0,
    nullptr,
    "range",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --range                     \tOptimize only functions in the range [NUM0, NUM1]\n"
    "                              \t--range=NUM0,NUM1\n",
    "me",
    { { nullptr } } },
  { kMeDumpPhases,
    0,
    nullptr,
    "dump-phases",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --dump-phases               \tEnable debug trace for specified phases in the comma separated list\n"
    "                              \t--dump-phases=PHASENAME,...\n",
    "me",
    { { nullptr } } },
  { kMeSkipPhases,
    0,
    nullptr,
    "skip-phases",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --skip-phases               \tSkip the phases specified in the comma separated list\n"
    "                              \t--skip-phases=PHASENAME,...\n",
    "me",
    { { nullptr } } },
  { kMeDumpFunc,
    0,
    nullptr,
    "dump-func",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --dump-func                 \tDump/trace only for functions whose names contain FUNCNAME as substring\n"
    "                              \t(can only specify once)\n"
    "                              \t--dump-func=FUNCNAME\n",
    "me",
    { { nullptr } } },
  { kMeQuiet,
    0,
    nullptr,
    "quiet",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --quiet                     \tDisable brief trace messages with phase/function names\n",
    "me",
    { { nullptr } } },
  { kMeNoDot,
    0,
    nullptr,
    "nodot",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --nodot                     \tDisable dot file generation from cfg\n",
    "me",
    { { nullptr } } },
  { kSetCalleeHasSideEffect,
    0,
    nullptr,
    "setCalleeHasSideEffect",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --setCalleeHasSideEffect    \tSet all the callees have side effect\n",
    "me",
    { { nullptr } } },
  { kNoSteensgaard,
    0,
    nullptr,
    "noSteensgaard",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --noSteensgaard             \tDisable Steensgaard-style alias analysis\n",
    "me",
    { { nullptr } } },
  { kNoTBAA,
    0,
    nullptr,
    "noTBAA",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --noTBAA                    \tDisable type-based alias analysis\n",
    "me",
    { { nullptr } } },
  { kAliasAnalysisLevel,
    0,
    nullptr,
    "aliasAnalysisLevel",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --aliasAnalysisLevel        \tSet level of alias analysis. \n"
    "                              \t0: most conservative;\n"
    "                              \t1: Steensgaard-style alias analysis; 2: type-based alias analysis;\n"
    "                              \t3: Steensgaard-style and type-based alias analysis\n"
    "                              \t--aliasAnalysisLevel=NUM\n",
    "me",
    { { nullptr } } },
  { kStmtNum,
    0,
    nullptr,
    "stmtnum",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --stmtnum                   \tPrint MeStmt index number in IR dump\n",
    "me",
    { { nullptr } } },
  { kMeDumpAfter,
    0,
    nullptr,
    "dump-after",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --dump-after                \tDo extra IR dump after the specified phase in me\n",
    "me",
    { { nullptr } } },
  { kLessThrowAlias,
    0,
    nullptr,
    "lessthrowalias",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --lessthrowalias            \tHandle aliases at java throw statements more accurately\n",
    "me",
    { { nullptr } } },
  { kFinalFieldAlias,
    0,
    nullptr,
    "finalfieldalias",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --finalfieldalias           \tRegard final fields as having alias like other fields\n",
    "me",
    { { nullptr } } },
  { kRegReadAtReturn,
    0,
    nullptr,
    "regreadatreturn",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --regreadatreturn           \tAllow register promotion to promote the operand of return statements\n",
    "me",
    { { nullptr } } },
  // mpl2mpl
  { kMpl2MplHelp,
    0,
    "h-mpl2mpl",
    "help-mpl2mpl",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyOptional,
    "  -h-mpl2mpl --help-mpl2mpl   \tPrint usage and exit.Available command names:\n"
    "                              \tmpl2mpl\n",
    "all",
    { { nullptr } } },
  { kMpl2MplDumpPhase,
    0,
    nullptr,
    "dump-phase",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --dump-phase                \tEnable debug trace for specified phase (can only specify once)\n"
    "                              \t--dump-phase=PHASENAME\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplSkipPhase,
    0,
    nullptr,
    "skip-phase",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --skip-phase                \tSkip the phase when adding it to phase manager\n"
    "                              \t--skip-phase=PHASENAME\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplSkipFrom,
    0,
    nullptr,
    "skip-from",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --skip-from                 \tSkip all remaining phases including PHASENAME\n"
    "                              \t--skip-from=PHASENAME\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplSkipAfter,
    0,
    nullptr,
    "skip-after",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --skip-after                \tSkip all remaining phases after PHASENAME\n"
    "                              \t--skip-after=PHASENAME\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplDumpFunc,
    0,
    nullptr,
    "dump-func",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --dump-func                 \tDump/trace only for functions whose names contain FUNCNAME as substring\n"
    "                              \t(can only specify once)\n"
    "                              \t--dump-func=FUNCNAME\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplQuiet,
    0,
    nullptr,
    "quiet",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --quiet                     \tDisable brief trace messages with phase/function names\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplMapleLinker,
    0,
    nullptr,
    "maplelinker",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --maplelinker               \tGenerate MUID symbol tables and references\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplStubJniFunc,
    0,
    nullptr,
    "regnativefunc",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --regnativefunc             \tGenerate native stub function to support JNI registration and calling\n",
    "mpl2mpl",
    { { nullptr } } },
  { kNativeWrapper,
    kEnable,
    nullptr,
    "nativewrapper",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --nativewrapper             \tGenerate native wrappers [default]\n",
    "mpl2mpl",
    { { nullptr } } },
  { kNativeWrapper,
    kDisable,
    nullptr,
    "no-nativewrapper",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --no-nativewrapper\n",
    "mpl2mpl",
    { { nullptr } } },
  { kRegNativeDynamicOnly,
    0,
    nullptr,
    "regnative-dynamic-only",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --regnative-dynamic-only    \tOnly Generate dynamic register code, Report Fatal Msg if no implemented\n",
    "mpl2mpl",
    { { nullptr } } },
  { kRegNativeStaticBindingList,
    0,
    nullptr,
    "static-binding-list",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyRequired,
    "  --static-bindig-list        \tOnly Generate static binding function in file configure list\n"
    "                              \t--static-bindig-list=file\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplDumpBefore,
    0,
    nullptr,
    "dump-before",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --dump-before               \tDo extra IR dump before the specified phase\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMpl2MplDumpAfter,
    0,
    nullptr,
    "dump-after",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --dump-after                \tDo extra IR dump after the specified phase\n",
    "mpl2mpl",
    { { nullptr } } },
  { kMplnkDumpMuid,
    0,
    nullptr,
    "dump-muid",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --dump-muid                 \tDump MUID def information into a .muid file\n",
    "mpl2mpl",
    { { nullptr } } },
  { kEmitVtableImpl,
    0,
    nullptr,
    "emitVtableImpl",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --emitVtableImpl            \tgenerate VtableImpl file\n",
    "mpl2mpl",
    { { nullptr } } },
#if MIR_JAVA
  { kMpl2MplSkipVirtual,
    0,
    nullptr,
    "skipvirtual",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --skipvirtual\n",
    "mpl2mpl",
    { { nullptr } } },
#endif
  // mplcg
  { kPie,
    kEnable,
    nullptr,
    "pie",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --pie                       \tGenerate position-independent executable\n",
    "mplcg",
    { { nullptr } } },
  { kPie,
    kDisable,
    nullptr,
    "no-pie",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --no-pie\n",
    "mplcg",
    { { nullptr } } },
  { kPic,
    kEnable,
    nullptr,
    "fpic",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --fpic                      \tGenerate position-independent shared library\n",
    "mplcg",
    { { nullptr } } },
  { kPic,
    kDisable,
    nullptr,
    "no-fpic",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --no-fpic\n",
    "mplcg",
    { { nullptr } } },
  { kVerbose,
    kEnable,
    nullptr,
    "verbose-asm",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --verbose-asm               \tAdd comments to asm output\n",
    "mplcg",
    { { nullptr } } },
  { kVerbose,
    kDisable,
    nullptr,
    "no-verbose-asm",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --no-verbose-asm\n",
    "mplcg",
    { { nullptr } } },
  { kCGMapleLinker,
    kEnable,
    nullptr,
    "maplelinker",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --maplelinker               \tGenerate the MapleLinker .s format\n",
    "mplcg",
    { { nullptr } } },
  { kCGQuiet,
    kEnable,
    nullptr,
    "quiet",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --quiet                     \tBe quiet (don't output debug messages)\n",
    "mplcg",
    { { nullptr } } },
  { kCGQuiet,
    kDisable,
    nullptr,
    "no-quiet",
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    "  --no-quiet\n",
    "mplcg",
    { { nullptr } } },
  // End

  { kUnknown,
    0,
    nullptr,
    nullptr,
    nullptr,
    false,
    nullptr,
    mapleOption::BuildType::kBuildTypeAll,
    mapleOption::ArgCheckPolicy::kArgCheckPolicyNone,
    nullptr,
    "",
    { { nullptr } } }
};

}  // namespace maple
#endif  // MAPLE_DRIVER_INCLUDE_USAGES_H
