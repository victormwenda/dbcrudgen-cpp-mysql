//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPARSER_H
#define DBCRUDGEN_CPP_ANGULARPARSER_H

#include "../SyntaxParser.h"
#include "../../../databases/generic/Table.h"
#include "../../templates/angular/AngularClassTableModelTemplate.h"
#include "../../templates/angular/AngularComponentCssTemplate.h"
#include "../../templates/angular/AngularComponentTemplate.h"
#include "../../templates/angular/AngularComponentSpecTemplate.h"
#include "../../templates/angular/AngularComponentHtmlTemplate.h"
#include "../../templates/angular/AngularServiceSpecTemplate.h"
#include "../../templates/angular/AngularServiceTemplate.h"
#include "../../templates/angular/AngularModuleTemplate.h"
#include "../../templates/angular/AngularHtmlTableTemplate.h"
#include "../../templates/angular/AngularHtmlTableHeadTemplate.h"
#include "../../templates/angular/AngularHtmlTableBodyTemplate.h"
#include "../../templates/angular/AngularHtmlFormInputTemplate.h"
#include "../../templates/angular/AngularTsFormControlInitBindTemplate.h"
#include "../../templates/angular/AngularHtmlFormTemplate.h"
#include "../../templates/angular/AngularTextTemplates.h"

namespace dbcrudgen {
    namespace orm {
        class AngularParser : public SyntaxParser {

        public:

            //Create a Java Script data type
            static std::string getJSDataType(const std::string &dataType) {
                if (dataType == "bool") {
                    return "bool";
                }
                if (dataType == "int") {
                    return "number";
                }
                if (dataType == "bigint") {
                    return "number";
                }
                if (dataType == "integer") {
                    return "number";
                }
                if (dataType == "double") {
                    return "number";
                }
                if (dataType == "float") {
                    return "number";
                }
                if (dataType == "longtext") {
                    return "string";
                }
                if (dataType == "varchar") {
                    return "string";
                }
                if (dataType == "string") {
                    return "string";
                }
                if (dataType == "timestamp") {
                    return "string";
                }


                return "any";
            }

            //Create HTML 5 Data type
            static std::string getHtml5DataType(const std::string &dataType) {
                if (dataType == "bool") {
                    return "bool";
                }
                if (dataType == "int") {
                    return "number";
                }
                if (dataType == "bigint") {
                    return "number";
                }
                if (dataType == "integer") {
                    return "number";
                }
                if (dataType == "double") {
                    return "number";
                }
                if (dataType == "float") {
                    return "number";
                }
                if (dataType == "longtext") {
                    return "text";
                }
                if (dataType == "varchar") {
                    return "text";
                }
                if (dataType == "string") {
                    return "text";
                }
                if (dataType == "timestamp") {
                    return "text";
                }


                return "any";
            }

            /**
            * Create  Class name
            * @param name
            * @return
            */
            static std::string toClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return SyntaxParser::createClassNameCamelCase(name);
            }

            static std::string toVariableName(const std::string &name) {
                return createVariableNameCamelCase(name);
            }


            static std::string prepareModelLocation(const std::string &moduleName, const std::string &modelClassName) {

                if (moduleName == "") {
                    return std::string{"./" + moduleName + "/" + modelClassName};
                }
                return std::string{"../" + moduleName + "/" + modelClassName};
            }

            //Create module name
            static std::string createModuleSrc(const std::string &moduleName, const std::string &componentsClassImports,
                                               const std::string &componentsClassesDeclarations) {
                dbcrudgen::orm::AngularModuleTemplate srcTemplate;
                std::string src = srcTemplate.getTemplate();

                src = replace(src, "${MODULE_NAME}", moduleName);
                src = replace(src, "${COMPONENTS_IMPORTS}", componentsClassImports);
                src = replace(src, "${COMPONENTS_DECLARATIONS}", componentsClassesDeclarations);

                return src;
            }

