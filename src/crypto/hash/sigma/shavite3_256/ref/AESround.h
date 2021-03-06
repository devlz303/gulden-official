// File originates from the supercop project
#ifndef AESROUND_H
#define AESROUND_H

// Tables of the combined SubBytes MixColumns operation
static const uint32_t AESTable0[256] = {
0xA56363C6U, 0x847C7CF8U, 0x997777EEU, 0x8D7B7BF6U, 0x0DF2F2FFU, 0xBD6B6BD6U, 
0xB16F6FDEU, 0x54C5C591U, 0x50303060U, 0x03010102U, 0xA96767CEU, 0x7D2B2B56U, 
0x19FEFEE7U, 0x62D7D7B5U, 0xE6ABAB4DU, 0x9A7676ECU, 0x45CACA8FU, 0x9D82821FU, 
0x40C9C989U, 0x877D7DFAU, 0x15FAFAEFU, 0xEB5959B2U, 0xC947478EU, 0x0BF0F0FBU, 
0xECADAD41U, 0x67D4D4B3U, 0xFDA2A25FU, 0xEAAFAF45U, 0xBF9C9C23U, 0xF7A4A453U, 
0x967272E4U, 0x5BC0C09BU, 0xC2B7B775U, 0x1CFDFDE1U, 0xAE93933DU, 0x6A26264CU, 
0x5A36366CU, 0x413F3F7EU, 0x02F7F7F5U, 0x4FCCCC83U, 0x5C343468U, 0xF4A5A551U, 
0x34E5E5D1U, 0x08F1F1F9U, 0x937171E2U, 0x73D8D8ABU, 0x53313162U, 0x3F15152AU, 
0x0C040408U, 0x52C7C795U, 0x65232346U, 0x5EC3C39DU, 0x28181830U, 0xA1969637U, 
0x0F05050AU, 0xB59A9A2FU, 0x0907070EU, 0x36121224U, 0x9B80801BU, 0x3DE2E2DFU, 
0x26EBEBCDU, 0x6927274EU, 0xCDB2B27FU, 0x9F7575EAU, 0x1B090912U, 0x9E83831DU, 
0x742C2C58U, 0x2E1A1A34U, 0x2D1B1B36U, 0xB26E6EDCU, 0xEE5A5AB4U, 0xFBA0A05BU, 
0xF65252A4U, 0x4D3B3B76U, 0x61D6D6B7U, 0xCEB3B37DU, 0x7B292952U, 0x3EE3E3DDU, 
0x712F2F5EU, 0x97848413U, 0xF55353A6U, 0x68D1D1B9U, 0x00000000U, 0x2CEDEDC1U, 
0x60202040U, 0x1FFCFCE3U, 0xC8B1B179U, 0xED5B5BB6U, 0xBE6A6AD4U, 0x46CBCB8DU, 
0xD9BEBE67U, 0x4B393972U, 0xDE4A4A94U, 0xD44C4C98U, 0xE85858B0U, 0x4ACFCF85U, 
0x6BD0D0BBU, 0x2AEFEFC5U, 0xE5AAAA4FU, 0x16FBFBEDU, 0xC5434386U, 0xD74D4D9AU, 
0x55333366U, 0x94858511U, 0xCF45458AU, 0x10F9F9E9U, 0x06020204U, 0x817F7FFEU, 
0xF05050A0U, 0x443C3C78U, 0xBA9F9F25U, 0xE3A8A84BU, 0xF35151A2U, 0xFEA3A35DU, 
0xC0404080U, 0x8A8F8F05U, 0xAD92923FU, 0xBC9D9D21U, 0x48383870U, 0x04F5F5F1U, 
0xDFBCBC63U, 0xC1B6B677U, 0x75DADAAFU, 0x63212142U, 0x30101020U, 0x1AFFFFE5U, 
0x0EF3F3FDU, 0x6DD2D2BFU, 0x4CCDCD81U, 0x140C0C18U, 0x35131326U, 0x2FECECC3U, 
0xE15F5FBEU, 0xA2979735U, 0xCC444488U, 0x3917172EU, 0x57C4C493U, 0xF2A7A755U, 
0x827E7EFCU, 0x473D3D7AU, 0xAC6464C8U, 0xE75D5DBAU, 0x2B191932U, 0x957373E6U, 
0xA06060C0U, 0x98818119U, 0xD14F4F9EU, 0x7FDCDCA3U, 0x66222244U, 0x7E2A2A54U, 
0xAB90903BU, 0x8388880BU, 0xCA46468CU, 0x29EEEEC7U, 0xD3B8B86BU, 0x3C141428U, 
0x79DEDEA7U, 0xE25E5EBCU, 0x1D0B0B16U, 0x76DBDBADU, 0x3BE0E0DBU, 0x56323264U, 
0x4E3A3A74U, 0x1E0A0A14U, 0xDB494992U, 0x0A06060CU, 0x6C242448U, 0xE45C5CB8U, 
0x5DC2C29FU, 0x6ED3D3BDU, 0xEFACAC43U, 0xA66262C4U, 0xA8919139U, 0xA4959531U, 
0x37E4E4D3U, 0x8B7979F2U, 0x32E7E7D5U, 0x43C8C88BU, 0x5937376EU, 0xB76D6DDAU, 
0x8C8D8D01U, 0x64D5D5B1U, 0xD24E4E9CU, 0xE0A9A949U, 0xB46C6CD8U, 0xFA5656ACU, 
0x07F4F4F3U, 0x25EAEACFU, 0xAF6565CAU, 0x8E7A7AF4U, 0xE9AEAE47U, 0x18080810U, 
0xD5BABA6FU, 0x887878F0U, 0x6F25254AU, 0x722E2E5CU, 0x241C1C38U, 0xF1A6A657U, 
0xC7B4B473U, 0x51C6C697U, 0x23E8E8CBU, 0x7CDDDDA1U, 0x9C7474E8U, 0x211F1F3EU, 
0xDD4B4B96U, 0xDCBDBD61U, 0x868B8B0DU, 0x858A8A0FU, 0x907070E0U, 0x423E3E7CU, 
0xC4B5B571U, 0xAA6666CCU, 0xD8484890U, 0x05030306U, 0x01F6F6F7U, 0x120E0E1CU, 
0xA36161C2U, 0x5F35356AU, 0xF95757AEU, 0xD0B9B969U, 0x91868617U, 0x58C1C199U, 
0x271D1D3AU, 0xB99E9E27U, 0x38E1E1D9U, 0x13F8F8EBU, 0xB398982BU, 0x33111122U, 
0xBB6969D2U, 0x70D9D9A9U, 0x898E8E07U, 0xA7949433U, 0xB69B9B2DU, 0x221E1E3CU, 
0x92878715U, 0x20E9E9C9U, 0x49CECE87U, 0xFF5555AAU, 0x78282850U, 0x7ADFDFA5U, 
0x8F8C8C03U, 0xF8A1A159U, 0x80898909U, 0x170D0D1AU, 0xDABFBF65U, 0x31E6E6D7U, 
0xC6424284U, 0xB86868D0U, 0xC3414182U, 0xB0999929U, 0x772D2D5AU, 0x110F0F1EU, 
0xCBB0B07BU, 0xFC5454A8U, 0xD6BBBB6DU, 0x3A16162CU, 
};

