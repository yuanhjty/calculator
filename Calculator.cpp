#include "Calculator.h"


void ScientificCalculator::init()
{
    std::shared_ptr<Scanner> scanner = new Scanner;
    std::shared_ptr<Parser> parser = new Parser;
    std::shared_ptr<Expression> expression = new Expression;

    scanner->init();
    parser->init();
    expression->init();

    m_scanner = scanner;
    m_parser = parser;
    m_expression = expression;
}

void ScientificCalculator::evaluate() {
    buildExpression();
    m_expression->evaluate();
    m_result = m_expression->getResult();
}


void ConversionCalculator::init()
{

}

void ConversionCalculator::evaluate()
{

}
