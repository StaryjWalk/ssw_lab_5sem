//
// Created by vovan on 28.09.2019.
//

#ifndef LEXEM_H
#define LEXEM_H

#include <string>


enum tokens {
    unknown_tk = -1,    // we get unknown token
    program_tk = 0,     // 'program'
    var_tk,             // 'var'
    begin_tk,           // 'begin'
    end_tk,             // 'end'
    type_tk,            // 'type'
    id_tk       = 8,    // any [aA-zZ][0-9]
    constant_tk = 9,    // 0-9
    dot_tk,             // '.'
    comma_tk,           // ','
    ddt_tk,             // ':'
    semi_tk,            // ';'
    eqv_tk,             // '='
    ass_tk,             // ':='
    add_tk,             // '+'
    sub_tk,             // '-'
    mul_tk,             // '*'
    div_tk,             // '/'
    opb_tk,             // '('
    cpb_tk,             // ')'

    eof_tk
};


enum errors {
    UNKNOWN_LEXEM,   // Unknown lexeme
    EOF_ERR,         // End of file error
    MUST_BE_ID,      // Error: Must be identifier
    MUST_BE_SEMI,    // Error: Must be ';'
    MUST_BE_PROG,    // Error: Must be 'program'
    MUST_BE_COMMA,   // Error: Must be ','
    MUST_BE_TYPE,    // Error: Must be type of identifier
    MUST_BE_DOT,     // Error: Must be '.'
    MUST_BE_ASS,     // Error: Must be ':='
    DUPL_ID_ERR,     // Error: Duplicate declaration on identifier
    UNKNOWN_ID,      // Error: Undefined identifier
    // TODO: Add other types of error
};


class Lexem {
public:
    Lexem() = default;
    Lexem(std::string &&t_name, tokens t_tok, int t_line) : name(t_name),
                                                            token(t_tok), line(t_line) {};
    int GetLine(){
        return line;
    }
    tokens GetToken() {
        return token;
    }
    std::string GetName() {
        return name;
    }
private:
    std::string name{ "" };
    tokens token{ unknown_tk };
    int line{ 0 };
};



#endif //LEXEM_H