static const uint32_t AESTable1[256] = {
0x6363C6A5U, 0x7C7CF884U, 0x7777EE99U, 0x7B7BF68DU, 0xF2F2FF0DU, 0x6B6BD6BDU, 
0x6F6FDEB1U, 0xC5C59154U, 0x30306050U, 0x01010203U, 0x6767CEA9U, 0x2B2B567DU, 
0xFEFEE719U, 0xD7D7B562U, 0xABAB4DE6U, 0x7676EC9AU, 0xCACA8F45U, 0x82821F9DU, 
0xC9C98940U, 0x7D7DFA87U, 0xFAFAEF15U, 0x5959B2EBU, 0x47478EC9U, 0xF0F0FB0BU, 
0xADAD41ECU, 0xD4D4B367U, 0xA2A25FFDU, 0xAFAF45EAU, 0x9C9C23BFU, 0xA4A453F7U, 
0x7272E496U, 0xC0C09B5BU, 0xB7B775C2U, 0xFDFDE11CU, 0x93933DAEU, 0x26264C6AU, 
0x36366C5AU, 0x3F3F7E41U, 0xF7F7F502U, 0xCCCC834FU, 0x3434685CU, 0xA5A551F4U, 
0xE5E5D134U, 0xF1F1F908U, 0x7171E293U, 0xD8D8AB73U, 0x31316253U, 0x15152A3FU, 
0x0404080CU, 0xC7C79552U, 0x23234665U, 0xC3C39D5EU, 0x18183028U, 0x969637A1U, 
0x05050A0FU, 0x9A9A2FB5U, 0x07070E09U, 0x12122436U, 0x80801B9BU, 0xE2E2DF3DU, 
0xEBEBCD26U, 0x27274E69U, 0xB2B27FCDU, 0x7575EA9FU, 0x0909121BU, 0x83831D9EU, 
0x2C2C5874U, 0x1A1A342EU, 0x1B1B362DU, 0x6E6EDCB2U, 0x5A5AB4EEU, 0xA0A05BFBU, 
0x5252A4F6U, 0x3B3B764DU, 0xD6D6B761U, 0xB3B37DCEU, 0x2929527BU, 0xE3E3DD3EU, 
0x2F2F5E71U, 0x84841397U, 0x5353A6F5U, 0xD1D1B968U, 0x00000000U, 0xEDEDC12CU, 
0x20204060U, 0xFCFCE31FU, 0xB1B179C8U, 0x5B5BB6EDU, 0x6A6AD4BEU, 0xCBCB8D46U, 
0xBEBE67D9U, 0x3939724BU, 0x4A4A94DEU, 0x4C4C98D4U, 0x5858B0E8U, 0xCFCF854AU, 
0xD0D0BB6BU, 0xEFEFC52AU, 0xAAAA4FE5U, 0xFBFBED16U, 0x434386C5U, 0x4D4D9AD7U, 
0x33336655U, 0x85851194U, 0x45458ACFU, 0xF9F9E910U, 0x02020406U, 0x7F7FFE81U, 
0x5050A0F0U, 0x3C3C7844U, 0x9F9F25BAU, 0xA8A84BE3U, 0x5151A2F3U, 0xA3A35DFEU, 
0x404080C0U, 0x8F8F058AU, 0x92923FADU, 0x9D9D21BCU, 0x38387048U, 0xF5F5F104U, 
0xBCBC63DFU, 0xB6B677C1U, 0xDADAAF75U, 0x21214263U, 0x10102030U, 0xFFFFE51AU, 
0xF3F3FD0EU, 0xD2D2BF6DU, 0xCDCD814CU, 0x0C0C1814U, 0x13132635U, 0xECECC32FU, 
0x5F5FBEE1U, 0x979735A2U, 0x444488CCU, 0x17172E39U, 0xC4C49357U, 0xA7A755F2U, 
0x7E7EFC82U, 0x3D3D7A47U, 0x6464C8ACU, 0x5D5DBAE7U, 0x1919322BU, 0x7373E695U, 
0x6060C0A0U, 0x81811998U, 0x4F4F9ED1U, 0xDCDCA37FU, 0x22224466U, 0x2A2A547EU, 
0x90903BABU, 0x88880B83U, 0x46468CCAU, 0xEEEEC729U, 0xB8B86BD3U, 0x1414283CU, 
0xDEDEA779U, 0x5E5EBCE2U, 0x0B0B161DU, 0xDBDBAD76U, 0xE0E0DB3BU, 0x32326456U, 
0x3A3A744EU, 0x0A0A141EU, 0x494992DBU, 0x06060C0AU, 0x2424486CU, 0x5C5CB8E4U, 
0xC2C29F5DU, 0xD3D3BD6EU, 0xACAC43EFU, 0x6262C4A6U, 0x919139A8U, 0x959531A4U, 
0xE4E4D337U, 0x7979F28BU, 0xE7E7D532U, 0xC8C88B43U, 0x37376E59U, 0x6D6DDAB7U, 
0x8D8D018CU, 0xD5D5B164U, 0x4E4E9CD2U, 0xA9A949E0U, 0x6C6CD8B4U, 0x5656ACFAU, 
0xF4F4F307U, 0xEAEACF25U, 0x6565CAAFU, 0x7A7AF48EU, 0xAEAE47E9U, 0x08081018U, 
0xBABA6FD5U, 0x7878F088U, 0x25254A6FU, 0x2E2E5C72U, 0x1C1C3824U, 0xA6A657F1U, 
0xB4B473C7U, 0xC6C69751U, 0xE8E8CB23U, 0xDDDDA17CU, 0x7474E89CU, 0x1F1F3E21U, 
0x4B4B96DDU, 0xBDBD61DCU, 0x8B8B0D86U, 0x8A8A0F85U, 0x7070E090U, 0x3E3E7C42U, 
0xB5B571C4U, 0x6666CCAAU, 0x484890D8U, 0x03030605U, 0xF6F6F701U, 0x0E0E1C12U, 
0x6161C2A3U, 0x35356A5FU, 0x5757AEF9U, 0xB9B969D0U, 0x86861791U, 0xC1C19958U, 
0x1D1D3A27U, 0x9E9E27B9U, 0xE1E1D938U, 0xF8F8EB13U, 0x98982BB3U, 0x11112233U, 
0x6969D2BBU, 0xD9D9A970U, 0x8E8E0789U, 0x949433A7U, 0x9B9B2DB6U, 0x1E1E3C22U, 
0x87871592U, 0xE9E9C920U, 0xCECE8749U, 0x5555AAFFU, 0x28285078U, 0xDFDFA57AU, 
0x8C8C038FU, 0xA1A159F8U, 0x89890980U, 0x0D0D1A17U, 0xBFBF65DAU, 0xE6E6D731U, 
0x424284C6U, 0x6868D0B8U, 0x414182C3U, 0x999929B0U, 0x2D2D5A77U, 0x0F0F1E11U, 
0xB0B07BCBU, 0x5454A8FCU, 0xBBBB6DD6U, 0x16162C3AU, 
};

