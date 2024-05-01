#pragma once

#ifndef WALL_STATE_H
#define WALL_STATE_H

namespace mg {
	/// <summary>
	/// ������������ ���� ��������� �����
	/// <para>
	/// Open = 1 - �������
	/// </para>
	/// <para>
	/// Close = 0 - �������
	/// </para>
	/// </summary>
	enum WallState {
		Open = 1,
		Close = 0
	};
}

#endif // WALL_STATE_H