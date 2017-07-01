using namespace std;

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class DbCrudGen {
    int version = 2;
public:
    DbCrudGen(int version) : version{version} {}

    int getVersion() const { return version; }
};

TEST(DbCrudGenTest, TestVersion) {
    DbCrudGen dbCrudGen{2};
    EXPECT_EQ(dbCrudGen.getVersion(), 2);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}