static const uint32_t AESTable2[256] = {
0x63C6A563U, 0x7CF8847CU, 0x77EE9977U, 0x7BF68D7BU, 0xF2FF0DF2U, 0x6BD6BD6BU, 
0x6FDEB16FU, 0xC59154C5U, 0x30605030U, 0x01020301U, 0x67CEA967U, 0x2B567D2BU, 
0xFEE719FEU, 0xD7B562D7U, 0xAB4DE6ABU, 0x76EC9A76U, 0xCA8F45CAU, 0x821F9D82U, 
0xC98940C9U, 0x7DFA877DU, 0xFAEF15FAU, 0x59B2EB59U, 0x478EC947U, 0xF0FB0BF0U, 
0xAD41ECADU, 0xD4B367D4U, 0xA25FFDA2U, 0xAF45EAAFU, 0x9C23BF9CU, 0xA453F7A4U, 
0x72E49672U, 0xC09B5BC0U, 0xB775C2B7U, 0xFDE11CFDU, 0x933DAE93U, 0x264C6A26U, 
0x366C5A36U, 0x3F7E413FU, 0xF7F502F7U, 0xCC834FCCU, 0x34685C34U, 0xA551F4A5U, 
0xE5D134E5U, 0xF1F908F1U, 0x71E29371U, 0xD8AB73D8U, 0x31625331U, 0x152A3F15U, 
0x04080C04U, 0xC79552C7U, 0x23466523U, 0xC39D5EC3U, 0x18302818U, 0x9637A196U, 
0x050A0F05U, 0x9A2FB59AU, 0x070E0907U, 0x12243612U, 0x801B9B80U, 0xE2DF3DE2U, 
0xEBCD26EBU, 0x274E6927U, 0xB27FCDB2U, 0x75EA9F75U, 0x09121B09U, 0x831D9E83U, 
0x2C58742CU, 0x1A342E1AU, 0x1B362D1BU, 0x6EDCB26EU, 0x5AB4EE5AU, 0xA05BFBA0U, 
0x52A4F652U, 0x3B764D3BU, 0xD6B761D6U, 0xB37DCEB3U, 0x29527B29U, 0xE3DD3EE3U, 
0x2F5E712FU, 0x84139784U, 0x53A6F553U, 0xD1B968D1U, 0x00000000U, 0xEDC12CEDU, 
0x20406020U, 0xFCE31FFCU, 0xB179C8B1U, 0x5BB6ED5BU, 0x6AD4BE6AU, 0xCB8D46CBU, 
0xBE67D9BEU, 0x39724B39U, 0x4A94DE4AU, 0x4C98D44CU, 0x58B0E858U, 0xCF854ACFU, 
0xD0BB6BD0U, 0xEFC52AEFU, 0xAA4FE5AAU, 0xFBED16FBU, 0x4386C543U, 0x4D9AD74DU, 
0x33665533U, 0x85119485U, 0x458ACF45U, 0xF9E910F9U, 0x02040602U, 0x7FFE817FU, 
0x50A0F050U, 0x3C78443CU, 0x9F25BA9FU, 0xA84BE3A8U, 0x51A2F351U, 0xA35DFEA3U, 
0x4080C040U, 0x8F058A8FU, 0x923FAD92U, 0x9D21BC9DU, 0x38704838U, 0xF5F104F5U, 
0xBC63DFBCU, 0xB677C1B6U, 0xDAAF75DAU, 0x21426321U, 0x10203010U, 0xFFE51AFFU, 
0xF3FD0EF3U, 0xD2BF6DD2U, 0xCD814CCDU, 0x0C18140CU, 0x13263513U, 0xECC32FECU, 
0x5FBEE15FU, 0x9735A297U, 0x4488CC44U, 0x172E3917U, 0xC49357C4U, 0xA755F2A7U, 
0x7EFC827EU, 0x3D7A473DU, 0x64C8AC64U, 0x5DBAE75DU, 0x19322B19U, 0x73E69573U, 
0x60C0A060U, 0x81199881U, 0x4F9ED14FU, 0xDCA37FDCU, 0x22446622U, 0x2A547E2AU, 
0x903BAB90U, 0x880B8388U, 0x468CCA46U, 0xEEC729EEU, 0xB86BD3B8U, 0x14283C14U, 
0xDEA779DEU, 0x5EBCE25EU, 0x0B161D0BU, 0xDBAD76DBU, 0xE0DB3BE0U, 0x32645632U, 
0x3A744E3AU, 0x0A141E0AU, 0x4992DB49U, 0x060C0A06U, 0x24486C24U, 0x5CB8E45CU, 
0xC29F5DC2U, 0xD3BD6ED3U, 0xAC43EFACU, 0x62C4A662U, 0x9139A891U, 0x9531A495U, 
0xE4D337E4U, 0x79F28B79U, 0xE7D532E7U, 0xC88B43C8U, 0x376E5937U, 0x6DDAB76DU, 
0x8D018C8DU, 0xD5B164D5U, 0x4E9CD24EU, 0xA949E0A9U, 0x6CD8B46CU, 0x56ACFA56U, 
0xF4F307F4U, 0xEACF25EAU, 0x65CAAF65U, 0x7AF48E7AU, 0xAE47E9AEU, 0x08101808U, 
0xBA6FD5BAU, 0x78F08878U, 0x254A6F25U, 0x2E5C722EU, 0x1C38241CU, 0xA657F1A6U, 
0xB473C7B4U, 0xC69751C6U, 0xE8CB23E8U, 0xDDA17CDDU, 0x74E89C74U, 0x1F3E211FU, 
0x4B96DD4BU, 0xBD61DCBDU, 0x8B0D868BU, 0x8A0F858AU, 0x70E09070U, 0x3E7C423EU, 
0xB571C4B5U, 0x66CCAA66U, 0x4890D848U, 0x03060503U, 0xF6F701F6U, 0x0E1C120EU, 
0x61C2A361U, 0x356A5F35U, 0x57AEF957U, 0xB969D0B9U, 0x86179186U, 0xC19958C1U, 
0x1D3A271DU, 0x9E27B99EU, 0xE1D938E1U, 0xF8EB13F8U, 0x982BB398U, 0x11223311U, 
0x69D2BB69U, 0xD9A970D9U, 0x8E07898EU, 0x9433A794U, 0x9B2DB69BU, 0x1E3C221EU, 
0x87159287U, 0xE9C920E9U, 0xCE8749CEU, 0x55AAFF55U, 0x28507828U, 0xDFA57ADFU, 
0x8C038F8CU, 0xA159F8A1U, 0x89098089U, 0x0D1A170DU, 0xBF65DABFU, 0xE6D731E6U, 
0x4284C642U, 0x68D0B868U, 0x4182C341U, 0x9929B099U, 0x2D5A772DU, 0x0F1E110FU, 
0xB07BCBB0U, 0x54A8FC54U, 0xBB6DD6BBU, 0x162C3A16U, 
};

