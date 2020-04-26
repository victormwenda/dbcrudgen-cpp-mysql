//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_FRAMEWORKS_H
#define DBCRUDGEN_CPP_FRAMEWORKS_H
namespace dbcrudgen {
    namespace orm {

        class Frameworks {

        public:

            struct Android {
                static constexpr const char *Java = "Java";
                static constexpr const char *Kotlin = "Kotlin";
            };
            struct iOs {
                static constexpr const char *IOS = "OBJECTIVE-C";
                static constexpr const char *SWIFT = "SWIFT";
            };
            struct Java {
                static constexpr const char *CORE = "Java-Core";
                static constexpr const char *JAX_RS = "JaxRs";
                static constexpr const char *JAX_WS = "JaxWs";
                static constexpr const char *SPRING = "Spring";
                static constexpr const char *SPRING_BOOT = "Spring-boot";
            };
            struct JavaScript {
                static constexpr const char *VANILLA = "Vanilla";
            };
            struct PHP {
                static constexpr const char *CAKE = "Cake";
                static constexpr const char *CODEIGNITER = "CodeIgniter";
                static constexpr const char *CORE = "Core";
                static constexpr const char *LARAVEL = "Laravel";
                static constexpr const char *YII = "Yii";
            };
        };
    }
}
#endif //DBCRUDGEN_CPP_FRAMEWORKS_H
