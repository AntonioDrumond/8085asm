#ifndef FLAGS_H
#define FLAGS_H

class Flags{

	private:

	bool Z;
	bool CY;
	bool S;
	bool P;
	bool AC;

	public:

	Flags(){
		this.Z = false;
		this.CY = false;
		this.S = false;
		this.P = false;
		this.AC = false;
	}

	~Flags(){
	}

	void setZ(){
		this.Z = true;
	}
	void resetZ(){
		this.Z = false;
	}
	bool getZ(){
		return this.Z;
	}

	void setbool CY(){
		this.CY = true;
	}
	void resetCY(){
		this.CY = false;
	}
	bool getCY(){
		return this.CY;
	}

	void setbool S(){
		this.S = true;
	}
	void resetS(){
		this.S = false;
	}
	bool getS(){
		return this.S;
	}

	void setbool P(){
		this.P = true;
	}
	void resetP(){
		this.P = false;
	}
	bool getP(){
		return this.P;
	}

	void setbool AC(){
		this.AC = true;
	}
	void resetAC(){
		this.AC = false;
	}
	bool getAC(){
		return this.AC;
	}

}

#endif
