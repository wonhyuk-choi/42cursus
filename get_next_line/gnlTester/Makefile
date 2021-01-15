TIMEOUT_US				= 400000

.DEFAULT_GOAL			= va
UTILS					= utils/sigsegv.cpp utils/color.cpp utils/check.cpp utils/gnl.cpp
TESTS_PATH				= tests/
SHELL					= bash


MANDATORY_HEADER		= ../get_next_line.h
MANDATORY_FILES			= ../get_next_line.c ../get_next_line_utils.c
MANDATORY_OBJS			= $(MANDATORY_FILES:../%.c=%.o)

MANDATORY				= mandatory
1MANDATORY				= $(addprefix 1, $(MANDATORY))
42MANDATORY				= $(addprefix 42, $(MANDATORY))
10MMANDATORY			= $(addprefix 10M, $(MANDATORY))

V1MANDATORY				= $(addprefix v1, $(MANDATORY))
V42MANDATORY			= $(addprefix v42, $(MANDATORY))
V10MMANDATORY			= $(addprefix v10M, $(MANDATORY))


BONUS_HEADER			= ../get_next_line_bonus.h
BONUS_FILES				= ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
BONUS_OBJS				= $(BONUS_FILES:../%.c=%.o)

BONUS					= bonus
1BONUS					= $(addprefix 1, $(BONUS))
42BONUS					= $(addprefix 42, $(BONUS))
10MBONUS				= $(addprefix 10M, $(BONUS))

V1BONUS					= $(addprefix v1, $(BONUS))
V42BONUS				= $(addprefix v42, $(BONUS))
V10MBONUS				= $(addprefix v10M, $(BONUS))

1MBONUS					= $(addprefix m1, $(BONUS))
42MBONUS				= $(addprefix m42, $(BONUS))
10MMBONUS				= $(addprefix m10M, $(BONUS))

V1MBONUS				= $(addprefix vm1, $(BONUS))
V42MBONUS				= $(addprefix vm42, $(BONUS))
V10MMBONUS				= $(addprefix vm10M, $(BONUS))

CFLAGS					= -Wall -Wextra -Werror
CPPFLAGS				= -g3 -std=c++11 -I utils/ -I.. -Wno-everything
VALGRIND				= valgrind -q --leak-check=full --show-reachable=yes

$(1MANDATORY): 1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(42MANDATORY): 42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(10MMANDATORY): 10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest

$(V1MANDATORY): v1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V42MANDATORY): v42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V10MMANDATORY): v10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(MANDATORY_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(MANDATORY_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest


$(1MBONUS): m1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(42MBONUS): m42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(10MMBONUS): m10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest

$(1BONUS): 1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(42BONUS): 42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(10MBONUS): 10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest

$(V1MBONUS): vm1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V42MBONUS): vm42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V10MMBONUS): vm10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$(MANDATORY).cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest

$(V1BONUS): v1%:
	@gcc -D BUFFER_SIZE=1 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=1 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V42BONUS): v42%:
	@gcc -D BUFFER_SIZE=42 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=42 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest
$(V10MBONUS): v10M%:
	@gcc -D BUFFER_SIZE=10000000 $(CFLAGS) -c $(BONUS_FILES)
	@clang++ -D BUFFER_SIZE=10000000 -D TIMEOUT_US=$(TIMEOUT_US) $(CPPFLAGS) $(UTILS) $(TESTS_PATH)$*.cpp $(BONUS_OBJS) -o gnlTest && $(VALGRIND) ./gnlTest < files/alternate_line_nl_with_nl && rm -f gnlTest

mandatory_start: update
	@tput setaf 4 && echo [Mandatory]

bonus_start: update
	@tput setaf 3 && printf "[Static = " && cat ../*bonus* | grep static | wc -l | tr -d '\n' | xargs /bin/echo -n && printf "]\n"
	@tput setaf 5 && /bin/echo [Bonus]

update:
	@git pull

m: mandatory_start $(1MANDATORY) $(42MANDATORY) $(10MMANDATORY) cleanMandatory
b: bonus_start $(1MBONUS) $(42MBONUS) $(10MMBONUS) $(1BONUS) $(42BONUS) $(10MBONUS) cleanBonus
a: m b

vm: mandatory_start $(V1MANDATORY) $(V42MANDATORY) $(V10MMANDATORY) cleanMandatory
vb: bonus_start $(V1MBONUS) $(V42MBONUS) $(V10MMBONUS) $(V1BONUS) $(V42BONUS) $(V10MBONUS) cleanBonus
va: vm vb

clean cleanMandatory cleanBonus:
	@rm -rf $(MANDATORY_OBJS) $(BONUS_OBJS) gnlTest

.PHONY:	mandatory_start m vm bonus_start b vb a va clean cleanMandatory cleanBonus