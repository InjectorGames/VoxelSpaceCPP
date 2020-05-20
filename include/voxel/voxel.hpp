#pragma once
#include <voxel/defines.hpp>
#include <voxel/updater.hpp>
#include <voxel/renderer.hpp>

#include <memory>

namespace voxel
{
	// TODO: remove isPassable

	struct Voxel
	{
		VOXEL_ID_T id;
		VOXEL_MD_T md;
		bool isPassable;
		std::shared_ptr<Updater> updater;
		std::shared_ptr<Renderer> renderer;

		Voxel(const VOXEL_ID_T _id,
			const VOXEL_MD_T _md,
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
			const VOXEL_ID_T id = VOXEL_ID_NULL,
			const VOXEL_MD_T md = VOXEL_MD_NULL,
			const bool isPassable = true,
			const std::shared_ptr<Updater>& const updater = nullptr,
			const std::shared_ptr<Renderer>& const renderer = nullptr) noexcept
		{
			return Voxel(id, md, isPassable, updater, renderer);
		}
		inline static const Voxel createUnknown(
			const VOXEL_ID_T id = VOXEL_ID_UNKNOWN,
			const VOXEL_MD_T md = VOXEL_MD_NULL,
			const bool isPassable = false,
			const std::shared_ptr<Updater>& const updater = nullptr,
			const std::shared_ptr<Renderer>& const renderer = nullptr) noexcept
		{
			return Voxel(id, md, isPassable, updater, renderer);
		}
	};
}
