//
//  maths.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef maths_h
#define maths_h

/// The default scalar type to use throughout the application
///
/// The type is defined as a macro to conserve the possibility of
/// easily switching the entire app to another scalar type.
#define SCALAR double

#define GLM_SWIZZLE_XYZW
#include <glm/glm.hpp>
#include "../Messages/messages.hpp"

// MARK: - Definitions

// Define common types
using vec2 = glm::vec<2, SCALAR, glm::qualifier::defaultp>;
using vec3 = glm::vec<3, SCALAR, glm::qualifier::defaultp>;
using vec4 = glm::vec<4, SCALAR, glm::qualifier::defaultp>;

namespace maths {

// MARK: - Conversion

#ifdef MACHINE_ACQUISITOR

#include <nite2/NiTE.h>

/// Converts a nite float3 to a `vec3`
/// @param p3f The float3 to convert
inline vec3 P3FToVec3(const nite::Point3f &p3f) {
	return vec3(p3f.x, p3f.y, p3f.z);
}

/// Converts a nite quaternion to a `vec4`
/// @param nQuat The quaternion to convert
inline vec4 nQuatToVec4(const nite::Quaternion &nQuat) {
	return vec4(nQuat.x, nQuat.y, nQuat.z, nQuat.w);
}

#endif /* MACHINE_ACQUISITOR */

// MARK: - Communication

/// Converts a `vec2` to its equivalent protobuf message
/// @param vec The vec to convert
inline messages::vec2 * asMessage(const vec2 &vec) {
	messages::vec2 * message = new messages::vec2();
	message->set_x(vec.x);
	message->set_y(vec.y);

	return message;
}

/// Converts a `vec23` to its equivalent protobuf message
/// @param vec The vec to convert
inline messages::vec3 * asMessage(const vec3 &vec) {
	messages::vec3 * message = new messages::vec3();
	message->set_x(vec.x);
	message->set_y(vec.y);
	message->set_z(vec.z);

	return message;
}

/// Converts a `vec4` to its equivalent protobuf message
/// @param vec The vec to convert
inline messages::vec4 * asMessage(const vec4 &vec) {
	messages::vec4 * message = new messages::vec4();
	message->set_x(vec.x);
	message->set_y(vec.y);
	message->set_z(vec.z);
	message->set_w(vec.w);

	return message;
}

/// Gives the vec2 represented by the given message
/// @param message The message to unpack
inline vec2 fromMessage(const messages::vec2 &message) {
	vec2 vec;
	vec.x = message.x();
	vec.y = message.y();

	return vec;
}

/// Gives the vec3 represented by the given message
/// @param message The message to unpack
inline vec3 fromMessage(const messages::vec3 &message) {
	vec3 vec;
	vec.x = message.x();
	vec.y = message.y();
	vec.z = message.z();

	return vec;
}

/// Gives the vec4 represented by the given message
/// @param message The message to unpack
inline vec4 fromMessage(const messages::vec4 &message) {
	vec4 vec;
	vec.x = message.x();
	vec.y = message.y();
	vec.z = message.z();
	vec.w = message.w();

	return vec;
}

}

#endif /* maths_h */
