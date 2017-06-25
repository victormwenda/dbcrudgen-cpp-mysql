#include <iostream>
#include "core/cli/CliParser.h"
#include "core/database/schemas/DatabaseSchemas.h"
#include "lang/parser/java/JavaLangTemplateParser.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    std::string model = "${CLASSNAME} . . 1 ${METHOD_NAME} . . 6 ${JAVA} . . 7.. ${JAVA}. . 9 ";
    JavaLangTemplateParser javaLangTemplateParser{model};

    std::string tag1 = "${CLASSNAME}";
    std::string tag2 = "${METHOD_NAME}";
    std::string tag3 = "${JAVA}";

    std::string value1 = "Foo";
    std::string value2 = "foo";
    std::string value3 = "bar";



    string newData = javaLangTemplateParser
    .parse(tag1, value1)
    .parse(tag2, value2)
    .parse(tag3, value3)
            .getTemplate();


    cout << newData << endl;

    return 0;
}