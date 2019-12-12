/*
 * Project: curve
 * Created Date: 2019-09-25
 * Author: charisu
 * Copyright (c) 2018 netease
 */

#ifndef SRC_TOOLS_NAMESPACE_TOOL_H_
#define SRC_TOOLS_NAMESPACE_TOOL_H_

#include <gflags/gflags.h>
#include <time.h>

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <utility>

#include "proto/nameserver2.pb.h"
#include "proto/topology.pb.h"
#include "src/common/timeutility.h"
#include "src/common/string_util.h"
#include "src/mds/common/mds_define.h"
#include "src/tools/namespace_tool_core.h"

using curve::mds::FileInfo;
using curve::mds::PageFileSegment;
using curve::mds::StatusCode;

namespace curve {
namespace tool {

class NameSpaceTool {
 public:
    explicit NameSpaceTool(std::shared_ptr<NameSpaceToolCore> core) :
                              core_(core) {}
    virtual ~NameSpaceTool() = default;

    /**
     *  @brief 打印用法
     *  @param cmd：查询的命令
     *  @return 无
     */
    void PrintHelp(const std::string &cmd);

    /**
     *  @brief 执行命令
     *  @param cmd：执行的命令
     *  @param filename: 要操作的文件名
     *  @return 成功返回0，失败返回-1
     */
    int RunCommand(const std::string &cmd);

 private:
    // 打印fileInfo和文件占用的实际空间
    int PrintFileInfoAndActualSize(std::string fileName);

    // 打印目录中的文件信息
    int PrintListDir(std::string dirName);

    // 打印出文件的segment信息
    int PrintSegmentInfo(const std::string &fileName);

    // 打印fileInfo，把时间转化为易读的格式输出
    void PrintFileInfo(const FileInfo& fileInfo);

    // 打印PageFileSegment，把同一个chunk的信息打在同一行
    void PrintSegment(const PageFileSegment& segment);

    // 打印chunk的位置信息
    int PrintChunkLocation(const std::string& fileName,
                                     uint64_t offset);

    // 向mds发送RPC的client
    std::shared_ptr<NameSpaceToolCore> core_;
};
}  // namespace tool
}  // namespace curve

#endif  // SRC_TOOLS_NAMESPACE_TOOL_H_