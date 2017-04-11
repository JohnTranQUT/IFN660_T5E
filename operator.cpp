#include <Types.h>
#include <LanguageTypes.h>
#include <SpecificationTypes.h>

namespace {
	ResultContainer *addition(LanguageType *lref = nullptr, LanguageType *rref = nullptr) {
		auto lval = GetValue(lref);
		auto rval = GetValue(rref);
		auto lprim = ToPrimitive(lval);
		auto rprim = ToPrimitive(rval);
		if (dynamic_cast<StringType*>(lprim) || dynamic_cast<StringType *>(rprim)) {
			auto lstr = ToString(lprim);
			auto rstr = ToString(rprim);
			return new ResultContainer(lstr + rstr);
		}
		else {
			auto lnum = ToNumber(lprim);
			auto rnum = ToNumber(rprim);
			return new ResultContainer(lnum + rnum);
		}
	}
}