static const uint32_t AESTable3[256] = {
0xC6A56363U, 0xF8847C7CU, 0xEE997777U, 0xF68D7B7BU, 0xFF0DF2F2U, 0xD6BD6B6BU, 
0xDEB16F6FU, 0x9154C5C5U, 0x60503030U, 0x02030101U, 0xCEA96767U, 0x567D2B2BU, 
0xE719FEFEU, 0xB562D7D7U, 0x4DE6ABABU, 0xEC9A7676U, 0x8F45CACAU, 0x1F9D8282U, 
0x8940C9C9U, 0xFA877D7DU, 0xEF15FAFAU, 0xB2EB5959U, 0x8EC94747U, 0xFB0BF0F0U, 
0x41ECADADU, 0xB367D4D4U, 0x5FFDA2A2U, 0x45EAAFAFU, 0x23BF9C9CU, 0x53F7A4A4U, 
0xE4967272U, 0x9B5BC0C0U, 0x75C2B7B7U, 0xE11CFDFDU, 0x3DAE9393U, 0x4C6A2626U, 
0x6C5A3636U, 0x7E413F3FU, 0xF502F7F7U, 0x834FCCCCU, 0x685C3434U, 0x51F4A5A5U, 
0xD134E5E5U, 0xF908F1F1U, 0xE2937171U, 0xAB73D8D8U, 0x62533131U, 0x2A3F1515U, 
0x080C0404U, 0x9552C7C7U, 0x46652323U, 0x9D5EC3C3U, 0x30281818U, 0x37A19696U, 
0x0A0F0505U, 0x2FB59A9AU, 0x0E090707U, 0x24361212U, 0x1B9B8080U, 0xDF3DE2E2U, 
0xCD26EBEBU, 0x4E692727U, 0x7FCDB2B2U, 0xEA9F7575U, 0x121B0909U, 0x1D9E8383U, 
0x58742C2CU, 0x342E1A1AU, 0x362D1B1BU, 0xDCB26E6EU, 0xB4EE5A5AU, 0x5BFBA0A0U, 
0xA4F65252U, 0x764D3B3BU, 0xB761D6D6U, 0x7DCEB3B3U, 0x527B2929U, 0xDD3EE3E3U, 
0x5E712F2FU, 0x13978484U, 0xA6F55353U, 0xB968D1D1U, 0x00000000U, 0xC12CEDEDU, 
0x40602020U, 0xE31FFCFCU, 0x79C8B1B1U, 0xB6ED5B5BU, 0xD4BE6A6AU, 0x8D46CBCBU, 
0x67D9BEBEU, 0x724B3939U, 0x94DE4A4AU, 0x98D44C4CU, 0xB0E85858U, 0x854ACFCFU, 
0xBB6BD0D0U, 0xC52AEFEFU, 0x4FE5AAAAU, 0xED16FBFBU, 0x86C54343U, 0x9AD74D4DU, 
0x66553333U, 0x11948585U, 0x8ACF4545U, 0xE910F9F9U, 0x04060202U, 0xFE817F7FU, 
0xA0F05050U, 0x78443C3CU, 0x25BA9F9FU, 0x4BE3A8A8U, 0xA2F35151U, 0x5DFEA3A3U, 
0x80C04040U, 0x058A8F8FU, 0x3FAD9292U, 0x21BC9D9DU, 0x70483838U, 0xF104F5F5U, 
0x63DFBCBCU, 0x77C1B6B6U, 0xAF75DADAU, 0x42632121U, 0x20301010U, 0xE51AFFFFU, 
0xFD0EF3F3U, 0xBF6DD2D2U, 0x814CCDCDU, 0x18140C0CU, 0x26351313U, 0xC32FECECU, 
0xBEE15F5FU, 0x35A29797U, 0x88CC4444U, 0x2E391717U, 0x9357C4C4U, 0x55F2A7A7U, 
0xFC827E7EU, 0x7A473D3DU, 0xC8AC6464U, 0xBAE75D5DU, 0x322B1919U, 0xE6957373U, 
0xC0A06060U, 0x19988181U, 0x9ED14F4FU, 0xA37FDCDCU, 0x44662222U, 0x547E2A2AU, 
0x3BAB9090U, 0x0B838888U, 0x8CCA4646U, 0xC729EEEEU, 0x6BD3B8B8U, 0x283C1414U, 
0xA779DEDEU, 0xBCE25E5EU, 0x161D0B0BU, 0xAD76DBDBU, 0xDB3BE0E0U, 0x64563232U, 
0x744E3A3AU, 0x141E0A0AU, 0x92DB4949U, 0x0C0A0606U, 0x486C2424U, 0xB8E45C5CU, 
0x9F5DC2C2U, 0xBD6ED3D3U, 0x43EFACACU, 0xC4A66262U, 0x39A89191U, 0x31A49595U, 
0xD337E4E4U, 0xF28B7979U, 0xD532E7E7U, 0x8B43C8C8U, 0x6E593737U, 0xDAB76D6DU, 
0x018C8D8DU, 0xB164D5D5U, 0x9CD24E4EU, 0x49E0A9A9U, 0xD8B46C6CU, 0xACFA5656U, 
0xF307F4F4U, 0xCF25EAEAU, 0xCAAF6565U, 0xF48E7A7AU, 0x47E9AEAEU, 0x10180808U, 
0x6FD5BABAU, 0xF0887878U, 0x4A6F2525U, 0x5C722E2EU, 0x38241C1CU, 0x57F1A6A6U, 
0x73C7B4B4U, 0x9751C6C6U, 0xCB23E8E8U, 0xA17CDDDDU, 0xE89C7474U, 0x3E211F1FU, 
0x96DD4B4BU, 0x61DCBDBDU, 0x0D868B8BU, 0x0F858A8AU, 0xE0907070U, 0x7C423E3EU, 
0x71C4B5B5U, 0xCCAA6666U, 0x90D84848U, 0x06050303U, 0xF701F6F6U, 0x1C120E0EU, 
0xC2A36161U, 0x6A5F3535U, 0xAEF95757U, 0x69D0B9B9U, 0x17918686U, 0x9958C1C1U, 
0x3A271D1DU, 0x27B99E9EU, 0xD938E1E1U, 0xEB13F8F8U, 0x2BB39898U, 0x22331111U, 
0xD2BB6969U, 0xA970D9D9U, 0x07898E8EU, 0x33A79494U, 0x2DB69B9BU, 0x3C221E1EU, 
0x15928787U, 0xC920E9E9U, 0x8749CECEU, 0xAAFF5555U, 0x50782828U, 0xA57ADFDFU, 
0x038F8C8CU, 0x59F8A1A1U, 0x09808989U, 0x1A170D0DU, 0x65DABFBFU, 0xD731E6E6U, 
0x84C64242U, 0xD0B86868U, 0x82C34141U, 0x29B09999U, 0x5A772D2DU, 0x1E110F0FU, 
0x7BCBB0B0U, 0xA8FC5454U, 0x6DD6BBBBU, 0x2C3A1616U, 
};

