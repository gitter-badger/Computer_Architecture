#include "simulator.h"

namespace Simulator{
	void R_Type_Calculator(Instruction cur_ins){
		u32 rs = cur_ins.get_rs();
		u32 rt = cur_ins.get_rt();
		u32 rd = cur_ins.get_rd();
		u32 C_shamt = cur_ins.get_C_shamt();
		u32 funct = cur_ins.get_funct();
	
		printf("funct %d vs %d\n", funct, ADD);
		
		
		switch(funct){
			case ADD:
				add_funct(rd, rs, rt);
				break;
			case SUB:
				sub_funct(rd, rs, rt);
		}
	}

	void add_funct(u32 rd, u32 rs, u32 rt){
		s64 sum = (s64)reg[rs] + (s64)reg[rt];;
		detect_overflow(sum, reg[rs], reg[rt]);
		reg[rd] = sum;
	}

	void sub_funct(u32 rd, u32 rs, u32 rt){
		s64 sum = (s64)reg[rs] - (s64)reg[rt];;
		detect_overflow(sum, reg[rs], reg[rt]);
		reg[rd] = sum;
	}

	void and_funct(u32 rd, u32 rs, u32 rt){}
	void or_funct(u32 rd, u32 rs, u32 rt){}
	void xor_funct(u32 rd, u32 rs, u32 rt){}
	void nor_funct(u32 rd, u32 rs, u32 rt){}
	void nand_funct(u32 rd, u32 rs, u32 rt){}
	void slt_funct(u32 rd, u32 rt, u32 C_shamt){}
	void srl_funct(u32 rd, u32 rt, u32 C_shamt){}
	void sra_funct(u32 rd, u32 rt, u32 C_shamt){}
	void jr_funct(u32 rs){}

	void detect_overflow(s64 sum, int x, int y){
		if( x < 0 && y < 0 && sum < MIN)
			fprintf(ERR, "In cycle %d: Number Overflow\n", cycle);
		else if( x > 0 && y > 0 && sum > MAX)
			fprintf(ERR, "In cycle %d: Number Overflow\n", cycle);
		else if( x >= 0 && y <= 0 && sum > MAX)
			fprintf(ERR, "In cycle %d: Number Overflow\n", cycle);
		else if( x <= 0 && y >= 0 && sum < MIN)
			fprintf(ERR, "In cycle %d: Number Overflow\n", cycle);

	}
}
