#include <iostream>


using namespace std;

//TODO - Read this http://www.oracle.com/technetwork/topics/linuxx86-64soft-092277.html
int main(int argc, char *argv[]) {
    Environment *env = Environment::createEnvironment();
    Connection *conn = env->createConnection("HR", "password");
    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);
    return 0;
}