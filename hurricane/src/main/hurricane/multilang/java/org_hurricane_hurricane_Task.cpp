/**
 * licensed to the apache software foundation (asf) under one
 * or more contributor license agreements.  see the notice file
 * distributed with this work for additional information
 * regarding copyright ownership.  the asf licenses this file
 * to you under the apache license, version 2.0 (the
 * "license"); you may not use this file except in compliance
 * with the license.  you may obtain a copy of the license at
 *
 * http://www.apache.org/licenses/license-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "as is" basis,
 * without warranties or conditions of any kind, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 */

#include "hurricane/multilang/java/org_hurricane_hurricane_Task.h"

JNIEXPORT void JNICALL Java_org_hurricane_hurricane_Task_emit
  (JNIEnv * env, jobject obj, jobject values) {
      jclass clazzTask = env->GetObjectClass(obj);
      jmethodID getCollector = env->GetMethodID(clazzTask, "getCollector", "(I)V");

      jlong collectorHandle = env->CallLongMethod(obj, collectorHandle);
      OutputCollector* collector = reinterpret_cast<OutputCollector*>(collectorHandle);

      collector->Emit(values);
}
