#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lazel {
    class LAZEL_API Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        
    };

}

#define LZ_CORE_TRACE(...) ::Lazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LZ_CORE_DEBUG(...) ::Lazel::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define LZ_CORE_INFO(...)  ::Lazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LZ_CORE_WARN(...)  ::Lazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LZ_CORE_ERROR(...) ::Lazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LZ_CORE_FATAL(...) ::Lazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define LZ_TRACE(...) ::Lazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LZ_DEBUG(...) ::Lazel::Log::GetClientLogger()->debug(__VA_ARGS__)
#define LZ_INFO(...)  ::Lazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define LZ_WARN(...)  ::Lazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LZ_ERROR(...) ::Lazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define LZ_FATAL(...) ::Lazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
