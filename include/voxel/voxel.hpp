#pragma once
#include <voxel/updater.hpp>
#include <voxel/renderer.hpp>

#include <memory>

namespace VOXEL_NAMESPACE
{
	// TODO: remove isPassable

	struct Voxel
	{
		id_t id;
		md_t md;
		bool isPassable;
		std::shared_ptr<Updater> updater;
		std::shared_ptr<Renderer> renderer;

		Voxel(const id_t _id,
			const md_t _md,
			const bool _isPassable,
			const std::shared_ptr<Updater>& _updater,
			const std::shared_ptr<Renderer>& _renderer) :
			id(_id),
			md(_md),
			isPassable(_isPassable),
			updater(_updater),
			renderer(_renderer)
		{}
		virtual ~Voxel()
		{}

		inline static const Voxel createNull(
			const id_t id = nullVoxelID,
			const md_t md = nullVoxelMD,
			const bool isPassable = true,
			const std::shared_ptr<Updater>& const updater = nullptr,
			const std::shared_ptr<Renderer>& const renderer = nullptr) noexcept
		{
			return Voxel(id, md, isPassable, updater, renderer);
		}
		inline static const Voxel createUnknown(
			const id_t id = unknownVoxelID,
			const md_t md = nullVoxelMD,
			const bool isPassable = false,
			const std::shared_ptr<Updater>& const updater = nullptr,
			const std::shared_ptr<Renderer>& const renderer = nullptr) noexcept
		{
			return Voxel(id, md, isPassable, updater, renderer);
		}
	};
}