            //Create Table Model source
            static std::string createModelSource(const std::string &className, const std::string modelInstanceVars) {
                dbcrudgen::orm::AngularClassTableModelTemplate srcTemplate;
                std::string src = srcTemplate.getTemplate();

                src = replace(src, "${CLASS_NAME}", className);
                src = replace(src, "${TABLE_COLUMN_INSTANCE_VARIABLES}", modelInstanceVars);

                return src;
            }

            //Create model table instance variable. The instance variable is deduced from the column
            static std::string
            createModelInstanceVariable(const std::string &dataType, const std::string &columnObject) {
                return columnObject + ":" + dataType + ";";
            }

            static std::string createComponentCssSrc(const std::string &componentName) {
                dbcrudgen::orm::AngularComponentCssTemplate cssTemplate;
                return cssTemplate.getTemplate();
            }

            static std::string createComponentHtmlSrc(const std::string &componentName, const std::string &htmlForm,
                                                      const std::string &htmlTable) {
                dbcrudgen::orm::AngularComponentHtmlTemplate htmlTemplate;
                std::string src = htmlTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${FORM}", htmlForm);
                src = replace(src, "${TABLE}", htmlTable);

                return src;
            }

            static std::string
            createComponentSpecSrc(const std::string &componentName, const std::string &componentClass) {
                dbcrudgen::orm::AngularComponentSpecTemplate specTemplate;
                std::string src = specTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${COMPONENT_CLASS}", componentClass);

                return src;
            }

            static std::string
            createComponentTsSrc(const std::string &moduleName,
                                 const std::string &componentName, const std::string &componentClass,
                                 const std::string &modelLocation, const std::string &modelClass,
                                 const std::string &modelClassObject,
                                 const std::string &formGroupDeclaration, const std::string &formControlsDeclarationTs,
                                 const std::string &formGroupInit, const std::string &formControlsBindTs) {
                dbcrudgen::orm::AngularComponentTemplate tsTemplate;
                std::string src = tsTemplate.getTemplate();

                src = replace(src, "${MODULE_NAME}", moduleName);
                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${CLASS_NAME}", componentClass);

                src = replace(src, "${MODEL_LOCATION}", modelLocation);
                src = replace(src, "${MODEL_CLASS}", modelClass);
                src = replace(src, "${MODEL_OBJECT}", modelClassObject);

                src = replace(src, "${FORM_GROUP_DECLARATION}", formGroupDeclaration);
                src = replace(src, "${FORM_CONTROLS_DECLARATION}", formControlsDeclarationTs);
                src = replace(src, "${INIT_FORM_GROUP}", formGroupInit);
                src = replace(src, "${INIT_BIND_FORM_CONTROLS}", formControlsBindTs);

                return src;
            }

            //Creates the service class source code
            static std::string createServiceSrc(const std::string &componentName, const std::string &componentClass,
                                                const std::string &modelLocation, const std::string &modelClass,
                                                const std::string &modelObject) {
                dbcrudgen::orm::AngularServiceTemplate serviceTemplate;
                std::string src = serviceTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${CLASS_NAME}", componentClass);

                src = replace(src, "${MODEL_LOCATION}", modelLocation);
                src = replace(src, "${MODEL_CLASS}", modelClass);
                src = replace(src, "${MODEL_OBJECT}", modelObject);

                return src;
            }

            //Creates the service class test cases(spec) code
            static std::string
            createServiceSpecSrc(const std::string &componentName, const std::string &componentClass) {
                dbcrudgen::orm::AngularServiceSpecTemplate specTemplate;
                std::string src = specTemplate.getTemplate();

                src = replace(src, "${COMPONENT_NAME}", componentName);
                src = replace(src, "${SERVICE_CLASS}", componentClass);

                return src;
            }

            //Set the component class declaration
            static std::string addComponentClassDeclaration(const std::string &componentClass, bool isBeforeLast) {

                return isBeforeLast ?
                       std::string{componentClass + "Component,"} : std::string{componentClass + "Component"};
            }

