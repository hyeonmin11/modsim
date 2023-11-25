#include "pc.m.h"

PC::PC( string name )
{
	linkSimulator( name );

	in = new PORT( "in" );
	out = new PORT( "out" );

	addInport( *in );
	addOutport( *out );

	job_id( "job_id" );
	processing_time( "processing_time" );

	sigma = INFINITY;
	phase = "passive";
	job_id = "-";
	processing_time = rand()%2 + 2;
}


PC::~PC()
{
	delete out;
	delete in;
}


void PC::externalTransitionFunc( timetype e, CONTENT x )
{
	if ( *in == x.getPort() )
	{
		if ( phase == "passive" )
		{
			job_id = x.getValue();
			holdIn( "busy", STR_TO_DBL( processing_time.getV() ) );
		}
		else if ( phase == "busy" )
			Continue( e );
	}
}


void PC::internalTransitionFunc()
{
	if ( phase == "busy" )
		passivate();
}


CONTENT PC::outputFunc()
{
    job_id = "(g1 ( 90 8 7 32 18 ) ) (g1 ( 21 56 87 4 7 ) ) (g1 ( 2 7 4 1 66 ) )";
	CONTENT y;
	string id = job_id.getV();

    istringstream iss(id);
    ostringstream oss;
    int num;    char ch;    int cnt=3;

    // "g1 ("를 결과 문자열에 먼저 추가합니다.
    oss << "g1 (";

    // 입력 문자열을 순회하며 숫자를 추출합니다.
    iss >> ch;
    while(cnt){
        printf("%s\n", &oss);
        while(iss >> ch && ch != '(');
        while(iss >> ch && ch != '(');
        
        while (iss >> num && ch != ')') {
            oss << num << " ";
        }
        cnt--;

    }


    // 마지막 공백을 제거하고 닫는 괄호를 추가합니다.
    string result = oss.str();
    result.pop_back(); // 마지막 공백 제거
    result += ")";
    

    //std::cout << res << std::endl;

	if ( phase == "busy" )
		y.setContent( out, result );

	return y;
}