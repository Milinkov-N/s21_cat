#include <gtest/gtest.h>

#include "s21_cat.h"

TEST(CatLib, ReadFileValid) {
  char* contents = nullptr;
  size_t bytes_read = read_file("test.txt", contents);
  ASSERT_EQ(bytes_read, 55);
}

TEST(CatLib, ReadFileInvalid) {
  char* contents = nullptr;
  size_t bytes_read = read_file("non.exists.totally", contents);
  ASSERT_EQ(bytes_read, 0);
}

TEST(CatLib, IsOptShort) {
  bool_t res = is_opt("-b");
  ASSERT_TRUE((bool)res);
}

TEST(CatLib, IsOptLong) {
  bool_t res = is_opt("--squeeze-blank");
  ASSERT_TRUE((bool)res);
}

TEST(CatLib, IsOptInvalid) {
  bool_t res = is_opt("not-an-option");
  ASSERT_FALSE((bool)res);
}

TEST(CatLib, IsLongOptValid) {
  bool_t res = is_longopt("--squeeze-blank");
  ASSERT_TRUE((bool)res);
}

TEST(CatLib, IsLongOptShortOption) {
  bool_t res = is_longopt("-n");
  ASSERT_FALSE((bool)res);
}

TEST(CatLib, IsLongOptNotAnOption) {
  bool_t res = is_longopt("not-an-option");
  ASSERT_FALSE((bool)res);
}

TEST(CatLib, IsShortOptValid) {
  bool_t res = is_shortopt("-n");
  ASSERT_TRUE((bool)res);
}

TEST(CatLib, IsShortOptLongOption) {
  bool_t res = is_shortopt("--squeeze-blank");
  ASSERT_FALSE((bool)res);
}

TEST(CatLib, IsShortOptNotAnOption) {
  bool_t res = is_shortopt("not-an-option");
  ASSERT_FALSE((bool)res);
}

TEST(CatLib, ShortOptLookupValid) {
  int valid_options[] = {'b', 'e', 'n', 's', 't', 'v'};
  ASSERT_EQ(OPT_NUM_NONBLANK, shortopt_lookup(valid_options[0]));
  ASSERT_EQ(OPT_MARK_EOL, shortopt_lookup(valid_options[1]));
  ASSERT_EQ(OPT_NUM_ALL, shortopt_lookup(valid_options[2]));
  ASSERT_EQ(OPT_SQUEEZE_BLANK, shortopt_lookup(valid_options[3]));
  ASSERT_EQ(OPT_MARK_TABS, shortopt_lookup(valid_options[4]));
  ASSERT_EQ(OPT_MARK_NONPRINTABLE, shortopt_lookup(valid_options[5]));
}

TEST(CatLib, ShortOptLookupInvalid) {
  for (int i = 0; i != 255; ++i) {
    if (i == (int)'b' || i == (int)'e' || i == (int)'n' || i == (int)'s' ||
        i == (int)'t' || i == (int)'v')
      continue;
    ASSERT_EQ(OPT_INVLAID, shortopt_lookup((char)i));
  }
}

TEST(CatLib, LongOptLookupValid) {
  ASSERT_EQ(OPT_NUM_NONBLANK, longopt_lookup("number-nonblank"));
  ASSERT_EQ(OPT_NUM_ALL, longopt_lookup("number"));
  ASSERT_EQ(OPT_SQUEEZE_BLANK, longopt_lookup("squeeze-blank"));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
