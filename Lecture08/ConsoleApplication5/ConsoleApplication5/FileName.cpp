//#include <iostream>
//#include <vector>
//#include <thread>
//void delay(int milliseconds) {
//    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
//}
//int main() {
//    std::vector<std::string> ants = {
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "#########################################################oooooooooooooooooooooooooo##############################################################################ooooooooooooooooooooooooooooo##########",
//        "#########################################################oooooooooooooooooooooooooo##############################################################################o###########################o##########",
//        "##############################################ooooooooooooooooo##################################################################################################o###########################o##########",
//        "###################################oooooooooooooooooooooooo######################################################################################################o###########################o##########",
//        "##############ooooooooooooooooooooooooooooooooooooooooooooooo####################################################################################################o###########################o##########",
//        "##############oooooooooooo################################oooo###################################################################################################o###########################o##########",
//        "##############oooooooooooo################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########",
//        "##############oooooooooooooooooooo#################oooooooooooo####oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "#################ooooooooooooooooo#################oooooooooooo####ooooooooooooooooooooooooooooooooo###########################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###ooooooooooooooo############oooo#################oooooooooooo####ooooooooooooooooooooooooooooooooo###########################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###o##########################oooo#################ooooooooooooooooooooooooooooooooooooooooooooooooo###########################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###o##########################oooo#############################################################################################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###o##########################oooo####oooooooooooooooo#########################################################################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###o#########ooooooooooooooooooooo####o##############o#########################################################################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "###o#########oooooooo#################o##############o#########################################################################################oooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "##oooooooooooo########################o##############o################################ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "##oo##################################oooooooooooooo#o################################ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#####",
//        "##oo###############################################o#o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########",
//        "##oo####ooooooooooooo##############################o#o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########",
//        "###o####ooooooooooooo#########oooooooooooooooooooooo#o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo################################",
//        "###o###############oo#########o######################o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo################################",
//        "###o###############ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo################################",
//        "###o###############ooooooooooooooooooooooooooooooooooo##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########################",
//        "###o###############oo#########o##########oo#####################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########",
//        "###o#####oooooooooooo#########o##########oo#####################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo################################",
//        "###o#####oooooooooooo#########o##########oo#####################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##########################",
//        "###o#####oo########oo#########o##########oo#####################################################oo######################################################################################################",
//        "###o#####oo########oo#########o##########oo#####################################################oo######################################################################################################",
//        "#oooo####oo########oo#########o##########oo#####################################################oo######################################################################################################",
//        "#oooo####oo########oo#########o##########oo#####################################################oo######################################################################################################",
//        "#oooo##############oo#########o##########oo#####################################################oo######################################################################################################",
//        "#oooo##############oo#########o##########oo#####################################################oo######################################################################################################",
//        "#oooooooooooooooooooo#########o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo###############################################################",
//        "#oooo#########################o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#oooo#########################o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#oooo#########################o##########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oo#####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##ooo####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##ooo####################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oooo###################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##ooooo##################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##oooooo#################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##ooooooo################################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "##ooooooooooooooo########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########ooooooo#########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########ooooooo#########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########ooooooo#########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########ooooo###########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########ooooo###########################oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo#######################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "#########oooooooooooooooooooooooooooooooooooooooooooooooooooo###########################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################",
//        "########################################################################################################################################################################################################"
//    };
//
//    delay(3000);
//    for (const auto& line : ants) {
//        std::cout << line << std::endl;
//    }
//
//    return 0;
//}
