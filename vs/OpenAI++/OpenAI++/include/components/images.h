#pragma once

/*
	images.h : Images component class for OpenAI.
		This class contains all the methods for the Images component
		of the OpenAI API. This class provides access to 'Images' 
		endpoints on the OpenAI API and should be accessed via the
		liboai.h header file through an instantiated liboai::OpenAI
		object after setting necessary authentication information
		through the liboai::Authorization::Authorizer() singleton
		object.
*/

#include "../core/authorization.h"
#include "../core/response.h"

namespace liboai {
	class Images final : private Network {
		public:
			Images() = default;
			~Images() = default;
			Images(const Images&) = delete;
			Images(Images&&) = delete;
			
			Images& operator=(const Images&) = delete;
			Images& operator=(Images&&) = delete;
			
			/*
				@brief Images component method to create an image from
				provided text.
				
				@param *prompt         The text to create an image from.
				@param n               The number of images to create.
				@param size            The size of the image to create.
				@param response_format The format of the response.
				@param user            A unique identifier representing an end-user.

				@return A liboai::Response object containing the image(s)
					data in JSON format.
			*/
			LIBOAI_EXPORT Response create(
				const std::string& prompt,
				const std::optional<uint8_t>& n = std::nullopt,
				const std::optional<std::string>& size = std::nullopt,
				const std::optional<std::string>& response_format = std::nullopt,
				const std::optional<std::string>& user = std::nullopt
			) const &;
			
				/*
				@brief Images component method to produce an edited
				image from a provided base image and mask image
				according to given text.

				@param *image          The image to edit (path).
				@param *prompt         The text description of the desired image.
				@param mask            The mask to edit the image with (path).
				@param n		       The number of images to create.
				@param size            The size of the image to create.
				@param response_format The format of the response.
				@param user            A unique identifier representing an end-user.
			*/		
			LIBOAI_EXPORT Response create_edit(
				const std::filesystem::path& image,
				const std::string& prompt,
				const std::optional<std::filesystem::path>& mask = std::nullopt,
				const std::optional<uint8_t>& n = std::nullopt,
				const std::optional<std::string>& size = std::nullopt,
				const std::optional<std::string>& response_format = std::nullopt,
				const std::optional<std::string>& user = std::nullopt
			) const &;

			/*
				@brief Images component method to produce a variation
					of a supplied image.
				
				@param *image          The image to produce a variation of (path).
				@param n               The number of images to create.
				@param size            The size of the image to create.
				@param response_format The format of the response.
				@param user            A unique identifier representing an end-user.
			*/
			LIBOAI_EXPORT Response create_variation(
				const std::filesystem::path& image,
				const std::optional<uint8_t>& n = std::nullopt,
				const std::optional<std::string>& size = std::nullopt,
				const std::optional<std::string>& response_format = std::nullopt,
				const std::optional<std::string>& user = std::nullopt
			) const &;

		private:
			Authorization& auth_ = Authorization::Authorizer();
	};
}