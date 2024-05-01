#pragma once

#ifndef MAZE_SIZE_H
#define MAZE_SIZE_H

namespace mg {
	/// <summary>
	/// ������ ���������
	/// <para> uint width - ������ </para>
	/// <para> height - ������ </para>
	/// <para> �� ��������� w25 h25 </para>
	/// </summary>
	struct MazeSize {
		unsigned int width;
		unsigned int height;

		MazeSize() : width(25), height(25) { }
		MazeSize(unsigned int _width, unsigned int _height) : width(_width), height(_height) { }

		const bool operator==(const MazeSize& size) const {
			return this->width == size.width && this->height == size.height;
		}
	};
}

#endif // MAZE_SIZE_H