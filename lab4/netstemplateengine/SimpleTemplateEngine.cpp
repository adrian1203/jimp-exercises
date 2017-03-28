//
// Created by adrian on 26.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets {
    View::View() {}

    View::View(string str) {
        str_ = str;
    }
    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        string tekst = str_;
        string tmp2 = "";
        for (auto &n : model) {
            string tmp = n.first;
            while (tekst.find("{{" + tmp + "}}") < tekst.size()) {
                string tmp1 = n.second;
                if (tmp1[tmp1.size() - 1] == '}') {
                    tmp1[tmp1.size() - 1] = '*';
                }
                tekst.replace(tekst.find("{{" + tmp + "}}"), tmp.size() + 4, tmp1);
            }
        }
        while (tekst.find("*") < tekst.size()) {
            tekst.replace(tekst.find("*"), 1, "}");
        }
        for (int i = 0; i < tekst.size(); i++) {
            string tmp1 = "";
            if (tekst[i] == '{' and tekst[i + 1] == '{') {
                i = i + 2;
                while (tekst[i] != '}' and i < tekst.size()) {
                    tmp1 += tekst[i];
                    i++;
                }
                if (tekst[i] == '}' and tekst[i + 1] == '}') {
                    int k = 0;
                    for (auto &n : model) {
                        if (n.first == tmp1) {
                            k++;
                        }
                    }
                    if (k == 0) {
                        tekst.replace(tekst.find("{{" + tmp1 + "}}"), tmp1.size() + 4, "");
                        i = 0;
                    }
                }
            }

        }

        return tekst;
    };
};
