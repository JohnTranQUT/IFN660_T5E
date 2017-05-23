#pragma once
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <string>

 class LexiEnviType : public SpecificationType
 {
		EnviRecordType * ER;
		LexiEnviType * OUT;
	 public:
		explicit LexiEnviType(EnviRecordType * _ER, LexiEnviType * _OUT)
		 {
			 ER = _ER;
			 OUT = _OUT;
		 }
		 EnviRecordType *getER() { return ER; }
		 LexiEnviType *getOUT() { return OUT; }
};


LexiEnviType *NewDeclEnvi(LexiEnviType *);
Type *GetIdenRefe(LexiEnviType *, string, bool);
