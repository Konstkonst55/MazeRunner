#pragma once

#ifndef MAZE_SIZE_H
#define MAZE_SIZE_H

namespace mg::data {
	/// <summary>
	/// Размер лабиринта
	/// <para> uint width - ширина </para>
	/// <para> uint height - высота </para>
	/// <para> По умолчанию w25 h25 </para>
	/// </summary>
	struct MazeSize {
		size_t width;
		size_t height;

		MazeSize(size_t width = 25u, size_t height = 25u);
		~MazeSize() = default;

		const bool operator==(const MazeSize& size) const;
	};
}

#endif // MAZE_SIZE_H