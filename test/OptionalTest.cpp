//
// Created by William Zeh on 3/1/23.
//

#include <optional>
#include <gtest/gtest.h>

class OptionalTest : public ::testing::Test
{
public:
    void SetUp() override
    {

    }

    bool isOptValid(std::optional<std::reference_wrapper<std::string>> strOutOpt = std::nullopt)
    {
        if (strOutOpt)
        {
            auto& str = strOutOpt->get();
            str = valid_;
            return true;
        }
        return false;
    }

    bool isPtrValid(std::string* strOut = nullptr)
    {
        if (strOut)
        {
            *strOut = valid_;
            return true;
        }
        return false;
    }

private:
    std::string valid_ {"valid"};
};

TEST_F(OptionalTest, testStdOptionOutParam)
{
    std::string validStr;
    auto valid = isOptValid(validStr);
    EXPECT_TRUE(valid);
    EXPECT_EQ("valid", validStr);
}

TEST_F(OptionalTest, testPointOutParam)
{
    std::string validStr;
    auto valid = isPtrValid(&validStr);
    EXPECT_TRUE(valid);
    EXPECT_EQ("valid", validStr);
}

TEST_F(OptionalTest, testIgnoreOutParam)
{
    EXPECT_FALSE(isOptValid());
    EXPECT_FALSE(isPtrValid());
}