#define roundAESnokey(_input0, _input1, _input2, _input3, _output0, _output1, _output2, _output3) \
{ \
  _output0 = AESTable0[_input0 & 0xff ] ^ AESTable1[(_input1 >> 8) & 0xff] ^ AESTable2[(_input2 >> 16) & 0xff] ^ AESTable3[_input3 >> 24]; \
  _output1 = AESTable0[_input1 & 0xff ] ^ AESTable1[(_input2 >> 8) & 0xff] ^ AESTable2[(_input3 >> 16) & 0xff] ^ AESTable3[_input0 >> 24]; \
  _output2 = AESTable0[_input2 & 0xff ] ^ AESTable1[(_input3 >> 8) & 0xff] ^ AESTable2[(_input0 >> 16) & 0xff] ^ AESTable3[_input1 >> 24]; \
  _output3 = AESTable0[_input3 & 0xff ] ^ AESTable1[(_input0 >> 8) & 0xff] ^ AESTable2[(_input1 >> 16) & 0xff] ^ AESTable3[_input2 >> 24]; \
}

#define roundAES(_input0, _input1, _input2, _input3, _output0, _output1, _output2, _output3, _key0, _key1, _key2, _key3) \
{ \
  _output0 = AESTable0[_input0 & 0xff ] ^ AESTable1[(_input1 >> 8) & 0xff] ^ AESTable2[(_input2 >> 16) & 0xff] ^ AESTable3[_input3 >> 24]^_key0; \
  _output1 = AESTable0[_input1 & 0xff ] ^ AESTable1[(_input2 >> 8) & 0xff] ^ AESTable2[(_input3 >> 16) & 0xff] ^ AESTable3[_input0 >> 24]^_key1; \
  _output2 = AESTable0[_input2 & 0xff ] ^ AESTable1[(_input3 >> 8) & 0xff] ^ AESTable2[(_input0 >> 16) & 0xff] ^ AESTable3[_input1 >> 24]^_key2; \
  _output3 = AESTable0[_input3 & 0xff ] ^ AESTable1[(_input0 >> 8) & 0xff] ^ AESTable2[(_input1 >> 16) & 0xff] ^ AESTable3[_input2 >> 24]^_key3; \
}

#endif
