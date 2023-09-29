#pragma once

class kingTest
{
public:
	void run() const
	{
		read_free();
		read_blocked();
		read_capture();
		read_castle_king_moved();
		read_castle_rook_moved();
		read_castle_block();
		read_castle();
	}
private:
	void read_free() const;
	void read_blocked() const;
	void read_capture()const;
	void read_castle_king_moved() const;
	void read_castle_rook_moved() const;
	void read_castle_block() const;
	void read_castle() const;
};