            //Set the component class imports
            static std::string
            addComponentClassImport(const std::string &componentName, const std::string &componentClass) {

                std::string declarationTemplate = {
                        "import { " + componentClass + "Component } from './" + componentName + "/" + componentName +
                        ".component';"};

                return declarationTemplate;
            }

            //Prepare a Table Head TD Item <td>??</td>
            static std::string prepareTableHeadTD(const std::string &columnTitle) {
                return std::string{"<td>" + columnTitle + "</td>"};
            }

            //Prepare a Table Row TD Item <td>??</td>
            static std::string prepareTableRowTD(const std::string &modelArrObject, const std::string &columnObject) {
                return std::string{"<td> {{_" + modelArrObject + "." + columnObject + "}}</td>"};
            }

            static std::string createTableHeading(const std::string &tableHeadingTitles) {
                dbcrudgen::orm::AngularHtmlTableHeadTemplate headTemplate;
                std::string src = headTemplate.getTemplate();

                src = replace(src, "${TABLE_HEADINGS}", tableHeadingTitles);

                return src;
            }

            static std::string createTableBody(const std::string &modelArrObject, std::string tableBody) {
                dbcrudgen::orm::AngularHtmlTableBodyTemplate bodyTemplate;
                std::string src = bodyTemplate.getTemplate();

                src = replace(src, "${MODEL_OBJECT}", modelArrObject);
                src = replace(src, "${TABLE_COLS}", tableBody);

                return src;
            }

            static std::string createTable(const std::string &tableHeader, std::string tableBody) {
                dbcrudgen::orm::AngularHtmlTableTemplate tableTemplate;
                std::string src = tableTemplate.getTemplate();

                src = replace(src, "${TABLE_HEAD}", tableHeader);
                src = replace(src, "${TABLE_BODY}", tableBody);

                return src;
            }

            static std::string prepareHtmlFormInputs(const std::string &inputTitle, const std::string &inputType,
                                                     const std::string &controlName) {
                dbcrudgen::orm::AngularHtmlFormInputTemplate formInputTemplate;
                std::string src = formInputTemplate.getTemplate();
                src = replace(src, "${INPUT_TYPE}", inputType);
                src = replace(src, "${INPUT_TITLE}", inputTitle);
                src = replace(src, "${FORM_CONTROL}", controlName);

                return src;
            }

            static std::string prepareTsFormInputs(const std::string &formName, const std::string &controlName,
                                                   const std::string &defaultValue) {
                dbcrudgen::orm::AngularTsFormControlInitBindTemplate formControlInitBindTemplate;
                std::string src = formControlInitBindTemplate.getTemplate();

                src = replace(src, "${FORM_GROUP}", formName);
                src = replace(src, "${FORM_CONTROL}", controlName);
                src = replace(src, "${DEFAULT_VALUE}", defaultValue);

                return src;
            }

            static std::string generateHtmlForm(const std::string &modelClass, const std::string &formGroup,
                                                const std::string &formControls) {
                dbcrudgen::orm::AngularHtmlFormTemplate htmlFormTemplate;
                std::string src = htmlFormTemplate.getTemplate();

                src = replace(src, "${MODEL_CLASS}", modelClass);
                src = replace(src, "${FORM_GROUP}", formGroup);
                src = replace(src, "${FORM_CONTROLS}", formControls);

                return src;
            }


            static std::string prepareFormGroupDeclaration(std::string formGroupName) {
                std::string src = AngularTextTemplates::FORM_GROUP_DECLARATION;

                src = replace(src, "${FORM_GROUP}", formGroupName);

                return src;
            }

            static std::string prepareFormGroupInt(std::string formGroupName) {
                std::string src = AngularTextTemplates::FORM_GROUP_INIT;

                src = replace(src, "${FORM_GROUP}", formGroupName);

                return src;
            }

            static std::string prepareFormControlDeclaration(std::string formControlName) {
                std::string src = AngularTextTemplates::FORM_CONTROL_DECLARATION;

                src = replace(src, "${FORM_CONTROL}", formControlName);

                return src;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_ANGULARPARSER_H
